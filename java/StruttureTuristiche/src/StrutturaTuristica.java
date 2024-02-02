import java.util.ArrayList;
import java.util.Comparator;

/**
 * Struttura turistica
 * @author neonsn0w
 */
public class StrutturaTuristica {
    private String denominazione, tipologia, sede;
    private ArrayList<Impiegato> impiegati;
    private int nImpiegati = 0;

    public StrutturaTuristica(String denominazione, String tipologia, String sede, int nImpiegati) {
        this.denominazione = denominazione;
        this.tipologia = tipologia;
        this.sede = sede;
        this.impiegati = new ArrayList<>();
    }

    public String getDenominazione() {
        return denominazione;
    }

    public void setDenominazione(String denominazione) {
        this.denominazione = denominazione;
    }

    public String getTipologia() {
        return tipologia;
    }

    public void setTipologia(String tipologia) {
        this.tipologia = tipologia;
    }

    public String getSede() {
        return sede;
    }

    public void addImpiegato(Impiegato o) {
        impiegati.add(o);
        nImpiegati++;
    }

    public void setSede(String sede) {
        this.sede = sede;
    }

    /**
     * Restituisce il numero di impiegati italiani
     */
    public int getQuantiItaliani() {
        int nit = 0;
        for (int i=0; i<nImpiegati; i++) {
            if (impiegati.get(i).getNazionalita().compareToIgnoreCase("italia") == 0) {
                nit++;
            }
        }
        return nit;
    }

    /**
     * Determina l'ammontare complessivo mensile degli stipendi di tutti gli impiegati
     */
    public double totStipendi() {
        double tot = 0;
        for(int i=0; i<nImpiegati; i++) {
            tot += impiegati.get(i).getStipendioMensile();
        }
        return tot;
    }

    /**
     * Aumenta le spese del direttore
     * @param val di quanto aumentare le spese
     */
    public void aumentaSpeseDirettore(int val) {
        for(int i=0; i<nImpiegati; i++) {
            if (impiegati.get(i) instanceof Direttore) {
                ((Direttore) impiegati.get(i)).setSpese(((Direttore) impiegati.get(i)).getSpese() + val); // Questa riga è orribile...
                return;
            }
        }
    }

    /**
     * Restituisce l'elenco dei dipendenti ordinato per anzianità
     */
    public String ElencoDipendenti() {
        StringBuilder sb = new StringBuilder();

        impiegati.sort(Comparator.naturalOrder());

        for(int i = 0; i < nImpiegati; i++) {
            sb.append(impiegati.get(i));
            sb.append("\n");
        }

        return sb.toString();
    }

    @Override
    public String toString() {
        return "StrutturaTuristica{" +
                "denominazione='" + denominazione + '\'' +
                ", tipologia='" + tipologia + '\'' +
                ", sede='" + sede + '\'' +
                ", impiegati=" + impiegati +
                '}';
    }
}
