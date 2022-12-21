#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n, l, tot, np, nd = 0;
    while (l==0) {
        cout << "inserisci un numero = ";
        cin >> n;
        if (n!=0) {
            tot = tot + n;
            if (n%2==0) {
                np++;
            } else {
                nd++;
            }
        } else {
            l = 1;
            cout << endl << tot;
            cout << endl << np;
            cout << endl << nd;
        };
    };
    system("pause");
    return 0;
}