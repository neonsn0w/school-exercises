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

void visualizzaLibri(recLibro libri[], int nLibri) {
    for (int i = 0; i < nLibri; i++) {
        cout << "Titolo: " << libri[i].titolo << endl;
        cout << "Codice: " << libri[i].codice << endl;
        cout << "Pagine: " << libri[i].pagine << endl;
        cout << "Prezzo: " << libri[i].prezzo << endl;
        cout << "------------------------------------";
        cout << endl;
    }
}

int main() {
    int scelta;
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
                visualizzaLibri(libri, nLibri);
                pause();
                break;
            }
    } while (scelta != 0);
}