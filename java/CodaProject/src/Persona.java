/**
 * Classe utile a creare oggetti di tipo Persona in progetti che lo richiedono
 *
 * @author neonsn0w
 */

public class Persona {
    private String nome, cognome, codiceFiscale;
    private int eta;

    public Persona(String nome, String cognome, String codiceFiscale, int eta) {
        this.nome = nome;
        this.cognome = cognome;
        this.codiceFiscale = codiceFiscale;
        this.eta = eta;
    }

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getCodiceFiscale() {
        return codiceFiscale;
    }

    public int getEta() {
        return eta;
    }

    @Override
    public String toString() {
        return "Persona{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                ", codiceFiscale='" + codiceFiscale + '\'' +
                ", eta=" + eta +
                '}';
    }
}
