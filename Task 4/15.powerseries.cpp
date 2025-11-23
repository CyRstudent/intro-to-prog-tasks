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
    double s = 0;
    double x;
    cout << "Introduce a real number: ";
    cin >> x;
    for (int i = 0; i <= 10; i++) {
        s += (pow(x, i))/(factorial(i));
    }
    cout << "The result of the series is: " << s << endl;
    return 0;
}