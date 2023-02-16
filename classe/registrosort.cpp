#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void inserimentoDati(int v1[], string v2[], int dim) {
    for (int i = 0; i < dim; i++) {
        int v;
        string n;
        cout << "Inserire il voto dello studente " << i << " = ";
        cin >> v;
        cout << "Inserire il nome dello studente " << i << " = ";
        cin >> n;
        cout << endl;

        v1[i] = v;
        v2[i] = n;
    }
}

void ordinaDati(int v1[], string v2[], int dim) {       
    string stemp;
    int temp;
    for (int i; i < dim-1; i++) {
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

void stampaArray(int v1[], string v2[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << "Studente " << i << " = " << v1[i] << endl << "Voto = " << v2[i] << endl << endl;
    }
}

int main() {
    int x;

    cout << "Inserire il numero di studenti: ";
    cin >> x;
    cout << endl << endl;
    const int DIM = x;
    int voti[DIM];
    string nomi[DIM];

    inserimentoDati(voti, nomi, DIM);

    ordinaDati(voti, nomi, DIM);

    stampaArray(voti, nomi, DIM);

    return 0;
}