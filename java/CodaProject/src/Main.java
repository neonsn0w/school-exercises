import java.util.Scanner;

/**
 * Classe main con i metodi principali del programma
 *
 * @author neonsn0w
 */

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static int valoriTest(Coda coda, int count, int c) {
        for(int i=0; i<count; i++) {
            coda.aggiungiPersona(new Persona("nome" + c, "cognome", "cf", 2));
            c++;
        }
        return c;
    }


    public static void main(String[] args) {
        int scelta;
        Coda coda = new Coda();
        Persona bin;
        int usefulCounter = 0;
        int times = 0;

        do {

            scelta = Menu.menu();

            switch (scelta) {

                case 99: // Case utile al test del codice
                    System.out.println("Quanti?");
                    times = sc.nextInt();
                    usefulCounter = valoriTest(coda, times, usefulCounter);
                    break;

                case 1:

                    break;

                case 2:
                    coda.visualizzaCoda();
                    break;

                case 3:
                    bin = coda.estraiPersona();
                    break;

            }
        } while (scelta != 0);
    }
}
