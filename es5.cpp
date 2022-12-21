#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    double celsius;
    do {
        cout << "inserire celsium = ";
        cin >> celsius;
    } while (celsius < -273.15);
    cout << endl << "farenait = " << (9.0/5.0)*celsius+32.0 << endl;
    cout << "kevin = " << celsius+273.15 << endl;
    system("pause");
    return 0;
}
