#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n;
    cout << "Introduce an integer: ";
    cin >> n;
    if (n == 0) {
        cout << "1" << endl;
        return 0;
    }
    n = (int)log10(n);
    n++;
    cout << n << endl;
    return 0;
}