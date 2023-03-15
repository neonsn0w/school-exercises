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
        for (int j=0; j<size; j++) {
            if(ins1[i] == ins2[j]) {
                inters[intersize] = ins1[i];
                intersize++;
            }
        }
    }
}

void unione(int ins1[], int ins2[], int size, int un[], int &unsize) {
    int size1 = size;
    int size2 = size;
    int i=0, j=0;

    while (i < size1 && j < size2) {
        if (ins1[i] < ins2[j]) {
            un[unsize] = ins1[i];
            i++;
        } else if (ins1[i] > ins2[j]) {
            un[unsize] = ins2[j];
            j++;
        } else {
            un[unsize] = ins1[i];
            i++;
            j++;
        }
        unsize++;
    }
}

int main() {
    int size, intersize = 0, unsize = 0;
    const int DIM = 30;
    cout << "Inserisci la dimensione dell'insieme: " << endl;
    cin >> size;
    int ins1[DIM];
    int ins2[DIM];
    caricaInsieme(ins1, ins2, size);
    int inters[DIM];
    intersezione(ins1, ins2, size, inters, intersize);
    for (int i=0; i<intersize; i++) {
        cout << inters[i] << endl;
    }
    int un[DIM];
    unione(ins1, ins2, size, un, unsize);
    for (int i=0; i<unsize; i++) {
        cout << un[i] << endl;
    }
    return 0;
}