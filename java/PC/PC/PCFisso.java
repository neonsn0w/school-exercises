package PC;

public class PCFisso extends PC {
    private String tipoCase;

    public PCFisso(String processore, String marca, String modello, String os, int ram, int memMassa, String tipoCase) {
        super(processore, marca, modello, os, ram, memMassa);
        this.tipoCase = tipoCase;
    }

    public String getTipoCase() {
        return tipoCase;
    }
}
