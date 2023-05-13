#include <iostream>

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

// Struct tpiloti
struct tpiloti {
    char nome[69];
    char scuderia[69];
    int punti;
};

// Funzione per stampare il menu
int menu() {
    int scelta;
    cout << endl << "1. Inserisci un pilota" << endl;
    cout << "2. Inserisci un circuito" << endl;
    cout << "3. Visualizza la lista dei piloti" << endl;
    cout << "4. Visualizza la lista dei circuiti" << endl;
    cout << "5. Visualizza i piloti di una scuderia" << endl;
    cout << "6. Inserisci i tempi di arrivo dei piloti" << endl;
    cout << "7. Visualizza i tempi di arrivo dei piloti" << endl;
    cout << "8. Visualizza in quali gare ha vinto un pilota" << endl;
    cout << endl << "0. Esci" << endl;

    cout << endl << "Inserisci scelta: ";

    cin >> scelta;
    return scelta;
}

// Funzione per inserire un libro
void inserisciPilota(tpiloti piloti[], int &nPiloti) {
    cout << "Inserisci il nome del pilota: ";
    cin >> piloti[nPiloti].nome;
    cout << "Inserisci la scuderia del pilota: ";
    cin >> piloti[nPiloti].scuderia;
    cout << "Inserisci il punteggio del pilota: ";
    cin >> piloti[nPiloti].punti;
    nPiloti++;
}

// Funzione per inserire un circuito
void inserisciCircuito(string circuiti[], int &nCircuiti) {
    cout << "Inserisci il nome del circuito: ";
    cin.ignore();
    getline(cin, circuiti[nCircuiti]);
    nCircuiti++;
}

// Funzione che elenca i piloti
void elencoPiloti(tpiloti piloti[], int nPiloti) {
    for (int i = 0; i < nPiloti; i++) {
        cout << piloti[i].nome << endl;
        cout << piloti[i].scuderia << endl;
        cout << piloti[i].punti << endl << endl;
    }
}

// Funzione che elenca i circuiti
void elencoCircuiti(string circuiti[], int nCircuiti) {
    for (int i = 0; i < nCircuiti; i++) {
        cout << circuiti[i] << endl;
    }
}

// Funzione che elenca i piloti di una scuderia
void elencaPilotiScuderia(tpiloti piloti[], int nPiloti) {
    char scuderia[69];
    cout << "Inserisci il nome della scuderia: ";
    cin >> scuderia;
    for (int i = 0; i < nPiloti; i++) {
        if (piloti[i].scuderia == scuderia) {
            cout << piloti[i].nome << endl;
            cout << piloti[i].punti << endl << endl;
        }
    }
}

// Funzione che inserisce i tempi di arrivo dei piloti
void inserisciArrivi(tpiloti piloti[], int nPiloti, string circuiti[], int nCircuiti, int arrivi[][10]) {
    for(int i=0; i<nPiloti; i++) {
        for(int j=0; j<nCircuiti; j++) {
            cout << "Inserisci il tempo di arrivo di " << piloti[i].nome << " al circuito " << circuiti[j] << ": ";
            cin >> arrivi[i][j];
        }
    }
}

// Funzione per visualizzare i tempi di arrivo dei piloti
void visualizzaArrivi(tpiloti piloti[], int nPiloti, string circuiti[], int nCircuiti, int arrivi[][10]) {
    for(int i=0; i<nPiloti; i++) {
        for(int j=0; j<nCircuiti; j++) {
            cout << "Il pilota " << piloti[i].nome << " ha fatto il tempo di " << arrivi[i][j] << " al circuito " << circuiti[j] << endl;
        }
    }
}

// Funzione che cerca un pilota dato il nome
int cercaPilota(tpiloti piloti[], int nPiloti, char nome[]) {
    for(int i=0; i<nPiloti; i++) {
        if(piloti[i].nome == nome) {
            return i;
        }
    }
    return -1;
}

// Funzione che ritorna le gare in cui un dato pilato ha vinto
void vittoriaPilota(tpiloti piloti[], int n, int arrivi[][10], string circuiti[], int nCircuiti) {
    if (n==-1) {
        cout << "Nome non valido" << endl;
    } else {
        for(int i=0; i<nCircuiti; i++) {
            if(arrivi[n][i]==1) {
                cout << "Il pilota " << piloti[n].nome << " ha vinto la gara nel circuito " << nCircuiti;
            }
        }
    }
}

int main() {
    tpiloti piloti[20];
    string circuiti[10];
    int arrivi[20][10];
    int scelta, nPiloti = 0, nCircuiti = 0;



    do {
        clear();
        scelta = menu();
        switch (scelta) {
            case 1:
                clear();
                inserisciPilota(piloti, nPiloti);
                break;
            case 2:
                clear();
                inserisciCircuito(circuiti, nCircuiti);
                break;
            case 3:
                clear();
                elencoPiloti(piloti, nPiloti);
                pause();
                break;
            case 4:
                clear();
                elencoCircuiti(circuiti, nCircuiti);
                pause();
                break;
            case 5:
                clear();
                elencaPilotiScuderia(piloti, nPiloti);
                pause();
                break;
            case 6:
                clear();
                inserisciArrivi(piloti, nPiloti, circuiti, nCircuiti, arrivi);
                break;
            case 7:
                clear();
                visualizzaArrivi(piloti, nPiloti, circuiti, nCircuiti, arrivi);
                pause();
                break;
            case 8:
                clear();
                char nome[69];
                cout << "Inserisci il nome del pilota: ";
                cin >> nome;
                vittoriaPilota(piloti, cercaPilota(piloti, nPiloti, nome), arrivi, circuiti, nCircuiti);
                pause();
                break;
        }
    } while (scelta != 0);

    return 0;
}