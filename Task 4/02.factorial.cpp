#include <iostream>
using namespace std;

int main () {
    long long res = 1;
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    int i = 1;
    while (i <= n) {
        res *= i;
        i++;
    }
    cout << n << "! = " << res << endl;
    return 0;
}