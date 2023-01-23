#include <iostream>
#include <cstdlib>

using namespace std;

void stampaQuadrato(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            cout << "+";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int x, i = 0;

    cout << "Inserisci la dimensione del lato quadrato: ";
    cin >> x;

    while(x < 0) {
        cout << "Inserisci un numero positivo: ";
        cin >> x;
    }

    while(i <= x) {
        stampaQuadrato(i);
        i++;
    }
    i--;
    i--;
    while(i > 0) {
        stampaQuadrato(i);
        i--;
    }
}