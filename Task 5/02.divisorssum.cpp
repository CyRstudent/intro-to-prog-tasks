#include <iostream>
using namespace std;

int main () {
    int n;
    int sum = 0;
    cout << "Introduce a number: ";
    cin >> n;
    for (int i = 1; i < n; i++) {
        if(n%i == 0) sum+=i;
    }
    cout << "The sum of the divisors of " << n << " is: " << sum << endl;
    return 0;
}