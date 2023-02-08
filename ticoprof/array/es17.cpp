/*
Es 17. Leggere un array di interi di 10 posizioni e stampare il numero che compare più volte all’interno dell’array,
qualora ci siano più numeri che compaiano lo stesso numero di volte stampare quello che compare per primo.
*/

#include <iostream>

using namespace std;


int inserimentoArray(int i) {
    int n;
    cout << "Inserisci un numero in posizione "<< i << ": ";
    cin >> n;
    /*
    if(n < 0) {
        cout << "Inserisci un numero positivo!!!" << endl;
        inserimentoarray(n);
    }
    */
    return n;
}

int main() {
    int v[10], nvmagg = 0, nvatt, nmagg;

    for(int i=0; i<10; i++) {
        v[i] = inserimentoArray(i);
    }

    nmagg = v[0];

    for(int i=0; i<10; i++) {
        nvatt = 0;
        for(int j=0; j<10; j++) {
            if(v[i] == v[j]) {
                nvatt++;
            }
        }
        if(nvatt > nvmagg) {
            nvmagg = nvatt;
            nmagg = v[i];
        }
    }

    cout << "Il numero che compare più volte è: " << nmagg << " che compare " << nvmagg << " volte." << endl;



    system("PAUSE");
    return 0;
}