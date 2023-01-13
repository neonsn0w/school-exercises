#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    
    int a, b, r;
    
    cout << "inserisci a = ";
    cin >> a;
    while (a<=0){
        cout << endl << "ATTENZIONE!\n";
        cout << "inserisci a = ";
        cin >> a;
    }
    
    
    cout << "inserisci b = ";
    cin >> b;
    while (b<=0){
        cout << endl << "ATTENZIONE!\n";
        cout << "inserisci b = ";
        cin >> b;
    }
    int aa = a, bb = b;
    if (a==b){
        cout << "L'MCD tra " << a << " e " << b << " e': " << a;
    } else {
        r = a % b;
        while (r != 0) {
                a = b;
                b = r;
                r = a % b;
        }
        cout << "L'MCD tra " << aa << " e " << bb << " e': " << b;
    }
    cout << endl;
    //system("pause");
return 0;
}
