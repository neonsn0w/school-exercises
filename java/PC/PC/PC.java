package PC;

public class PC {
    private String processore, marca, modello, os;
    private int ram, memMassa;

    public PC(String processore, String marca, String modello, String os, int ram, int memMassa) {
        this.processore = processore;
        this.marca = marca;
        this.modello = modello;
        this.os = os;
        this.ram = ram;
        this.memMassa = memMassa;
    }

    public String getProcessore() {
        return processore;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public String getOs() {
        return os;
    }

    public int getRam() {
        return ram;
    }

    public int getMemMassa() {
        return memMassa;
    }
}
