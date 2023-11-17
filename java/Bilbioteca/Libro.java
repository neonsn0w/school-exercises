public class Libro {
    private static int nLibri = 0;
    private String titolo, autore, genere;
    private int pagine;
    private double prezzo;

    public Libro(String titolo, String autore, String genere, int pagine, double prezzo) {
        this.titolo = titolo;
        this.autore = autore;
        this.genere = genere;
        this.pagine = pagine;
        this.prezzo = prezzo;
        nLibri++;
    }

    public static int getNLibri() {
        return nLibri;
    }

    public static void setnLibri(int nLibri) {
        Libro.nLibri = nLibri;
    }

    public String getTitolo() {
        return titolo;
    }

    public String getAutore() {
        return autore;
    }

    public String getGenere() {
        return genere;
    }

    public int getPagine() {
        return pagine;
    }

    public double getPrezzo() {
        return prezzo;
    }

    public void setTitolo(String titolo) {
        this.titolo = titolo;
    }

    public void setAutore(String autore) {
        this.autore = autore;
    }

    public void setGenere(String genere) {
        this.genere = genere;
    }

    public void setPagine(int pagine) {
        this.pagine = pagine;
    }

    public void setPrezzo(double prezzo) {
        this.prezzo = prezzo;
    }
}
