#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int a, b, t, d=2;
    bool looper = true;

    cout << "Inserisci a: ";
    cin >> a;
    cout << "Inserisci b: ";
    cin >> b;

    if (b>a) {
        t = a;
        while (t<b){
            t++;
            cout << t << endl;
        }
    } else {
        while (d<a && looper) {
            if (a%d==0 && b%d==0) {
                looper = false;
            } else {
                d++;
            }
        }
        if (looper) {
            cout << "Il divisore comune e': 1" << endl;
        } else {
            cout << "Il divisore comune e': " << d << endl;
        }
        
    }

    //system("pause");
    return 0;
}
