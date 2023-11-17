import java.util.Scanner;

public class Telefonia {
    static Scanner sc = new Scanner(System.in);

    // Funzione che richiede all'utente di premere invio per continuare l'esecuzione
    public static void pause() {
        System.out.print("Premi Enter per continuare...");
        sc.nextLine();
    }

    // Questa funzione viene utilizzata in fase di test per inserire velocemente dei telefoni preimpostati
    public static void inserisciValoriDiTest(Telefono[] telefoni) {
        telefoni[Telefono.getNTelefoni()] = new Telefono("Apple", "iPhone 15 Pro", "A17", 256, 2023, 999.99, 17.1);
        telefoni[Telefono.getNTelefoni()] = new Telefono("Google", "Pixel 7", "Tensor G2", 128, 2022, 499.99, 13.0);
        telefoni[Telefono.getNTelefoni()] = new Telefono("Samsung", "Galaxy S23", "Snapdragon 888", 512, 2022, 799.9, 12.0);
        System.out.println("Valori inseriti!");
        pause();
    }

    // Aggiunge un nuovo telefono all'array
    public static void aggiungiTelefono(Telefono[] telefoni) {
        String marca, modello, processore, memoria_string, anno_string, prezzo_string, versione_string;
        int memoria=0, anno=0;
        double prezzo=0, versione=0;
        boolean check = true; // variabile utilizzata per il controllo dell'input

        System.out.print("\nInserisci la marca: ");
        marca = sc.nextLine();
        System.out.print("\nInserisci il modello: ");
        modello = sc.nextLine();
        System.out.print("\nInserisci il processore: ");
        processore = sc.nextLine();

        // input memoria
        do {
            check = true;
            System.out.print("\nInserisci la memoria in GB: ");
            memoria_string = sc.nextLine();
            try {
                memoria = Integer.parseInt(memoria_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        // input anno
        do {
            check = true;
            System.out.print("\nInserisci l'anno di uscita: ");
            anno_string = sc.nextLine();
            try {
                anno = Integer.parseInt(anno_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        // input prezzo
        do {
            check = true;
            System.out.print("\nInserisci il prezzo: ");
            prezzo_string = sc.nextLine();
            try {
                prezzo = Double.parseDouble(prezzo_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        // input versione
        do {
            check = true;
            System.out.print("\nInserisci la versione del sistema operativo: ");
            versione_string = sc.nextLine();
            try {
                versione = Double.parseDouble(versione_string);
            } catch (NumberFormatException e) {
                System.out.println("ERRORE");
                check = false;
            }
        } while (!check);

        telefoni[Telefono.getNTelefoni()] = new Telefono(marca, modello, processore, memoria, anno, prezzo, versione);
    }

    // Visualizza le specifiche di un telefono a scelta
    public static void visualizzaUnTelefono(Telefono[] telefoni, int index) {
        System.out.println("TELEFONO NUMERO " + (index+1));
        System.out.println("Marca: " + telefoni[index].getMarca());
        System.out.println("Modello: " + telefoni[index].getModello());
        System.out.println("Processore: " + telefoni[index].getProcessore());
        System.out.println("Memoria in GB: " + telefoni[index].getMemoria());
        System.out.println("Anno di uscita: " + telefoni[index].getAnno());
        System.out.println("Prezzo: " + telefoni[index].getPrezzo());
        System.out.println("Versione dell'OS: " + telefoni[index].getVersione());
        System.out.println();
    }

    // Visualizza la lista di tutti i telefoni dell'array
    public static void visualizzaListaTelefoni(Telefono[] telefoni) {
        System.out.println("Nel negozio ci sono " + Telefono.getNTelefoni() + " telefoni\n");
        if (Telefono.getNTelefoni() != 0) {
            for (int i = 0; i < Telefono.getNTelefoni(); i++) {
                visualizzaUnTelefono(telefoni, i);
            }
        } else {
            System.out.println("Non ci sono telefoni da visualizzare!");
        }
        pause();
    }

    // Rimuove un telefono dall'array spostando i telefoni di indice superiore
    public static void rimuoviTelefono(Telefono[] telefoni, int index) {
        for (int i=index; i<Telefono.getNTelefoni()-1; i++) {
            telefoni[i] = telefoni[i+1];
        }

        Telefono.decrementaNTelefoni();
    }

    // Apre un menu per la modifica degli attributi di un telefono a scelta
    public static void modificaTelefono(Telefono[] telefoni, int index) {
        int scelta = 0;
        boolean check = true;
        String s;
        int i = 0;
        double d = 0;

        do {
            scelta = Menu.modifiermenu(telefoni, index);

            switch (scelta) {
                case 1:
                    System.out.print("Inserisci la marca: ");
                    s = sc.nextLine();
                    telefoni[index].setMarca(s);
                    break;

                case 2:
                    System.out.print("Inserisci il modello: ");
                    s = sc.nextLine();
                    telefoni[index].setModello(s);
                    break;

                case 3:
                    System.out.print("Inserisci il processore: ");
                    s = sc.nextLine();
                    telefoni[index].setProcessore(s);
                    break;

                case 4:
                    do {
                        check = true;
                        System.out.print("Inserisci la memoria in GB: ");
                        s = sc.nextLine();
                        try {
                            i = Integer.parseInt(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    telefoni[index].setMemoria(i);
                    break;

                case 5:
                    do {
                        check = true;
                        System.out.print("Inserisci l'anno di uscita: ");
                        s = sc.nextLine();
                        try {
                            i = Integer.parseInt(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    telefoni[index].setAnno(i);
                    break;

                case 6:
                    do {
                        check = true;
                        System.out.print("Inserisci il prezzo: ");
                        s = sc.nextLine();
                        try {
                            d = Double.parseDouble(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    telefoni[index].setPrezzo(d);
                    break;

                case 7:
                    do {
                        check = true;
                        System.out.print("Inserisci la versione dell'OS: ");
                        s = sc.nextLine();
                        try {
                            d = Double.parseDouble(s);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    telefoni[index].setVersione(d);
                    break;
            }
        } while(scelta!=0);
    }

    public static void main(String[] args) {
        int scelta;
        final int DIM = 30;
        Telefono[] telefoni = new Telefono[DIM];
        String str_index;
        boolean check = true;

        do {
            scelta = Menu.menu();

            switch (scelta) {
                case 99: // questo case è utile al test del codice
                    inserisciValoriDiTest(telefoni);
                    break;

                case 1:
                    aggiungiTelefono(telefoni);
                    break;

                case 2:
                    visualizzaListaTelefoni(telefoni);
                    break;

                case 3:
                    int rm_index = 0;
                    System.out.println();
                    for(int i=0; i<Telefono.getNTelefoni(); i++) {
                        System.out.println((i+1) + ". " + telefoni[i].getMarca() + " " + telefoni[i].getModello());
                    }
                    do {
                        check = true;
                        System.out.print("Inserisci l'indice del telefono da rimuovere: ");
                        str_index = sc.nextLine();
                        try {
                            rm_index = Integer.parseInt(str_index);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    if (rm_index<=Telefono.getNTelefoni() && rm_index>0) {
                        rimuoviTelefono(telefoni, rm_index-1);
                        System.out.println("Telefono rimosso!");
                    } else {
                        System.out.println("INDICE NON VALIDO");
                    }
                    pause();
                    break;

                case 4:
                    int mod_index = 0;
                    System.out.println();
                    for(int i=0; i<Telefono.getNTelefoni(); i++) {
                        System.out.println((i+1) + ". " + telefoni[i].getMarca() + " " + telefoni[i].getModello());
                    }
                    do {
                        check = true;
                        System.out.print("Inserisci l'indice del telefono da modificare: ");
                        str_index = sc.nextLine();
                        try {
                            mod_index = Integer.parseInt(str_index);
                        } catch (NumberFormatException e) {
                            System.out.println("ERRORE");
                            check = false;
                        }
                    } while (!check);
                    if (mod_index<=Telefono.getNTelefoni() && mod_index>0) {
                        modificaTelefono(telefoni, mod_index-1);
                        System.out.println("Telefono modificato!");
                    } else {
                        System.out.println("INDICE NON VALIDO");
                    }
                    pause();
                    break;
            }
        } while(scelta!=0);
    }
}