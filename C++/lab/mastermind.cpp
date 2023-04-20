#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;

int menu() {
    int scelta;
    cout << "1. Gioca" << endl;
    cout << "2. Esci" << endl;
    cout << "Scelta: ";
    cin >> scelta;
    return scelta;
}

void codiceCasuale(string code[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        int random = rand() % 9;
        switch (random) {
            case 0:
                code[i] = "R";
                break;
            case 1:
                code[i] = "G";
                break;
            case 2:
                code[i] = "B";
                break;
            case 3:
                code[i] = "Y";
                break;
            case 4:
                code[i] = "O";
                break;
            case 5:
                code[i] = "P";
                break;
            case 6:
                code[i] = "W";
                break;
            case 7:
                code[i] = "V";
                break;
            case 8:
                code[i] = "M";
                break;  
        }
    }
}

bool checkCode(string code[], string answer[], int SIZE) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (code[i] == answer[i]) {
            count++;
        }
    }

    if (count == SIZE) {
        return true;
    } else {
        return false;
    }
}

void checkPos(string code[], string answer[], int SIZE) {
    int posGiusta = 0, posErrata = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (code[i] == answer[i])
        {
            posGiusta++;
        }
        else
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (code[i] == answer[j])
                {
                    posErrata++;
                }
            }
        }
    }

    cout << "Colori in posizione giusta: " << posGiusta << endl;
    cout << "Colori giusti ma in posizione sbagliata: " << posErrata << endl;
}

void stampaArray(string array[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
}

void inserisciCodice(string answer[], int SIZE) {
    cout << "Inserisci il codice: ";
    for (int i = 0; i < SIZE; i++) {
        cout << "Inserisci il " << i + 1 << "° colore: ";
        cin >> answer[i];

        if (answer[i][0] >= 'a' && answer[i][0] <= 'z')
        {
            answer[i][0] -= 32;
        }
    }

    cout << endl;

    cout << "Codice inserito: ";
    cout.flush();
    stampaArray(answer, SIZE);
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
#ifdef _WIN32
    system("pause");
#else
    system("read -p 'Press Enter to continue...' var");
#endif
}



int main() {
    const int SIZE = 4;
    string code[SIZE];
    string answer[SIZE];
    int maxTries = 10, tries = 0, input = 0;
    bool win = false;

    srand(time(NULL));

    cout << "Benvenuto in Master Mind!" << endl;

    codiceCasuale(code, SIZE);

    do
    {

        input = menu();

        while (tries < maxTries && !win && input == 1)
        {
            clearScreen();

            inserisciCodice(answer, SIZE);

            if (checkCode(code, answer, SIZE))
            {
                win = true;
            }
            else
            {
                tries++;
            }

            checkPos(code, answer, SIZE);

            if (!win)
            {
                cout << "Tentativi rimanenti: " << maxTries - tries << endl;
                pause();
            }
        }

        if (win && input == 1)
        {
            cout << "Hai vinto!" << endl;
            pause();
        }
        else if (tries == maxTries && input == 1)
        {
            cout << "Hai perso!" << endl;
            cout << "La sequenza era: ";
            stampaArray(code, SIZE);
            pause();


        }
        
        // Reset variabili
        win = false;
        tries = 0;
        codiceCasuale(code, SIZE);
        cout << endl;

    } while (input != 2);

    return 0;
}
