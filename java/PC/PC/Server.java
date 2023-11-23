package PC;

public class Server extends PCFisso {
    private int nProcessori;
    private boolean raid;

    public Server(String processore, String marca, String modello, String os, int ram, int memMassa, String tipoCase, int nProcessori, boolean raid) {
        super(processore, marca, modello, os, ram, memMassa, tipoCase);
        this.nProcessori = nProcessori;
        this.raid = raid;
    }
}
