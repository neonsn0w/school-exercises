// Leggi due stringhe e verifica quale è più lunga.

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Fuznione per pulire la console (cross-platform)
// void clear() {
// #ifdef _WIN32
//     system("cls");
// #else
//     system("clear");
// #endif
// }

// Funzione per mettere in pausa l'esecuzione (cross-platform)
void pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Premi Enter per continuare...' var");
#endif
}

int main() {
    int s1, s2;
    cout << "Inserisci la prima stringa: ";
    string s;
    getline(cin, s);
    s1 = s.length();
    cout << "Inserisci la seconda stringa: ";
    getline(cin, s);
    s2 = s.length();
    if (s1 > s2) {
        cout << "La prima stringa e' piu' lunga della seconda." << endl;
    } else if (s1 < s2) {
        cout << "La seconda stringa e' piu' lunga della prima." << endl;
    } else {
        cout << "Le due stringhe sono lunghe uguali." << endl;
    }

    pause();
    return 0;
}