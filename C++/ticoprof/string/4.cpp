// Leggi una stringa e determina quante vocali contiene.

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

int countVowels(string s) {
    int nvocali = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            nvocali++;
        }
    }
    return nvocali;
}

int main() {
    cout << "Inserisci una stringa: ";
    string s;
    getline(cin, s);
    cout << endl << "La stringa contiene " << countVowels(s) << " vocali." << endl;

    pause();
    return 0;
}