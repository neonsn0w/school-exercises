#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int v[8];

    for (int i = 0; i < 8; i++) {
        cout << endl << "Inseririsci il numero in posizione " << i << " = ";
        cin >> v[i];

        if (v[i] < 0) {
            i--;
        }
    }
    
    for (int i = 0; i < 8; i++) {
        cout << v[i] << endl;
    }

    system("pause");
    return 0;
}