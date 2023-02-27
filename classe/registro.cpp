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
    cout << "6. Aggiungi studente" << endl;
    cout << "7. Rimuovi studente" << endl;
    cout << "0. Esci" << endl << endl;
    cout << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

void ordinaDati(string V[], float voti[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (voti[i] > voti[j]) {
                float temp = voti[i];
                voti[i] = voti[j];
                voti[j] = temp;
                string temp2 = V[i];
                V[i] = V[j];
                V[j] = temp2;
            }
        }
    }
}

void caricaVettore(string V[], float voti[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Inserisci il nome del " << i+1 << " studente: ";
        getline(cin, V[i]);
        cout << "Inserisci voto del " << i+1 << " studente: ";
        cin >> voti[i];
        cin.ignore();
        while (voti[i] > 10 || voti[i] < 3) {
            cout << "Hai inserito un valore non valido!" << endl;
            cout << "Inserisci voto del " << i+1 << " studente: ";
            cin >> voti[i];
            cin.ignore();
        }
    }
    ordinaDati(V, voti, size);
}

void leggiVettore(string V[], float voti[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Nome: " << V[i] << endl;
        cout << "Voto dello studente: " << voti[i] << endl;
        cout << endl;
    }
}

float mediaVoti(const float voti[], int size) {
    float mediaTotale = 0;
    for (int i = 0; i < size; i++) {
        mediaTotale += voti[i];
    }
    return mediaTotale/size;
}

string migliorStudente(string studenti[], float voti[], int size) {
    string migliorStudente;
    float maxVoto = 0;
    for (int i = 0; i < size; i++) {
        if (voti[i] > maxVoto) {
            migliorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return migliorStudente;
}

string peggiorStudente(string studenti[], float voti[], int size) {
    string peggiorStudente;
    float maxVoto = 10;
    for (int i = 0; i < size; i++) {
        if (voti[i] < maxVoto) {
            peggiorStudente = studenti[i];
            maxVoto = voti[i];
        }
    }
    return peggiorStudente;
}

void rimuoviStudente(string studenti[], float voti[], int &size) {
    string nomeStudente;
    bool isRemoved = false;
    cout << "Inserisci il nome dello studente da rimuovere: " << endl;
    getline(cin, nomeStudente);
    for(int i=0; i<size; i++) {
        if(nomeStudente == studenti[i]) {
            for(; i<size-1; i++) {
                studenti[i] = studenti[i+1];
                voti[i] = voti[i+1];
            }
            size--;
        }
    }
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
    int scelta, size;
    cout << "Inserisci il numero di studenti: ";
    cin >> size;
    while(size<2) {
        cout << endl << "Hai inserito un valore non valido!" << endl;
        cout << "Inserisci il numero di studenti: ";
        cin >> size;
    }
    const int DIM = 30;
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
            caricaVettore(studenti, voti, size);
            break;

        case 2:
            leggiVettore(studenti, voti, size);
            break;

        case 3:
            cout << endl << "Media dei voti: " << mediaVoti(voti, size);
            break;

        case 4:
            cout << endl << "Miglior studente: " << migliorStudente(studenti, voti, size);
            break;

        case 5:
            cout <<  endl << "Peggior studente: " << peggiorStudente(studenti, voti, size);
            break;
        case 7:
            
        }
    } while (scelta != 0);

    return 0;
}