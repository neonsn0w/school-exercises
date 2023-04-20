#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int dim, vavg = 0, dimm;

    //getting the number of temperatures
    cout << "Inserisci la quantità di temperature con cui lavorare: " ;
    cin >> dim;

    int t[dim];
    int tt[dim-1];

    //getting temperatures
    for (int i = 0; i < dim; i++) {
        cout << "Inserisci la temperatura in posizione " << i << ": " ;
        cin >> t[i];
    }
    
    //calculating the temperature variations
    for (int i = 0; i < dim-1; i++) {
        tt[i] = abs(t[i] - t[i+1]);
        vavg =+ tt[i];
    }
    vavg = vavg / dim--;

    //printing the temperature variations
    cout << "La variazione di temperatura tra la posizione è di " << vavg << " gradi." << endl;

    system("pause");
    return 0;
}