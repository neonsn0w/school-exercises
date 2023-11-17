import java.util.Scanner;

public class Biblioteca {
    static Scanner sc = new Scanner(System.in);

    public static int menu() {
        String scelta_stringa = "";
        int scelta = 0;

        System.out.println("\n1. Inserisci nuovo libro");
        System.out.println("2. Visualizza la lista dei libri");
        System.out.println("3. Ricerca libro per titolo");
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

    public static void aggiungiLibro(Libro libri[]) {
        String titolo, autore, genere, pagine_string, prezzo_string;
        int pagine = 0;
        double prezzo = 0;
        boolean check = true;

        System.out.print("\nInserisci il titolo: ");
        titolo = sc.nextLine();
        System.out.print("\nInserisci l'autore: ");
        autore = sc.nextLine();
        System.out.print("\nInserisci il genere: ");
        genere = sc.nextLine();
        do {
            check = true;
            System.out.print("\nInserisci il pagine: ");
            pagine_string = sc.nextLine();
            try {
                pagine = Integer.parseInt(pagine_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);
        do {
            check = true;
            System.out.print("\nInserisci il prezzo: ");
            prezzo_string = sc.nextLine();
            try {
                prezzo = Double.parseDouble(prezzo_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        libri[Libro.getNLibri()] = new Libro(titolo, autore, genere, pagine, prezzo);
    }

    public static void visualizzaLibri(Libro libri[]) {
        if (Libro.getNLibri() != 0) {
            for (int i = 0; i < Libro.getNLibri(); i++) {
                System.out.println("LIBRO NUMERO " + (i+1));
                System.out.println("Titolo: " + libri[i].getTitolo());
                System.out.println("Autore: " + libri[i].getAutore());
                System.out.println("Genere: " + libri[i].getGenere());
                System.out.println("Pagine: " + libri[i].getPagine());
                System.out.println("Prezzo: " + libri[i].getPrezzo());
                System.out.println();
            }
        } else {
            System.out.println("Non ci sono libri da visualizzare!");
        }
    }

    public static int ricercaLibroPerTitolo(String s, Libro[] libri) {
        for (int i=0; i<Libro.getNLibri(); i++) {
            if (s.compareToIgnoreCase(libri[i].getTitolo()) == 0) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int scelta;
        final int DIM = 30;
        Libro[] libri = new Libro[DIM];



        do {
            scelta = menu();

            switch (scelta) {
                case -1:
                    break;

                case 1:
                    aggiungiLibro(libri);
                    break;

                case 2:
                    visualizzaLibri(libri);
                    break;

                case 3:
                    System.out.print("Inserisci il titolo del libro: ");
                    String titolo_da_cercare = sc.nextLine();
                    int risultato = ricercaLibroPerTitolo(titolo_da_cercare, libri);
                    if (risultato >= 0) {
                        System.out.println("LIBRO NUMERO " + (risultato + 1));
                        System.out.println("Titolo: " + libri[risultato].getTitolo());
                        System.out.println("Autore: " + libri[risultato].getAutore());
                        System.out.println("Genere: " + libri[risultato].getGenere());
                        System.out.println("Pagine: " + libri[risultato].getPagine());
                        System.out.println("Prezzo: " + libri[risultato].getPrezzo());
                        System.out.println();
                    } else {
                        System.out.println("Libro non trovato");
                    }
            }
        } while(scelta!=0);
    }
}
