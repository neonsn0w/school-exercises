// Leggi una stringa e trasformane le lettere minuscole in maiuscole e viceversa.

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

void lowercaseToCapsAndViceversa(string &s) {
    for (int i=0; i<s.length(); i++) {
        if (s[i]>='a' && s[i]<='z') {
            s[i] = s[i] - 32;
        } else if (s[i]>='A' && s[i]<='Z') {
            s[i] = s[i] + 32;
        }
    }
}

int main() {
    cout << "Inserisci una stringa: ";
    string s;
    getline(cin, s);
    lowercaseToCapsAndViceversa(s);
    cout << endl << "La stringa in modificata e': " << s << endl;

    pause();
    return 0;
}