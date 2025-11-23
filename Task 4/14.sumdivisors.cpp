#include <iostream>
using namespace std;

int main () {
    int n;
    int sum = 0;
    cout << "Introduce a number: ";
    cin >> n;
    for (int i = 1; i < n; i++) {
        if ((n%i) == 0) {
            sum += i;
        }
    }
    if (sum == n) {
        cout << "The number is perfect";
    } else {
        cout << "The sum of all the divisors of " << n << " is: " << sum;
    }
    cout << endl;
    return 0;
}