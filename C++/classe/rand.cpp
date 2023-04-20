#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Questo metodo carica il vettore con i valori inseriti dall'utente.
void randVettore(int v[], int dim) {
    int temp, counter = 0;
    for (int i = 0; i < dim; i++) {
        int x;
        cout << "Inserire il numero in posizione " << i << " = ";
        cin >> x;

        v[i] = x;
        counter++;

        for (int k = 0; k < counter; k++)
        {
            for (int j = k + 1; j < counter; j++)
            {
                if (v[k] > v[j])
                {
                    temp = v[k];
                    v[k] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
}

// Questo metodo stampa il contenuto del vettore.
void stampaVettore(int v[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << v[i] << " ";
    }
}

int main() {
    const int DIM = 10;
    int v[DIM];

    srand(time(NULL));
    cout << "Sorting Algorithm" << endl;
    randVettore(v, DIM);
    stampaVettore(v, DIM);

    return 0;
}