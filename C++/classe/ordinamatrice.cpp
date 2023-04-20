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

// Funzione per stampare il menu
int menu() {
    int scelta;
    cout << endl << "1. Randomizza matrice" << endl;
    cout << "2. Visualizza matrice" << endl;
    cout << "3. Ordina matrice" << endl;
    cout << endl << "0. Esci" << endl;

    cout << endl << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

// Funzione per randomizzare una matrice
void randomizzaMatrice(int matrice[][100], int dim, int dimm) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dimm; j++) {
            matrice[i][j] = rand() % 100;
        }
    }
}

// Funzione per visualizzare una matrice
void visualizzaMatrice(int matrice[][100], int dim, int dimm) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dimm; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

// Funzione per ordinare una matrice
void ordinaMatrice(int matrice[][100], int dim, int dimm) {
    int temp;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dimm; j++) {
            for (int k = 0; k < dim; k++) {
                for (int l = 0; l < dimm; l++) {
                    if (matrice[i][j] < matrice[k][l]) {
                        temp = matrice[i][j];
                        matrice[i][j] = matrice[k][l];
                        matrice[k][l] = temp;
                    }
                }
            }
        }
    }
}


int main() {
    int matrice[100][100];
    int dim, dimm, scelta;

    cout << "Inserisci il numero di righe della matrice: ";
    cin >> dim;

    cout << "Inserisci il numero di colonne della matrice: ";
    cin >> dimm;

    do {
        clear();
        scelta = menu();
        switch (scelta) {
            case 1:
                randomizzaMatrice(matrice, dim, dimm);
                break;
            case 2:
                visualizzaMatrice(matrice, dim, dimm);
                break;
            case 3:
                ordinaMatrice(matrice, dim, dimm);
                break;
            case 0:
                break;
            default:
                cout << "Scelta non valida" << endl;
                break;
        }
        pause();
    } while (scelta != 0);
}