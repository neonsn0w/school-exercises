import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void pause() {
        System.out.print("Premi Enter per continuare...");
        sc.nextLine();
    }

    public static int menu() {
        String scelta_stringa = "";
        int scelta = 0;

        System.out.println("\n1. Inserisci nuovo CD");
        System.out.println("2. Visualizza la lista dei CD");
        System.out.println("3. Rimuovi un CD");
        System.out.println("0. Esci\n");
        System.out.print("Inserire la scelta: ");
        scelta_stringa = sc.nextLine();
        try {
            scelta = Integer.parseInt(scelta_stringa);
        } catch (NumberFormatException e) {
            System.out.println("SELEZIONE ERRATA!");
            scelta = -1;
        }

        return scelta;
    }

    public static int mintosec(int sec) {
        int min = 0;
        while(sec>=60) {
            sec-=60;
            min++;
        }
        return min;
    }

    public static String returnformattedtime(int sec) {
        int min=0, hr=0;
        while(sec>=60) {
            sec-=60;
            min++;
        }
        while(min>=60) {
            min -= 60;
            hr++;
        }
        if(hr==0) {
            return min + ":" + sec;
        } else {
            return hr + ":" + min + ":" + sec;
        }
    }

    public static void inserisciValoriDiTest(CD[] cds) {
        cds[CD.getNCD()] = new CD("Supercell feat. Hatsune Miku", "ryo (supercell)", 8, 393939);
        cds[CD.getNCD()] = new CD("All I want for Christmas is You", "Mariah Carey", 4, 1547);
        cds[CD.getNCD()] = new CD("..squerez?", "Lunapop", 12, 7953);
        cds[CD.getNCD()] = new CD("DOOM Eternal Official Soundtrack", "Mick Gordon", 45, 65934);
        System.out.println("Valori inseriti!");
        pause();
    }

    public static void aggiungiCD(CD[] cds) {
        String titolo, autore, brani_string, minuti_string, secondi_string;
        int brani=0, minuti=0, secondi=0;
        boolean check = true; // variabile utilizzata per il controllo dell'input

        System.out.print("\nInserisci il titolo: ");
        titolo = sc.nextLine();
        System.out.print("\nInserisci l'autore: ");
        autore = sc.nextLine();

        do {
            check = true;
            System.out.print("\nInserisci il numero di brani: ");
            brani_string = sc.nextLine();
            try {
                brani = Integer.parseInt(brani_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        do {
            check = true;
            System.out.print("\nInserisci i minuti: ");
            minuti_string = sc.nextLine();
            try {
                minuti = Integer.parseInt(minuti_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        do {
            check = true;
            System.out.print("\nInserisci i secondi: ");
            secondi_string = sc.nextLine();
            try {
                secondi = Integer.parseInt(secondi_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        cds[CD.getNCD()] = new CD(titolo, autore, brani, (minuti*60)+secondi);
    }

    public static void visualizzaUnCD(CD cds[], int index) {
        System.out.println("CD NUMERO " + (index+1));
        System.out.println("Titolo: " + cds[index].getTitolo());
        System.out.println("Autore: " + cds[index].getAutore());
        System.out.println("Numero di Brani: " + cds[index].getBrani());
        // System.out.println("Durata: " + mintosec(cds[index].getDurata()) + ":" + (cds[index].getDurata()-(mintosec(cds[index].getDurata())*60)));
        System.out.println("Durata: " + returnformattedtime(cds[index].getDurata()));
        System.out.println();
    }

    public static void visualizzaListaCD(CD[] cds) {
        System.out.println("Nel negozio ci sono " + CD.getNCD() + " cds\n");
        if (CD.getNCD() != 0) {
            for (int i = 0; i < CD.getNCD(); i++) {
                visualizzaUnCD(cds, i);
            }
        } else {
            System.out.println("Non ci sono CD da visualizzare!");
        }
        pause();
    }

    public static void rimuoviCD(CD[] cds, int index) {
        for (int i=index; i<CD.getNCD()-1; i++) {
            cds[i] = cds[i+1];
        }

        CD.decrementaNCD();
    }

    public static void main(String[] args) {
        int scelta;
        final int DIM = 30;
        CD[] cds = new CD[DIM];
        boolean check = true;
        String str_index;

        do {
            scelta = menu();

            switch (scelta) {

                case 99:
                    inserisciValoriDiTest(cds);
                    break;

                case 1:
                    aggiungiCD(cds);
                    break;

                case 2:
                    visualizzaListaCD(cds);
                    break;

                case 3:
                    int rm_index = 0;
                    System.out.println();
                    for(int i=0; i<CD.getNCD(); i++) {
                        System.out.println((i+1) + ". " + cds[i].getAutore() + " - " + cds[i].getTitolo());
                    }
                    do {
                        check = true;
                        System.out.print("Inserisci l'indice del CD da rimuovere: ");
                        str_index = sc.nextLine();
                        try {
                            rm_index = Integer.parseInt(str_index);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    if (rm_index<=CD.getNCD() && rm_index>0) {
                        rimuoviCD(cds, rm_index-1);
                        System.out.println("CD rimosso!");
                    } else {
                        System.out.println("INDICE NON VALIDO");
                    }
                    pause();
                    break;
            }
        } while(scelta!=0);
    }
}
