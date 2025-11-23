#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    int i = 1;
    while ((i < n) and ((i*i) != n)) {
        i++;
    }
    if ((i*i) == n) {
        cout << "The number " << n << " has a perfect square" << endl;
    } else {
        cout << "The number " << n << " doesn't have a perfect square" << endl;
    }
    return 0;
}