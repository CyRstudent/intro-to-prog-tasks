#include <iostream>
using namespace std;

int main () {
    int n, sum, greatest, lowest;
    sum = 0;
    greatest = 0;
    lowest = 0;

    cout << "Introduce the number \"N\": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cout << "Introduce a number: ";
        cin >> k;
        sum += k;
        if (k > greatest) {
            greatest -= greatest;
            greatest += k;
        }
        if (k < lowest) {
            lowest -= lowest;
            lowest += k;
        }
    }
    int avg = (float)sum/n + 0.5;
    cout << "The largest number in the sequence is: " << greatest << endl;
    cout << "The lowest number in the sequence is: " << lowest << endl;
    cout << "The average of the sequence is: " << avg << endl;
    return 0;
}