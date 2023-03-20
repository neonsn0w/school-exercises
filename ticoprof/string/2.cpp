// Leggi una stringa e determina quanto è lunga.

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

int length(string s) {
    int dim = 0;
    while (s[dim++] != '\0');
    return dim;
}

int main() {
    cout << "Inserisci una stringa: ";
    string s;
    getline(cin, s);
    cout << endl << "La stringa e' lunga " << length(s)-1 << " caratteri." << endl;

    pause();
    return 0;
}