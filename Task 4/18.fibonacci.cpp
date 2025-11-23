#include <iostream>
using namespace std;

int main () {
    long long f, fb1, ff, n;
    f = 0;
    fb1 = 1;
    cout << "Introduce a number: ";
    cin >> n;
    for (int i = 2; i <= n; i++) {
        ff = f + fb1;
        f = fb1;
        fb1 = ff;
    }
    cout << "The term No. " << n << " of the fibonacci series is: " << fb1 << endl;
}