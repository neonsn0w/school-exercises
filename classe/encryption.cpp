#include <iostream>
#include <string>

using namespace std;

void encryptString(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'w' || s[i] >= 'A' && s[i] <= 'W') {
            s[i] = s[i] + 3;
        }
        else if (s[i] >= 'x' && s[i] <= 'z' || s[i] >= 'X' && s[i] <= 'Z') {
            s[i] = s[i] - 23;
        }
    }
}

void decryptString(string &s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'd' && s[i] <= 'z' || s[i] >= 'D' && s[i] <= 'Z') {
            s[i] = s[i] - 3;
        }
        else if (s[i] >= 'a' && s[i] <= 'c' || s[i] >= 'A' && s[i] <= 'C') {
            s[i] = s[i] + 23;
        }
    }
}

int main() {
    string s = "";
    int sel;
    getline(cin, s);

    cout << endl << "1. encrypt";
    cout << endl << "2. decrypt";

    cin >> sel;

    switch (sel) {
        case 1:
            encryptString(s);
            cout << endl << "stringa criptata = " << s;
            break;

        case 2:
            decryptString(s);
            cout << endl << "stringa decriptata = " << s;
            break;
    }

    return 0;
}