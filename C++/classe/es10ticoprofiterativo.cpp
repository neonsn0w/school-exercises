// Scrivere una funzione iterativa che ricevuto un intero n stampi n ‘-‘ seguiti da n ‘+’.
// Ad esempio se la funzione riceve 3 stampa – – – + + +.
// Usare un solo ciclo for

#include <iostream>
using namespace std;

void stampa(int n) {
    for (int i = 0; i < 2*n; i++) {
        if (i < n) {
            cout << "-";
        } else {
            cout << "+";
        }
    }
}

int main() {
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    stampa(n);
    return 0;
}