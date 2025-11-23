#include <iostream>
using namespace std;

int main () {
    int q, p;
    p = 105;
    cout << "Quantity: ";
    cin >> q;
    p -= (q*5);
    if (p < 85) {
        p -= p;
        p += 85;
    }
    cout << "Total: " << (p*q) << "€" << endl;
    return 0;
}