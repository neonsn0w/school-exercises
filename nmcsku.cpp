#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n = 0;
    int t, m = 0, nmax = 0, nmin = 0;
    cout << "quanti numeri? = ";
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << endl << "inserire numero = ";
        cin >> n;
        if (n > nmax || nmax == 0) {
            nmax = n;
            };
        if (n < nmin || nmin == 0) {
            nmin = n;
            };
        m = m + n;
        }
    m = m / t;
    cout << endl << "media = " << m;
    cout << endl << "massimo = " << nmax;
    cout << endl << "minimo = " << nmin << endl;
    system("pause");
    return  0;
}
