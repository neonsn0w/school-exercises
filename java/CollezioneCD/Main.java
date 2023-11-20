import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int scelta;
        final int DIM = 30;
        CD[] cds = new CD[DIM];
        Collezione collezione = new Collezione(30);
        boolean check = true;
        String str_index;

        do {
            System.out.println("Hai inserito " + collezione.getNCD() + " CD");
            scelta = Menu.menu();

            switch (scelta) {

                case 99: // Case utile al test del codice
                    collezione.inserisciValoriDiTest();
                    break;

                case 1:
                    collezione.aggiungiCD();
                    break;

                case 2:
                    collezione.visualizzaListaCD();
                    break;

                case 3:
                    int rm_index = 0;
                    System.out.println();
                    for(int i=0; i<collezione.getNCD(); i++) {
                        System.out.println((i+1) + ". " + collezione.getCD(i).getAutore() + " - " + collezione.getCD(i).getTitolo());
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
                    if (rm_index<=collezione.getNCD() && rm_index>0) {
                        collezione.rimuoviCD(rm_index-1);
                        System.out.println("CD rimosso!");
                    } else {
                        System.out.println("INDICE NON VALIDO");
                    }
                    Tools.pause();
                    break;

                case 4:
                    System.out.print("\nInserisci il titolo del CD da cercare: ");
                    String search_s = sc.nextLine();
                    if (collezione.ricercaPerTitolo(search_s) >= 0) {
                        System.out.println("Il CD si trova in posizione " + (collezione.ricercaPerTitolo(search_s)+1));
                    } else {
                        System.out.println("CD non trovato!");
                    }

                case 5:
                    int mod_index = 0;
                    System.out.println();
                    for(int i=0; i<collezione.getNCD(); i++) {
                        System.out.println((i+1) + ". " + collezione.getCD(i).getAutore() + " - " + collezione.getCD(i).getTitolo());
                    }
                    do {
                        check = true;
                        System.out.print("Inserisci l'indice del CD da modificare: ");
                        str_index = sc.nextLine();
                        try {
                            mod_index = Integer.parseInt(str_index);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    if (mod_index<=collezione.getNCD() && mod_index>0) {
                        collezione.modificaCD(collezione, mod_index-1);
                        System.out.println("CD modificato!");
                    } else {
                        System.out.println("INDICE NON VALIDO");
                    }
                    Tools.pause();
                    break;

            }
        } while(scelta!=0);
    }
}
