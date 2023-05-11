#include <iostream>

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

// Struct tpiloti
struct tpiloti {
    char nome[69];
    char scuderia[69];
    int punti;
};

// Funzione per stampare il menu
int menu() {
    int scelta;
    cout << endl << "1. Inserisci un pilota" << endl;
    cout << "2. Inserisci un circuito" << endl;
    cout << "3. Visualizza la lista dei piloti" << endl;
    cout << "4. Visualizza la lista dei circuiti" << endl;
    cout << endl << "0. Esci" << endl;

    cout << endl << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

// Funzione per inserire un libro
void inserisciPilota(tpiloti piloti[], int &nPiloti) {
    cout << "Inserisci il nome del pilota: ";
    cin >> piloti[nPiloti].nome;
    cout << "Inserisci la scuderia del pilota: ";
    cin >> piloti[nPiloti].scuderia;
    cout << "Inserisci il punteggio del pilota: ";
    cin >> piloti[nPiloti].punti;
    nPiloti++;
}

// Funzione per inserire un circuito
void inserisciCircuito(string circuiti[], int &nCircuiti) {
    cout << "Inserisci il nome del circuito: ";
    cin >> circuiti[nCircuiti];
    nCircuiti++;
}

// Funzione che elenca i piloti
void elencoPiloti(tpiloti piloti[], int nPiloti) {
    for (int i = 0; i < nPiloti; i++) {
        cout << piloti[i].nome << endl;
        cout << piloti[i].scuderia << endl;
        cout << piloti[i].punti << endl << endl;
    }
}

// Funzione che elenca i circuiti
void elencoCircuiti(string circuiti[], int nCircuiti) {
    for (int i = 0; i < nCircuiti; i++) {
        cout << circuiti[i] << endl;
    }
}

// Funzione che elenca i piloti di una scuderia
void elencaPilotiScuderia(tpiloti piloti[], int nPiloti) {
    char scuderia[69];
    cout << "Inserisci il nome della scuderia: ";
    cin >> scuderia;
    for (int i = 0; i < nPiloti; i++) {
        if (piloti[i].scuderia == scuderia) {
            cout << piloti[i].nome << endl;
            cout << piloti[i].punti << endl << endl;
        }
    }
}

int main() {
    tpiloti piloti[20];
    string circuiti[10];
    int arrivi[20][10];
    int scelta, nPiloti = 0, nCircuiti = 0;

    do {
        clear();
        scelta = menu();
        switch (scelta) {
            case 1:
                clear();
                inserisciPilota(piloti, nPiloti);
                break;
            case 2:
                clear();
                inserisciCircuito(circuiti, nCircuiti);
                break;
            case 3:
                clear();
                elencoPiloti(piloti, nPiloti);
                break;
            case 4:
                clear();
                elencoCircuiti(circuiti, nCircuiti);
                break;
        }
    } while (scelta != 0);

    return 0;
}