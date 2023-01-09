#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
    double prezzo, banconota, resto, q500=0, q200=0, q100=0, q50=0, q20=0, q10=0, q5=0, q2=0, q1 = 0;
    bool loopbreaker = true;
    do {
        cout << endl << "prezzo =  ";
        cin >> prezzo;
    } while (prezzo <= 0);
    do {
        cout << endl << "banconota = ";
        cin >> banconota;
    // YANDEREDEV MOMENT
    } while (banconota != 1 & banconota != 2 & banconota != 5 & banconota != 10 & banconota != 20 & banconota != 50 & banconota != 100 & banconota != 200 & banconota != 500);
    if (prezzo<50) {
        resto = banconota - prezzo;
        cout << "il resto è = " << resto << endl;
    } else if (prezzo<100) {
        prezzo = prezzo / 100 * 97;
        resto = banconota - prezzo;
        cout << "il resto è = " << resto << endl;
    } else if (prezzo<500) {
        prezzo = prezzo / 100 * 96;
        resto = banconota - prezzo;
        cout << "il resto è = " << resto << endl;
    } else {
        prezzo = prezzo / 100 * 94;
        resto = banconota - prezzo;
        cout << "il resto è = " << resto << endl;
    }

    // while yes, it is me, Yandere Dev

    while (loopbreaker == true)
    {
        if (resto >= 500)
        {
            resto = resto - 500;
            q500++;
        }
        else if (resto >= 200)
        {
            resto = resto - 200;
            q200++;
        }
        else if (resto >= 100)
        {
            resto = resto - 100;
            q100++;
        }
        else if (resto >= 50)
        {
            resto = resto - 50;
            q50++;
        }
        else if (resto >= 20)
        {
            resto = resto - 20;
            q20++;
        }
        else if (resto >= 10)
        {
            resto = resto - 10;
            q10++;
        }
        else if (resto >= 5)
        {
            resto = resto - 5;
            q5++;
        }
        else if (resto >= 2)
        {
            resto = resto - 2;
            q2++;
        }
        else if (resto >= 1)
        {
            resto = resto - 1;
            q1++;
        }
        else {
            loopbreaker = false;
        }
    }

    cout << "banconote da 500 = " << q500 << endl;
    cout << "banconote da 200 = " << q200 << endl;
    cout << "banconote da 100 = " << q100 << endl;
    cout << "banconote da 50 = " << q50 << endl;
    cout << "banconote da 20 = " << q20 << endl;
    cout << "banconote da 10 = " << q10 << endl;
    cout << "banconote da 5 = " << q5 << endl;
    cout << "banconote da 2 = " << q2 << endl;
    cout << "banconote da 1 = " << q1 << endl;
}
