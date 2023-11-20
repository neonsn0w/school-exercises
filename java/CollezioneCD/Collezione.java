import java.util.Scanner;

public class Collezione {
    static Scanner sc = new Scanner(System.in);

    private CD[] cds;
    private int nCD = 0;

    // Costruttore
    public Collezione(int n) {
        cds = new CD[n];
    }

    // Metodo che ritorna l'oggetto CD della collezione nella posizione indicata in input
    public CD getCD(int index) {
        return cds[index];
    }

    // Questo metodo viene usato solo all'interno della classe
    // Metodo sostituisce il CD nella posizione indicata
    private void setCD(int index, CD cd) {
        cds[index] = cd;
    }

    // Metodo che restituisce il numero di CD nella collezione
    public int getNCD() {
        return nCD;
    }

    // Metodo utilizzato in fase di test del programma per inserire dei valori di test
    public void inserisciValoriDiTest() {
        setCD(nCD, new CD("Supercell feat. Hatsune Miku", "ryo (supercell)", 8, 393939));
        nCD++;
        setCD(nCD, new CD("All I want for Christmas is You", "Mariah Carey", 4, 1547));
        nCD++;
        setCD(nCD, new CD("..squerez?", "Lunapop", 12, 7953));
        nCD++;
        setCD(nCD, new CD("DOOM Eternal Official Soundtrack", "Mick Gordon", 45, 65934));
        nCD++;
        System.out.println("Valori inseriti!");
        Tools.pause();
    }

    // Metodo che aggiunge un CD alla collezione
    public void aggiungiCD() {
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

        setCD(nCD, new CD(titolo, autore, brani, (minuti*60)+secondi));

        //cds[CD.getNCD()] = new CD(titolo, autore, brani, (minuti*60)+secondi);
        nCD++;
    }

    // Metodo che visualizza le informaizoni del CD nella posizione specificata
    public void visualizzaUnCD(int index) {
        System.out.println("CD NUMERO " + (index+1));
        System.out.println("Titolo: " + cds[index].getTitolo());
        System.out.println("Autore: " + cds[index].getAutore());
        System.out.println("Numero di Brani: " + cds[index].getBrani());
        // System.out.println("Durata: " + mintosec(cds[index].getDurata()) + ":" + (cds[index].getDurata()-(mintosec(cds[index].getDurata())*60)));
        System.out.println("Durata: " + Tools.returnformattedtime(cds[index].getDurata()));
        System.out.println();
    }

    // Metodo che visualizza tutti i CD della collezione
    public void visualizzaListaCD() {
        System.out.println("Nel negozio ci sono " + nCD + " cds\n");
        if (nCD != 0) {
            for (int i = 0; i < nCD; i++) {
                visualizzaUnCD(i);
            }
        } else {
            System.out.println("Non ci sono CD da visualizzare!");
        }
        Tools.pause();
    }

    // Metodo che rimuove un CD dalla collezione
    public void rimuoviCD(int index) {
        for (int i=index; i<nCD-1; i++) {
            cds[i] = cds[i+1];
        }

        nCD--;
    }

    // Metodo che restituisce la posizione del CD con il titolo ricercato
    public int ricercaPerTitolo(String s) {
        for (int i=0; i<nCD-1; i++) {
            if (s.compareToIgnoreCase(cds[i].getTitolo()) == 0) {
                return i;
            }
        }
        return -1;
    }

    // Metodo che modifica uno o più attributi di uno specifico CD
    public void modificaCD(Collezione collezione, int index) {
        int scelta = 0;
        boolean check = true;
        String s;
        int i = 0;
        int ii = 0;

        do {
            scelta = Menu.modifiermenu(collezione, index);

            switch (scelta) {
                case 1:
                    System.out.print("Inserisci il titolo: ");
                    s = sc.nextLine();
                    cds[index].setTitolo(s);
                    break;

                case 2:
                    System.out.print("Inserisci l'autore: ");
                    s = sc.nextLine();
                    cds[index].setAutore(s);
                    break;

                case 3:
                    do {
                        check = true;
                        System.out.print("Inserisci il numero di canzoni: ");
                        s = sc.nextLine();
                        try {
                            i = Integer.parseInt(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    cds[index].setBrani(i);
                    break;

                case 4:
                    do {
                        check = true;
                        System.out.print("Inserisci i minuti: ");
                        s = sc.nextLine();
                        try {
                            i = Integer.parseInt(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    ii = i;
                    do {
                        check = true;
                        System.out.print("Inserisci i secondi: ");
                        s = sc.nextLine();
                        try {
                            i = Integer.parseInt(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    cds[index].setDurata((ii*60)+i);
                    break;

            }
        } while (scelta!=0);
    }
}
