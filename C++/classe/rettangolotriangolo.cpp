#include <iostream>
#include <cmath>

using namespace std;

int inserimento(){
    int n;
    cin >> n;
    while (n<=0) {
        cout << "Inserire un numero positivo!!! = ";
        cin >> n;
    }
    return n;
}

int prett(int x, int y) {
    int p;
    p = (x+y)*2;
    return p;
}

int arett(int x, int y) {
    int a;
    a = x*y;
    return a;
}

int ptri(int x, int y) {
    int p;
    p = x+y+sqrt(x^2+y^2);
    return p;
}

int atri(int x, int y) {
    int a;
    a = x*y/2;
    return a;
}

int main() {
    int d1, d2, p, a;
    char in;

    cout << "inserire il primo numero = ";
    d1 = inserimento();

    cout << "inserire il secondo numero = ";
    d2 = inserimento();

    cout << "selezionare un opzione (t, r) = ";
    cin >> in;

    if (in == 'r'){
        p = prett(d1, d2);
        cout << "il perimetro del rettangolo e' = " << p << endl;
        a = arett(d1, d2);
        cout << "l'area del rettangolo e' = " << a << endl;
    } else if (in == 't'){
        p = ptri(d1, d2);
        cout << "il perimetro del triangolo e' = " << p << endl;
        a = atri(d1, d2);
        cout << "l'area del triangolo e' = " << a << endl;
    } else {
        cout << "carattere non valido";
    }
    return 0;
}
