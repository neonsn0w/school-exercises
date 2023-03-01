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
        cout << endl << "Inserisci il " << i+1 << " elemento: ";
        cin >> v[i];
    }
}

void copiaArray(double v[], double w[], int size, double min, double max, int &countBetween) {
    countBetween=0;
    for (int i = 0; i < size; i++) {
        if (v[i]>=min&&v[i]<=max) {
            w[countBetween] = v[i];
            countBetween++;
        }
    }
}

void stampaVettore(double w[], int countBetween) {
    cout << "I numeri tra il minimo e il massimo sono:" << endl;
    for (int i=0; i < countBetween; i++) {
        cout << w[i] << endl;
    }
}

int main() {
    int scelta, size, countBetween;
    const int DIM = 30;
    double v[DIM], w[DIM], max, min;

    cout << "Inserisci il numero di elementi: ";
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
                cout << endl << "Inserisci il numero minimo: ";
                cin >> min;
                cout << endl << "Inserisci il numero massimo: ";
                cin >> max;
                copiaArray(v, w, size, min, max, countBetween);
                clear();
                break;
            case 2:
                stampaVettore(w, countBetween);
                pause();
                clear();
                break;
        }
    } while (scelta != 0);

    pause();
    return 0;
}