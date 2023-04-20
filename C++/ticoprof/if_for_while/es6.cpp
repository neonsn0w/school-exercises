#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int last = 11, current = 12, counter = 0, next = 0;

    srand(time(NULL));

    while (current != last) {
        counter++;
        last = current;
        current = rand() % 11;
        cout << current << " ";
        if (current == last+1) {
            next++;
        }
    }
    cout << endl << "numeri pescati in totale: " << counter << endl;
    cout << "numeri pescati in successione: " << next << endl;
    
}