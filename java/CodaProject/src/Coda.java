/**
 * Coda di Persone che si espande automaticamente quando si riempe.
 *
 * @author neonsn0w
 */

public class Coda {
    private final int DIM = 2;
    private Persona[] persone = new Persona[DIM];
    private int fineCoda = 0;
    private int inizioCoda = 0;

    public Coda() {
    }

    /**
     * Aggiunge una persona facendo attenzione ad espandere l'array nel caso sia pieno e ripartire dall'inizio se
     * ci si trova allla fine dell'array
     * @param p Persona da aggiungere
     */
    public void aggiungiPersona(Persona p) {
        boolean warped = false;

        if(isFull()) {
            expandArray();
        }

        if (fineCoda == persone.length) {
            fineCoda = 0;
            warped = true;
        }

        persone[fineCoda] = p;
        if(!warped) {
            fineCoda++;
        }
    }

    /**
     * Estrae una persona dall'inizio della coda
     * @return Persona estratta
     */
    public Persona estraiPersona() {
        if(isEmpty()) {
            return null;
        } else {
            inizioCoda++;
            return persone[inizioCoda-1];
        }
    }

    /**
     * Visualizza una lista delle persone nella coda
     */
    public void visualizzaCoda() {
        if(fineCoda < inizioCoda) {
            for (int i = inizioCoda; i < persone.length; i++) {
                System.out.println(persone[i]);
            }
            for (int i = 0; i < fineCoda; i++) {
                System.out.println(persone[i]);
            }
        } else {
            for(int i=inizioCoda; i<fineCoda; i++) {
                System.out.println(persone[i]);
            }
        }
    }

    /**
     * Controlla se la coda e' vuota verificando se l'inizio e la fine combaciano
     * @return true se la coda e' vuota
     */
    private boolean isEmpty() {
        return inizioCoda == fineCoda;
    }

    /**
     * Controlla se la coda e' piena verificando se la fine della coda e' subito prima dell'inizio
     * oppure se l'inizio e' 0 e la fine e' in ultima posizione
     * @return true se la coda e' vuota
     */
    private boolean isFull() {
        if (fineCoda == inizioCoda-1 || inizioCoda == 0 && fineCoda == persone.length) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Espande l'array raddoppiando la dimensione
     */
    private void expandArray() {
        Persona[] personeTemp = new Persona[persone.length*2];
        if (fineCoda < inizioCoda) {
            for(int i=inizioCoda; i<persone.length; i++) {
                personeTemp[i-inizioCoda] = persone[i];
            }
            for(int i=0; i<fineCoda; i++) {
                personeTemp[persone.length-inizioCoda+i] = persone[i];
            }
        } else {
            for(int i=inizioCoda; i<fineCoda; i++) {
                personeTemp[i-inizioCoda] = persone[i];
            }
        }
        inizioCoda = 0;
        fineCoda = persone.length;
        persone = personeTemp;

    }

}
