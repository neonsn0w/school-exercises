import java.util.Scanner;

public class Menu {
    static Scanner sc = new Scanner(System.in);

    // Menu principale
    public static int menu() {
        String scelta_stringa = "";
        int scelta = 0;

        System.out.println("\n1. Inserisci nuovo CD");
        System.out.println("2. Visualizza la lista dei CD");
        System.out.println("3. Rimuovi un CD");
        System.out.println("4. Cerca un CD per titolo");
        System.out.println("5. Modifica un CD");
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

    // Menu visualizzato per modificare un CD
    public static int modifiermenu(Collezione collezione, int index) {
        String scelta_stringa = "";
        int scelta = 0;
        boolean check = true;

        do {
            System.out.println("\n1. Modifica il titolo (" + collezione.getCD(index).getTitolo() + ")");
            System.out.println("2. Modifica l'autore (" + collezione.getCD(index).getAutore() + ")");
            System.out.println("3. Modifica il numero di brani (" + collezione.getCD(index).getBrani() + ")");
            System.out.println("4. Modifica la durata (" + Tools.returnformattedtime(collezione.getCD(index).getDurata()) + ")");
            System.out.println("0. Esci\n");
            System.out.print("Inserire la scelta: ");
            scelta_stringa = sc.nextLine();
            try {
                scelta = Integer.parseInt(scelta_stringa);
            } catch (NumberFormatException e) {
                System.out.println("SELEZIONE ERRATA!");
                check = false;
                Tools.pause();
            }
        } while (!check);

        return scelta;
    }
}
