#include <iostream>
#include <ctime>

using namespace std;

int esercizio1(int M) {
    int x=1, sum=0;
    while (x<=M)
    {
        if (x==5) {}
        else if (((x*x)/(x-5))>10) {
            sum = sum + x;
        }
        x++;
    }
    return sum;
}

int esercizio2() {
    float m;
    srand(time(NULL));
    m = rand() % 21 + 10;
    while (m<=20) {
        int x = rand() % 21 + 10;
        m = (m+x)/2;
    }
    return m;
}

int esercizio3(int K) {
    int i=1, j=1, cpari=0;
    while (i<K) {
        while (j<=K) {
            if ((i*j)%2 == 0) {
                cpari++;
            }
            j++;
        }
        i++;
        j=1;
    }
    return cpari;
}

int main() {
    int outes1, ines1, outes2, outes3, ines3;

    cout << "inserire valore per la prima funzione = ";
    cin >> ines1;
    outes1 = esercizio1(ines1);
    cout << outes1 << endl << endl;

    outes2 = esercizio2();
    cout << outes2 << endl << endl;

    cout << "inserire valore per la terza funzione = ";
    cin >> ines3;
    outes3 = esercizio3(ines3);
    cout << outes3 << endl;
    
    return 0;
}