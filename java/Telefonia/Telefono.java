public class Telefono {
    private String marca, modello, processore;
    private int memoria, anno;
    private double prezzo, versione;
    private static int nTelefoni = 0;

    public Telefono(String marca, String modello, String processore, int memoria, int anno, double prezzo, double versione) {
        this.marca = marca;
        this.modello = modello;
        this.processore = processore;
        this.memoria = memoria;
        this.anno = anno;
        this.prezzo = prezzo;
        this.versione = versione;
        nTelefoni++;
    }

    public String getMarca() {
        return marca;
    }

    public String getModello() {
        return modello;
    }

    public String getProcessore() {
        return processore;
    }

    public int getMemoria() {
        return memoria;
    }

    public int getAnno() {
        return anno;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public double getVersione() {
        return versione;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModello(String modello) {
        this.modello = modello;
    }

    public void setProcessore(String processore) {
        this.processore = processore;
    }

    public void setMemoria(int memoria) {
        this.memoria = memoria;
    }

    public void setAnno(int anno) {
        this.anno = anno;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }

    public void setVersione(double versione) {
        this.versione = versione;
    }

    public static int getNTelefoni() {
        return nTelefoni;
    }

    public static void decrementaNTelefoni() {
        nTelefoni--;
    }
}
