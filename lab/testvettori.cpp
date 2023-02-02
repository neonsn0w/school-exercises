#include <iostream>
#include <cstdlib>

using namespace std;

int getMax(int v[], int DIM) {
    // Function that returns the maximum value of the array
    int min = v[0];
    for (int i=1; i<DIM; i++) {
        if (v[i] > min) {
            min = v[i];
        }
    }
    return min;
}

int getMin(int v[], int DIM) {
    // Function that returns the maximum value of the array
    int min = v[0];
    for (int i=1; i<DIM; i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min;
}

int getSum(int v[], int DIM) {
    // Function that returns the sum of the elements of the array
    int sum = 0;
    for (int i=0; i<DIM; i++) {
        sum = sum + v[i];
    }
    return sum;
}

double getAvg(int v[], int DIM) {
    // Function that returns the average of the elements of the array
    int sum = getSum(v, DIM);
    return sum/DIM;
}

int main() {

    //Array dimension acquisition
    cout << "Enter array dimension: ";
    int DIM;
    cin >> DIM;

    //Array declaration
    int v[DIM];

    //Variable declaration
    int max, min, sum;
    double avg;

    //Array filling
    for (int i=0; i<DIM; i++) {
        cout << "Enter value for v[" << i << "]: ";
        cin >> v[i];
    }

    cout << endl;

    //Array printing
    for(int i=0; i<DIM; i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    //Array search
    min = getMin(v, DIM);
    max = getMax(v, DIM);
    sum = getSum(v, DIM);
    avg = getAvg(v, DIM);

    //Results printing
    cout << endl;
    cout << "Min = " << min << endl;
    cout << "Max = " << max << endl;
    cout << "Sum = " << sum << endl;
    cout << "Avg = " << avg << endl;


}