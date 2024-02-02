import java.util.Scanner;

/**
 * Classe contenente uno o piu menu che possono essere visualizzati
 *
 * @author neonsn0w
 */

public class Menu {
    static Scanner sc = new Scanner(System.in);

    public static int menu() {
        String scelta_stringa = "";
        int scelta = 0;

        System.out.println("\n1. Inserisci una Persona");
        System.out.println("2. Visualizza la coda");
        System.out.println("3. Estrai una Persona");
        System.out.println("0. Esci\n");
        System.out.print("Inserire la scelta: ");
        scelta_stringa = sc.nextLine();
        try {
            scelta = Integer.parseInt(scelta_stringa);
        } catch (NumberFormatException e) {
            scelta = -1;
        }

        return scelta;
    }
}
