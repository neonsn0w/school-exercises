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

// Funzione per stampare il menu
int menu(bool emptyString) {
    int scelta;
    cout << endl << "1. Inserisci stringa" << endl;
    if (!emptyString) {
        cout << "2. Visualizza la stringa" << endl;
        cout << "3. Conta le vocali della stringa" << endl;
        cout << "4. Aggiungi un'altra stringa nella stringa principale" << endl;
        cout << "5. Estrai una sottostringa data la posizione di inizio e la lunghezza" << endl;
    }
    cout << endl << "0. Esci" << endl;

    cout << endl << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

// Funzione per contare i caratteri di una stringa
int contaChar(string s) {
    int dim = 0;
    while (s[dim++] != '\0');
    return dim;
}

// Funzione per contare le vocali di una stringa
int contaVocali(string s, int dim) {
    int nvocali = 0;
    for (int i = 0; i < dim-1; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            nvocali++;
        }
    }
    return nvocali;
}

// Funzione per inserire una stringa in un'altra
void inserisciStringa(string &s1, string s2, int pos) {
    string s3 = "";

    for (int i = 0; i < pos; i++) {
        s3 += s1[i];
    }

    s3 += s2;

    for (int i = pos; i < contaChar(s1); i++) {
        s3 += s1[i];
    }

    s1 = s3;
}

// Funzione per estrarre una sottostringa data la posizione di inizio e la lunghezza
string sottostringa (string s1, int pos, int lung) {
    string s2 = "";
    for (int i = pos; i < pos+lung; i++) {
        s2 += s1[i];
    }
    return s2;
}

int main() {
    string s1, s2;
    int pos, scelta, dim1, dim2, nvocali, lung;
    bool emptyString = true;

     do {
        clear();
        scelta = menu(emptyString);

        switch(scelta) {
        case 0:
            break;

        case 1:
            clear();
            cout << "Inserisci una stringa: ";
            cin.ignore();
            getline(cin, s1);
            emptyString = false;
            break;
        
        case 2:
            if (emptyString) {
                break;
            }
            clear();
            cout << "La stringa inserita è " << s1 << endl;
            pause();
            break;

        case 3:
            if (emptyString) {
                break;
            }
            clear();
            dim1 = contaChar(s1);
            nvocali = contaVocali(s1, dim1);
            cout << "La stringa inserita ha " << nvocali << " vocali" << endl;
            pause();
            break;

        case 4:
            if (emptyString) {
                break;
            }
            clear();
            cout << "Inserisci un'altra stringa: ";
            cin.ignore();
            getline(cin, s2);
            cout << "Digitare la posizione in cui inserire la seconda stringa: ";
            cin >> pos;

            dim2 = contaChar(s2);

            inserisciStringa(s1, s2, pos);
            cout << "Il risultato è " << s1 << endl;
            pause();
            break;

        case 5:
            if (emptyString) {
                break;
            }
            clear();
            cout << "Inserisci la posizione di inizio: ";
            cin >> pos;
            cout << "Inserisci la lunghezza: ";
            cin >> lung;

            s2 = sottostringa(s1, pos, lung);

            cout << "La sottostringa è " << s2 << endl;
            pause();
            break;
        }
    } while (scelta != 0);

    return 0;
}