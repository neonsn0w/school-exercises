import java.util.Scanner;

/**
 * Classe contenente metodi utili alla programmazione
 *
 * @author neonsn0w
 */

public class Tools {
    static Scanner sc = new Scanner(System.in);

    /**
     * Funzione utile ad acquisire un intero con gestione degli errori
     * @return Intero acquisito in input
     */
    public static int getInt(String msg) {
        boolean check;
        String str;
        int integer;

        do {
            check = true;
            System.out.print(msg);
            str = sc.nextLine();
            try {
                integer = Integer.parseInt(str);
                return integer;
            } catch (NumberFormatException e) {
                check = false;
            }
        } while (!check);

        return -1;
    }
}
