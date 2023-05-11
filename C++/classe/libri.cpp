#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Fuznione per pulire la console (cross-platform)
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Funzione per mettere in pausa l'esecuzione (cross-platform)
void pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Premi Enter per continuare...' var");
#endif
}

// Struct libro
struct recLibro {
    char titolo[69];
    int codice;
    int pagine;
    float prezzo;
};

// Funzione per stampare il menu
int menu() {
    int scelta;
    cout << endl << "1. Inserisci un libro" << endl;
    cout << "2. Visualizza la lista dei libri" << endl;
    cout << "3. Visualizza la lista dei libri ordinata per nome" << endl;
    cout << "4. Ricerca un libro dato il codice" << endl;
    cout << endl << "0. Esci" << endl;

    cout << endl << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

// Funzione per inserire un libro
void inserisciLibro(recLibro libri[], int &nLibri) {
    cout << "Inserisci il titolo del libro: ";
    cin >> libri[nLibri].titolo;
    cout << "Inserisci il codice del libro: ";
    cin >> libri[nLibri].codice;
    cout << "Inserisci il numero di pagine del libro: ";
    cin >> libri[nLibri].pagine;
    cout << "Inserisci il prezzo del libro: ";
    cin >> libri[nLibri].prezzo;
    nLibri++;
}

// Funzione per visualizzare un libro
void visualizzaLibro(recLibro libri[], int nLibri, int i) {
    cout << "Titolo: " << libri[i].titolo << endl;
    cout << "Codice: " << libri[i].codice << endl;
    cout << "Pagine: " << libri[i].pagine << endl;
    cout << "Prezzo: " << libri[i].prezzo << endl;
    cout << "------------------------------------";
    cout << endl;
}

// Funzione per ordinare i dati per titolo
void ordinaDati(recLibro v1[], int dim) {
    recLibro temp;
    for (int i=0; i < dim-1; i++) {
        for (int j=i+1; j < dim; j++) {
            if (v1[i].titolo < v1[j].titolo) {
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;
            }
        }
    }
}

// Funzione per visualizzare i libri ordinati per nome
void visualizzaLibriOrdinatiNome(recLibro libri[], int nLibri) {
    recLibro libriOrdinati[100];
    for (int i = 0; i < nLibri; i++) {
        libriOrdinati[i] = libri[i];
    }

    ordinaDati(libriOrdinati, nLibri);

    for (int i = 0; i < nLibri; i++) {
        cout << "Titolo: " << libriOrdinati[i].titolo << endl;
        cout << "Codice: " << libriOrdinati[i].codice << endl;
        cout << "Pagine: " << libriOrdinati[i].pagine << endl;
        cout << "Prezzo: " << libriOrdinati[i].prezzo << endl;
        cout << "------------------------------------";
        cout << endl;
    }
}

// Ricerca del libro dato il codice
int ricercaLibroCodice(recLibro libri[], int nLibri, int codice) {
    for (int i = 0; i < nLibri; i++) {
        if (libri[i].codice == codice) {
            return i;
        }
    }
    return -1;
}

// main
int main() {
    int scelta, codice;
    int nLibri=0;
    const int MAX_LIBRI = 100;
    recLibro libri[MAX_LIBRI];
    do {
        clear();
        scelta = menu();

        switch(scelta) {
            case 0:
                break;

            case 1:
                clear();
                inserisciLibro(libri, nLibri);
                break;

            case 2:
                clear();
                for(int i=0; i < nLibri; i++) {
                    visualizzaLibro(libri, nLibri, i);
                }
                pause();
                break;

            case 3:
                clear();
                visualizzaLibriOrdinatiNome(libri, nLibri);
                pause();
                break;

            case 4:
                clear();
                cout << "Inserisci il codice del libro da cercare: ";
                cin >> codice;
                codice = ricercaLibroCodice(libri, nLibri, codice);
                clear();
                if (codice==-1) {
                    cout << "Libro non trovato" << endl;
                } else {
                    visualizzaLibro(libri, nLibri, codice);
                }
                pause();
                break;
            }
    } while (scelta != 0);
}