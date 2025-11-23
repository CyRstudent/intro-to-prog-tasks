#include <iostream>
using namespace std;

int main () {
    int n, divs;
    divs = 0;
    cout << "Introduce a number: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if((n%i)==0) {
            divs++;
        }
    }
    if (divs == 2) {
        cout << "The number is prime" << endl;
    } else {
        cout << "The number is composite" << endl;
    }
    return 0;
}