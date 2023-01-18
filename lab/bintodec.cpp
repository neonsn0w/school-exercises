#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int bin, dec = 0, mul = 1, resto;
    cout << "Inserire numero binario: ";
    cin >> bin;
    while (bin > 0){
        resto = bin % 10;
        dec = dec + resto * mul;
        bin = bin / 10;
        mul = mul * 2;
    }
    cout << "Il numero decimale è: " << dec << endl;
    return 0;
    //system("pause")
}