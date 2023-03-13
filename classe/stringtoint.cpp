#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Fuznione per pulire la console (cross-platform)
void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Funzione per mettere in pausa l'esecuzione (cross-platform)
void pause() {
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Premi Enter per continuare...' var");
#endif
}

// Funzione per controllare se il valore inserito è un numero
bool isConvertible(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

// Funzione per convertire una stringa in intero
int tboi(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

int main() {
    string s;
    int result;
    cout << "Inserisci una stringa: ";
    cin >> s;

    if (isConvertible(s)) {
        result = tboi(s);
        cout << "La stringa convertita in intero e': " << result << endl;
    } else {
        cout << "La stringa non e' convertibile in intero" << endl;
    }
}