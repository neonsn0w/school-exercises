import java.util.Scanner;

public class Tools {
    static Scanner sc = new Scanner(System.in);

    // Chiede all'utente di premere Invio per continuare con l'esecuzione
    public static void pause() {
        System.out.print("Premi Enter per continuare...");
        sc.nextLine();
    }

    // Converte il tempo in secondi in una stringa formattata
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
}
