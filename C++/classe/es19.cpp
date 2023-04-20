#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Press Enter to continue...' var");
#endif
}

int menu() {
    int scelta;
    cout << endl << "1. Inserisci elementi" << endl;
    cout << "2. Stampa elementi" << endl;
    cout << "0. Esci" << endl << endl;
    cout << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

void caricaVettore(double v[], int size) {
    for (int i = 0; i < size; i++) {
        cout << endl << "Inserisci la " << i+1 << " misura: ";
        cin >> v[i];
    }
}

void mediaATrePunte(double v[], double w[], int size) {
    for (int i = 0; i < size; i++) {
        if (i==0) {
            w[i] = (v[i] + v[i] + v[i+1])/3;
        } else if (i==size-1) {
            w[i] = (v[i] + v[i] + v[i - 1])/3;
        } else {
            w[i] = (v[i] + v[i+1] + v[i-1])/3;
        }
    }
}

void stampaVettore(double w[], int size) {
    cout << "I dati modificati sono:" << endl;
    for (int i=0; i < size; i++) {
        cout << w[i] << endl;
    }
}

int main() {
    int scelta, size;
    const int DIM = 30;
    double v[DIM], w[DIM];

    cout << "Inserisci il numero di misure con cui lavorare: ";
    cin >> size;

    clear();
    do {
        scelta = menu();
        clear();
        switch (scelta) {
            case 0:
                break;
            case 1:
                caricaVettore(v, size);
                mediaATrePunte(v, w, size);
                clear();
                break;
            case 2:
                stampaVettore(w, size);
                pause();
                clear();
                break;
        }
    } while (scelta != 0);

    pause();
    return 0;
}