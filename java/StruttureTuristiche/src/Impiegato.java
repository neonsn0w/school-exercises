import java.time.LocalDate;

/**
 * Impiegato di una struttura turistica
 * @author neonsn0w
 */
public class Impiegato implements Comparable<Impiegato>{
    protected String cognome, nome, nazionalita;
    protected double stipendioBase;
    protected LocalDate dataDiAssunzione;

    public Impiegato(String cognome, String nome, String nazionalita, double stipendioBase, LocalDate dataDiAssunzione) {
        this.cognome = cognome;
        this.nome = nome;
        this.nazionalita = nazionalita;
        this.stipendioBase = stipendioBase;
        this.dataDiAssunzione = dataDiAssunzione;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNazionalita() {
        return nazionalita;
    }

    public void setNazionalita(String nazionalita) {
        this.nazionalita = nazionalita;
    }

    public double getStipendioBase() {
        return stipendioBase;
    }

    public void setStipendioBase(double stipendioBase) {
        this.stipendioBase = stipendioBase;
    }

    public LocalDate getDataDiAssunzione() {
        return dataDiAssunzione;
    }

    public void setDataDiAssunzione(LocalDate dataDiAssunzione) {
        this.dataDiAssunzione = dataDiAssunzione;
    }

    @Override
    public String toString() {
        return "Impiegato{" +
                "cognome='" + cognome + '\'' +
                ", nome='" + nome + '\'' +
                ", nazionalita='" + nazionalita + '\'' +
                ", stipendioBase=" + stipendioBase +
                ", dataDiAssunzione=" + dataDiAssunzione +
                '}';
    }

    /**
     * Somma dello stipendioBase più 50 Euro per ogni anno di anzianità di servizio
     * @return Stipendio mensile
     */
    public double getStipendioMensile() {
        return stipendioBase + 50*(LocalDate.now().getYear() - dataDiAssunzione.getYear());
    }

    /**
     * Setermina se l’anzianità di servizio è maggiore o meno di quella di un altro impiegato
     * @param o Secondo impiegato
     */
    public int compareTo(Impiegato o) {
        if (dataDiAssunzione.getYear() == o.getDataDiAssunzione().getYear()) {
            return 0;
        } else if (dataDiAssunzione.getYear() > o.getDataDiAssunzione().getYear()) {
            return 1;
        } else {
            return -1;
        }
    }
}
