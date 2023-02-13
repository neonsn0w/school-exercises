#include <iostream>

using namespace std;

int MassimoDivisoreComune(int n) {
    int i=n;
    bool primo;
    do {
        primo=true;
        for(int ii=2;ii<=i/2;ii++) {
            if(i%ii==0) {
                primo=false;
            }
        }
        i--;
    } while(n%(i+1)!=0||!primo);
    return i+1;
}

int main() {
    const int DIM = 5;
    int v[DIM], mdc[DIM];
    for (int i=0; i<DIM; i++) {
        cout << endl << "Inserire il numero in posizione " << i << " = ";
        cin >> v[i];
    }
    for (int i=0; i<DIM; i++) {
        mdc[i] = MassimoDivisoreComune(v[i]);
    }
    int max = mdc[0];
    for (int i=1; i<DIM; i++) {
        if (mdc[i]>max) {
            max = mdc[i];
        }
    }
    cout << "Il divisore primo più grande è " << max;
}