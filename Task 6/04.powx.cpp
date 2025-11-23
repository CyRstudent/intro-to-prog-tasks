#include <iostream>
using namespace std;

int main () {
    float powx(float x, int n);
    float a;
    int b;
    cout << "Introduce a real number and the exponent: ";
    cin >> a >> b;
    cout << a << "^" << b << " = " << powx(a, b) << endl;
    return 0;
}

float powx(float x, int n) {
    float res = 1;
    int absval = n;
    if(n < 0) absval*=-1;
    for (int i = 0; i < absval; i++) res*=x;
    if (n < 0) return (1/res);
    return res;
}