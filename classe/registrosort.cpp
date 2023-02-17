#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void inserimentoDati(int v1[], string v2[], int dim) {
    for (int i = 0; i < dim; i++) {
        int v;
        string n;
        cout << "Inserire il voto del " << i+1 << " studente = ";
        cin >> v;
        v1[i] = v;
        cin.ignore();
        cout << "Inserire il nome del " << i+1 << " studente = ";
        getline(cin, v2[i]);
        cout << endl;
    }
}

void ordinaDati(int v1[], string v2[], int dim) {
    string stemp;
    int temp;
    for (int i=0; i < dim-1; i++) {
        for (int j=i+1; j < dim; j++) {
            if (v1[i] > v1[j]) {
                temp = v1[i];
                v1[i] = v1[j];
                v1[j] = temp;

                stemp = v2[i];
                v2[i] = v2[j];
                v2[j] = stemp;
            }
        }
    }
}

void ordinaNomi(string v2[], int dim) {
    string stemp;
    for (int i=0; i < dim-1; i++) {
        for (int j=i+1; j < dim; j++) {
            if (v2[i] > v2[j]) {
                stemp = v2[i];
                v2[i] = v2[j];
                v2[j] = stemp;
            }
        }
    }
}

void stampaArray(int v1[], string v2[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Studente " << i << " = " << v2[i] << endl << "Voto = " << v1[i] << endl << endl;
    }
}

void stampaNomi(string v2[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Studente " << i << " = " << v2[i] << endl;
    }
}


int main() {
    int x;

    cout << "Inserire il numero di studenti: ";
    cin >> x;
    while (x < 1) {
        cout << endl << "Inserire un numero maggiore di 0: ";
        cin >> x;
    }
    cout << endl << endl;
    const int DIM = x;
    int voti[DIM];
    string nomi[DIM];

    inserimentoDati(voti, nomi, DIM);

    ordinaDati(voti, nomi, DIM);

    stampaArray(voti, nomi, DIM);

    ordinaNomi(nomi, DIM);

    stampaNomi(nomi, DIM);

    return 0;
}