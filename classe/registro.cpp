#include <iostream>
#include <string>

using namespace std;

int menu() {
    int scelta;
    cout << endl << "1. Inserisci studenti" << endl;
    cout << "2. Leggi dati" << endl;
    cout << "3. Media voti" << endl;
    cout << "4. Miglior studente" << endl;
    cout << "5. Peggior studente" << endl;
    cout << "0. Esci" << endl << endl;
    cout << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

void caricaVettore(string V[], float voti[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Inserisci una stringa: ";
        getline(cin, V[i]);
        cout << "Inserisci voto dello studente: ";
        cin >> voti[i];
        while (voti[i] > 10) {
            cout << "Hai inserito un valore superiore al 10" << endl;
            cout << "Inserisci voto dello studente: ";
            cin >> voti[i];
        }
        cin.ignore();
    }
}

void leggiVettore(string V[], float voti[], int DIM) {
    for (int i = 0; i < DIM; i++) {
        cout << "Nome in posizione: " << i+1 << " " << V[i] << endl;
        cout << "Voto dello studente: " << voti[i] << endl;
        cout << endl;
    }
}

float mediaVoti(const float voti[], int DIM) {
    float mediaTotale = 0;
    for (int i = 0; i < DIM; i++) {
        mediaTotale += voti[i];
    }
    return mediaTotale/DIM;
}

string migliorStudente(string studenti[], float voti[], int DIM) {
    string migliorStudente;
    float maxVoto = 0;
    for (int i = 0; i < DIM; i++) {
        if (voti[i] > maxVoto) {
            migliorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return migliorStudente;
}

string peggiorStudente(string studenti[], float voti[], int DIM) {
    string peggiorStudente;
    float maxVoto = 10;
    for (int i = 0; i < DIM; i++) {
        if (voti[i] < maxVoto) {
            peggiorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return peggiorStudente;
}

int main() {
    //const int DIM = 2;
    //string studenti[DIM];
    //float voti[DIM];

    // cout << "Registro Elettronico" << endl;
    // caricaVettore(studenti, voti, DIM);
    // leggiVettore(studenti, voti, DIM);
    // cout << endl << "Media dei voti: " << mediaVoti(voti, DIM);
    // cout << endl << "Miglior studente: " << migliorStudente(studenti, voti, DIM);
    // cout <<  endl << "Peggior studente: " << peggiorStudente(studenti, voti, DIM);
    int scelta, x;
    cout << "Inserisci numero di studenti: ";
    cin >> x;
    const int DIM = x;
    string studenti[DIM];
    float voti[DIM];
    do
    {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;
        // case 1:
        //     cout << "Inserisci numero di studenti: ";
        //     cin >> DIM;
        //     break;

        case 1:
            cin.ignore();
            caricaVettore(studenti, voti, DIM);
            break;

        case 2:
            leggiVettore(studenti, voti, DIM);
            break;

        case 3:
            cout << endl << "Media dei voti: " << mediaVoti(voti, DIM);
            break;

        case 4:
            cout << endl << "Miglior studente: " << migliorStudente(studenti, voti, DIM);
            break;

        case 5:
            cout <<  endl << "Peggior studente: " << peggiorStudente(studenti, voti, DIM);
            break;
        }
    } while (scelta != 0);

    return 0;
}