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
    const double epsilon = 0.000001;
    cout << "Introduce a real number: ";
    cin >> x;
    int i = 0;
    double res = (pow(x, i)/factorial(i));
    while (res >= epsilon) {
        s += res;
        i++;
        res = (pow(x, i)/factorial(i));
    }
    cout << "The result of the series is: " << s << endl;
    return 0;
}