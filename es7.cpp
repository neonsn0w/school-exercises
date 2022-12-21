#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int anno;
    cout << "anno = ";
    cin >> anno;
    if (anno%400 == 0) {
        cout << endl << "bisestile" << endl;
        system("pause");
        return 0;
    } else if (anno%4 == 0) {
        if (anno%100 != 0) {
            cout << endl << "bisestile" << endl;
            system("pause");
            return 0;
        } else {
            cout << endl << "non bisestile" << endl;
            system("pause");
            return 0;
        }
    } else {
        cout << endl << "non bisestile" << endl;
        system("pause");
        return 0;
    }
}
