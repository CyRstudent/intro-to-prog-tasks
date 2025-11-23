#include <iostream>
using namespace std;

int main () {
    int n;
    int backn = 0;
    cout << "Introduce a number: ";
    cin >> n;
    while (n>0) {
        int digit = n%10;
        backn = 10*backn + digit;
        n/=10;
    }
    cout << backn << endl;
    return 0;
}