#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {
    long long res = 1;
    for(int i = 1; i <= n; i++) {
        res*=i;
    }
    return res;
}

int main () {
    int x, y;
    cout << "Introduce 2 numbers: ";
    cin >> x >> y;
    int res = factorial(x)/(factorial(y)*(factorial(x-y)));
    cout << "(" << x << " " << y << ") = " << res << endl;
}