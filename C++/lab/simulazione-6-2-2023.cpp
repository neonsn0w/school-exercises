#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void esercizio1() {
    int sum=0, r;
    do
    {
        r = rand() % 34 + 16;
        cout << r << endl;
        sum += r;
    } while (sum < 15000);
}

void esercizio2(int z) {
    int x=1, y=1;
    while (x<z) {
        while (y<z) {
            if (pow(x, 2) + pow(y, 2) == pow(z, 2)) {
                cout << "terna --> " << x << ", " << y << endl;
            }
            y++;
        }
        y=1;
        x++;
    }
}

bool esercizio3(char VET[], char K) {
    for (int i=0; i<10; i++) {
        if (VET[i] == K) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));

    int z;

    esercizio1();

    cin >> z;
    esercizio2(z);

    char VET[10];
    char K;

    for (int i=0; i<10; i++) {
        cout << "Inserire carattere in posizione " << i << ": ";
        cin >> VET[i];
    }
    cin >> K;

    if (esercizio3(VET, K)) {
        cout << "trovato" << endl;
    } else {
        cout << "non trovato" << endl;
    }

    system("PAUSE");
    return 0;
}
