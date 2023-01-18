#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int soluzione, utente, tentativi = 0;

    srand(time(NULL));
    
    soluzione = rand() % 100 + 1;

    cout << "Indovina il numero da 1 a 100" << endl;

    while (soluzione != utente) {
        cin >> utente;
        tentativi++;
        if (utente > soluzione) {
            cout << "Il numero e' piu' piccolo" << endl;
        } else if (utente < soluzione) {
            cout << "Il numero e' piu' grande" << endl;
        }
    }

    cout << "Hai indovinato il numero in " << tentativi << " tentativi" << endl;
    if (tentativi>=10) {
        cout << "bravo";
    } else {
        cout << "potresti fare di meglio";
    }
}