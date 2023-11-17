public class CD {
    private String titolo, autore;
    private int brani, durata;
    private static int nCD;

    public CD(String titolo, String autore, int brani, int durata) {
        this.titolo = titolo;
        this.autore = autore;
        this.brani = brani;
        this.durata = durata;
        nCD++;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public int getBrani() {
        return brani;
    }

    public int getDurata() {
        return durata;
    }

    public static int getNCD() {
        return nCD;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public void setAutore(String autore) {
        this.autore = autore;
    }

    public void setBrani(int brani) {
        this.brani = brani;
    }

    public void setDurata(int durata) {
        this.durata = durata;
    }

    @Override
    public String toString() {
        return "CD{" +
                "titolo='" + titolo + '\'' +
                ", autore='" + autore + '\'' +
                ", brani=" + brani +
                ", durata=" + durata +
                '}';
    }

    public static void decrementaNCD() {
        nCD--;
    }
}
