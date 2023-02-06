#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int v[8], sum=0;
    
    for (int i = 0; i < 8; i++) {
        cout << endl << "Inseririsci il numero in posizione " << i << " = ";
        cin >> v[i];
    }

    for (int i = 0; i < 8; i++) {
        if (v[i] < 0) {
            sum += v[i];
            v[i] = 0;
        }
    }

    cout << endl << "La somma dei numeri negativi e' " << sum << endl;
    cout << endl << "Il vettore modificato e': " << endl;
    for (int i = 0; i < 8; i++) {
        cout << v[i] << endl;
    }
    
    system("pause");
    return 0;
}