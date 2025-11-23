#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int a, b, c;
    double x1, x2;
    cout << "Introduce the coefficients a b and c for the following equation: a(x^2) + bx + c = 0: ";
    cin >> a >> b >> c;
    int dis = (pow(b, 2) - (4*a*c));
    if ((dis < 0) or (a==0)) {
        cout << "The values you provided make x belong to the complex numbers set or inexistent. Please, try again" << endl;
        return 1;
    }
    x1 = (sqrt(dis) - b)/(2*a);
    x2 = (-(sqrt(dis) + b))/(2*a);
    cout << "The values of x for which the equation " << a <<"(x^2)" << " + " << b << "x + " << c << " is met are: " << x1 << ", " << x2 << endl;
    return 0;
}