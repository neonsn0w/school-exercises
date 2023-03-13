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
int isConvertible(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+' && s[i] != '.') {
            return -1;
        }
    }
    if (s[0] == '-') {
        return 1;
    } else if (s[0] == '+') {
        return 2;
    } else {
        return 0;
    }
}

// Funzione per convertire una stringa in intero
double tboi(string s, int sign) {
    bool point = false;
    int tencounter = 1;
    double result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            point = true;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            if (point) {
                tencounter *= 10;
                result = result + ((s[i] - '0') / tencounter);
            } else {
                result = result * 10 + (s[i] - '0');
            }
        }
    }
    if (sign == 1) {
        return -result;
    } else {
        return result;
    }
}

int main() {
    string s;
    double result;
    cout << "Inserisci una stringa: ";
    cin >> s;

    if (isConvertible(s)>=0) {
        result = tboi(s, isConvertible(s));
        cout << "La stringa convertita in dabol e': " << result << endl;
    } else {
        cout << "La stringa non e' convertibile in intero" << endl;
    }
}