#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int v[5], max=0, pmax;

    for (int i = 0; i < 5; i++) {
        cout << endl << "Inseririsci il numero in posizione " << i << " = ";
        cin >> v[i];

        while (v[i] < 0) {
            cout << endl << "Inseririsci un numero positivo: ";
            cin >> v[i];
        }

        if (v[i] > max) {
            max = v[i];
            pmax = i;
        }
    }

    cout << endl << "Il numero maggiore e' " << max << " in posizione " << pmax << endl;

    system("pause");
    return 0;
}