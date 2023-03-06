#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ordinaDati(int v[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void caricaInsieme(int ins1[], int ins2[], int size) {
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        ins1[i] = 1 + rand() % 10;
        for(int j=i-1; j>=0; j--) {
            if (ins1[i] == ins1[j]) {
                i--;
            }
        }
    }

    for(int i=0; i<size; i++) {
        ins2[i] = 1 + rand() % 10;
        for(int j=i-1; j>=0; j--) {
            if (ins2[i] == ins2[j]) {
                i--;
            }
        }
    }

    ordinaDati(ins1, size);
    ordinaDati(ins2, size);

    for(int i=0; i<size; i++) {
        cout << ins1[i] << endl;
    }
    cout << endl;
    for(int i=0; i<size; i++) {
        cout << ins2[i] << endl;
    }
}

void intersezione(int ins1[], int ins2[], int size, int inters[], int &intersize) {
    for (int i=0; i<size; i++) {
        for (int j=i; j<size; j++) {
            if(ins1[i] == ins2[j]) {
                inters[intersize] = ins1[i];
                intersize++;
            }
        }
    }
}

int main() {
    int size, intersize = 0;
    const int DIM = 30;
    cout << "Inserisci la dimensione dell'insieme: " << endl;
    cin >> size;
    int ins1[DIM];
    int ins2[DIM];
    caricaInsieme(ins1, ins2, size);
    int inters[DIM];
    intersezione(ins1, ins2, size, inters, intersize);
    for (int i=0; i<size; i++) {
        cout << inters[i] << endl;
    }
    return 0;
}