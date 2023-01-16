#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int prezzo, soldi = 0, resto;

    srand(time(NULL));

    prezzo = rand() % 1000 + 1;

    cout << "Il prezzo del prodotto e' " << prezzo << " euro." << endl;

    while (prezzo>soldi) {
        soldi = rand() % 8 + 1;
        if (soldi == 1){
            soldi = 5;
        } else if (soldi == 2){
            soldi = 10;
        } else if (soldi == 3){
            soldi = 20;
        } else if (soldi == 4){
            soldi = 50;
        } else if (soldi == 5){
            soldi = 100;
        } else if (soldi == 6){
            soldi = 200;
        } else if (soldi == 7){
            soldi = 500;
        } else if (soldi == 8){
            soldi = 1000;
        }
    }
    
    resto = soldi - prezzo;

    cout << "Il cliente ha pagato " << soldi << " euro." << endl;

    cout << "Il resto e' " << resto << " euro." << endl;

    return 0;
}