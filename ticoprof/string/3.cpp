// Leggi una stringa e un carattere e conta quante volte quel carattere è contenuto nella stringa.

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

int isInside(string &s, char c) {
    int count = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << "Inserisci una stringa: ";
    string s;
    getline(cin, s);
    cout << "Inserisci un carattere: ";
    char c;
    cin >> c;
    cout << endl << "Il carattere " << c << " e' contenuto " << isInside(s, c) << " volte nella stringa." << endl;

    pause();
    return 0;
}