package PC;

public class Palmare extends PCPortatile {
    private boolean bluetooth;
    private String espansione;

    public Palmare(String processore, String marca, String modello, String os, int ram, int memMassa, double peso, double altezza, double larghezza, double profondita, double diagonale, boolean wireless, boolean bluetooth, String espansione) {
        super(processore, marca, modello, os, ram, memMassa, peso, altezza, larghezza, profondita, diagonale, wireless);
        this.bluetooth = bluetooth;
        this.espansione = espansione;
    }

    public boolean isBluetooth() {
        return bluetooth;
    }

    public String getEspansione() {
        return espansione;
    }
}
