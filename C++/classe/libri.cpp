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
    cout << "3. Conta le vocali della stringa" << endl;
    cout << "4. Aggiungi un'altra stringa nella stringa principale" << endl;
    cout << "5. Estrai una sottostringa data la posizione di inizio e la lunghezza" << endl;
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
        }
    } while (scelta != 0);
}