#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int contaChar(string s) {
    int dim = 0;
    while (s[dim++] != '\0');
    return dim;
}

int contaVocali(string s, int dim) {
    int nvocali = 0;
    for (int i = 0; i < dim-1; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            nvocali++;
        }
    }
    return nvocali;
}

string inserisciStringa(string s1, string s2, int dim1, int dim2, int pos) {
    string s3 = s1;
    char tempchar = 'G';

    for(int i=dim1; i<dim2+dim1-1; i++) {
        s3 = s3 + tempchar;
    }

    for(int i=pos; i<pos+dim2-1; i++) {
        s3[i+dim2-1] = s3[i];
    }

    for(int i=0; i<dim2-1; i++) {
        s3[i+pos] = s2[i];
    }

    return s3;
}

int main() {
    string s1, s2;
    int pos;

    cout << "Inserisci una stringa: ";    
    getline(cin, s1);

    int dim1 = contaChar(s1);
    cout << "La stringa inserita ha " << dim1+1 << " caratteri" << endl;

    int nvocali = contaVocali(s1, dim1);

    cout << "La stringa inserita ha " << nvocali << " vocali" << endl;

    cout << "Inserisci un'altra stringa: ";
    getline(cin, s2);
    cout << "Digitare la posizione in cui inserire la seconda stringa: ";
    cin >> pos;

    int dim2 = contaChar(s2);

    string s3 = inserisciStringa(s1, s2, dim1, dim2, pos);
    cout << "Il risultato è " << s3;

    return 0;
}