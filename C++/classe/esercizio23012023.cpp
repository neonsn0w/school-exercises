#include <iostream>
#include <cstdlib>

using namespace std;

bool controllopari(int p) {
    if (p % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool controlloPrimo(int p) {
    int i;
    for (i = 2; i < p; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

int stampaDivisori(int d) {
    int i;
    for (i = 1; i <= d; i++) {
        if (d % i == 0) {
            cout << i << endl;
        }
    }
    return 0;
}

int main() {
    int n;

    cout << "Inserisci un numero: ";
    cin >> n;
    while (n < 0) {
        cout << "Inserisci un numero positivo: ";
        cin >> n;
    }

    if (controllopari(n)) {
        cout << "Il numero e' pari" << endl;
    } else {
        cout << "Il numero e' dispari" << endl;
    }

    if (controlloPrimo(n)) {
        cout << "Il numero e' primo" << endl;
    } else {
        cout << "Il numero non e' primo" << endl;
    }

    cout << "I divisori del numero sono: " << endl;
    stampaDivisori(n);

    return 0;
    system("pause");
}