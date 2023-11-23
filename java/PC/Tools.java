import java.util.Scanner;

public class Tools {
    static Scanner sc = new Scanner(System.in);

    // Chiede all'utente di premere Invio per continuare con l'esecuzione
    public static void pause() {
        System.out.print("Premi Enter per continuare...");
        sc.nextLine();
    }
}
