import java.time.LocalDate;

/**
 * Il Direttore è un particolare tipo di impiegato che sostiene anche delle spese
 * @author neonsn0w
 */
public class Direttore extends Impiegato {
    protected double spese;

    public Direttore(String cognome, String nome, String nazionalita, double stipendioBase, LocalDate dataDiAssunzione, double spese) {
        super(cognome, nome, nazionalita, stipendioBase, dataDiAssunzione);
        this.spese = spese;
    }

    public double getSpese() {
        return spese;
    }

    public void setSpese(double spese) {
        this.spese = spese;
    }

    /**
     * Somma dello stipendioBase più 50 Euro per ogni anno di anzianità di servizio (tenendo conto delle spese)
     * @return Stipendio mensile
     */
    public double StipendioMensile() {
        return stipendioBase + 50*(LocalDate.now().getYear() - dataDiAssunzione.getYear()) - spese;
    }

    @Override
    public String toString() {
        return "Direttore{" +
                "spese=" + spese +
                ", cognome='" + cognome + '\'' +
                ", nome='" + nome + '\'' +
                ", nazionalita='" + nazionalita + '\'' +
                ", stipendioBase=" + stipendioBase +
                ", dataDiAssunzione=" + dataDiAssunzione +
                '}';
    }
}
