package PC;

public class PCPortatile extends PC {
    private double peso, altezza, larghezza, profondita, diagonale;
    private boolean wireless;

    public PCPortatile(String processore, String marca, String modello, String os, int ram, int memMassa, double peso, double altezza, double larghezza, double profondita, double diagonale, boolean wireless) {
        super(processore, marca, modello, os, ram, memMassa);
        this.peso = peso;
        this.altezza = altezza;
        this.larghezza = larghezza;
        this.profondita = profondita;
        this.diagonale = diagonale;
        this.wireless = wireless;
    }

    public double getPeso() {
        return peso;
    }

    public double getAltezza() {
        return altezza;
    }

    public double getLarghezza() {
        return larghezza;
    }

    public double getProfondita() {
        return profondita;
    }

    public double getDiagonale() {
        return diagonale;
    }

    public boolean isWireless() {
        return wireless;
    }
}
