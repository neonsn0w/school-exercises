import java.util.Scanner;

public class Menu {
    static Scanner sc = new Scanner(System.in);

    // Menu principale
    public static int menu() {
        String scelta_stringa = "";
        int scelta = 0;

        System.out.println("\n1. Inserisci nuovo telefono");
        System.out.println("2. Visualizza la lista dei telefoni");
        System.out.println("3. Rimuovi un telefono");
        System.out.println("4. Modifica un telefono");
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

    // Menu utilizzato per la modifica degli attributi di un telefono
    public static int modifiermenu(Telefono telefoni[], int index) {
        String scelta_stringa = "";
        int scelta = 0;
        boolean check = true;

        do {
            System.out.println("\n1. Modifica la marca (" + telefoni[index].getMarca() + ")");
            System.out.println("2. Modifica il modello (" + telefoni[index].getModello() + ")");
            System.out.println("3. Modifica il processore (" + telefoni[index].getProcessore() + ")");
            System.out.println("4. Modifica la memoria (" + telefoni[index].getMemoria() + " GB)");
            System.out.println("5. Modifica l'anno di uscita (" + telefoni[index].getAnno() + ")");
            System.out.println("6. Modifica il prezzo (" + telefoni[index].getPrezzo() + ")");
            System.out.println("7. Modifica la versione dell'OS (" + telefoni[index].getVersione() + ")");
            System.out.println("0. Esci\n");
            System.out.print("Inserire la scelta: ");
            scelta_stringa = sc.nextLine();
            try {
                scelta = Integer.parseInt(scelta_stringa);
            } catch (NumberFormatException e) {
                System.out.println("SELEZIONE ERRATA!");
                check = false;
                Telefonia.pause();
            }
        } while(!check);

        return scelta;
    }
}
