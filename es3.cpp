#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n = 0;
    int l = 0;
    int tot = 0;
    while (l==0) {
        cout << "inserisci un numero = ";
        cin >> n;
        if (n!=0) {
            tot = tot + n;
        } else {
            l = 1;
            cout << endl << tot;
        };
    };
    system("pause");
    return 0;
}