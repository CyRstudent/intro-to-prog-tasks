#include <iostream>
using namespace std;

int main () {
    int first = 0;
    int last = 0;
    int pos = 0;
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    while (n!=0) {
        pos++;
        if (n == 12) {
            if (first == 0) {first += pos;}
            if (pos > last) {
                last -= last;
                last += pos;
            }
        }
    }
    cout << first << ", " << last << endl;
    return 0;
}