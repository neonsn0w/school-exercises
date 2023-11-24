package Scuole;

public class Tecnico extends Scuola {
    private final int EUROCLASSE = 3500;
    private final int EUROLAB = 6000;
    private final int EUROSEDE = 0;
    public Tecnico(String codiceAlfanumerico, String denominazione, String indirizzo, String città, int nStudenti, int nClassi, int nSediAggiuntive, int nLaboratori) {
        super(codiceAlfanumerico, denominazione, indirizzo, città, nStudenti, nClassi, nSediAggiuntive, nLaboratori);
    }
}
