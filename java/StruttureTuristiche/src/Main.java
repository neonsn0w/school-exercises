import java.time.LocalDate;

/**
 * Il signor Briatore ha molte strutture turistiche sparse nel mondo, vuole memorizzare le
 * caratteristiche di ogni struttura e di tutti gli impiegati.
 */

public class Main {
    public static void main(String[] args) {
        StrutturaTuristica theone = new StrutturaTuristica("The One", "Hotel", "Caorle", 5);

        theone.addImpiegato(new Direttore("Dario", "Moccia", "Bari", 999999, LocalDate.ofEpochDay(0), 420));

        for(int i = 0; i < 9; i++) {
            theone.addImpiegato(new Impiegato("Marco", "Merrino", "Cina", 1200, LocalDate.ofEpochDay(i*420+10)));
        }
        theone.addImpiegato(new Impiegato("Marco", "Merrino", "Cina", 1200, LocalDate.of(2002, 2,19)));

        theone.aumentaSpeseDirettore(80);

        theone.ElencoDipendenti();

        System.out.println(theone.ElencoDipendenti());
    }
}