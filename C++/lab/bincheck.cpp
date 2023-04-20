#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cout << "Inserire numero binario: ";
    cin >> n;

    if ( n % 10 == 0 || n % 10 == 1 ) {
        cout << "Il numero è binario" << endl;
    } else {
        cout << "Il numero non è binario" << endl;    
    }

    return 0;
    //system("pause")
}