package Scuole;

import java.util.Objects;

public class Scuola {
    private int EUROCLASSE = 0;
    private int EUROLAB = 0;
    private int EUROSEDE = 0;

    private String codiceAlfanumerico, denominazione, indirizzo, città;
    private int nStudenti, nClassi, nSediAggiuntive, nLaboratori;

    public Scuola(String codiceAlfanumerico, String denominazione, String indirizzo, String città, int nStudenti, int nClassi, int nSediAggiuntive, int nLaboratori) {
        this.codiceAlfanumerico = codiceAlfanumerico;
        this.denominazione = denominazione;
        this.indirizzo = indirizzo;
        this.città = città;
        this.nStudenti = nStudenti;
        this.nClassi = nClassi;
        this.nSediAggiuntive = nSediAggiuntive;
        this.nLaboratori = nLaboratori;
    }

    public String getCodiceAlfanumerico() {
        return codiceAlfanumerico;
    }

    public String getDenominazione() {
        return denominazione;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public String getCittà() {
        return città;
    }

    public int getnStudenti() {
        return nStudenti;
    }

    public int getnClassi() {
        return nClassi;
    }

    public int getnSediAggiuntive() {
        return nSediAggiuntive;
    }

    public int getnLaboratori() {
        return nLaboratori;
    }

    @Override
    public String toString() {
        return "\n" +
                "codiceAlfanumerico= " + codiceAlfanumerico + '\n' +
                "denominazione= " + denominazione + '\n' +
                "indirizzo= " + indirizzo + '\n' +
                "città= " + città + '\n' +
                "nStudenti= " + nStudenti + '\n' +
                "nClassi= " + nClassi + '\n' +
                "nSediAggiuntive= " + nSediAggiuntive + '\n' +
                "nLaboratori= " + nLaboratori + '\n';
    }
}
