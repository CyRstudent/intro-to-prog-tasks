#include <iostream>
#include <array>
using namespace std;

const int N = 100;

typedef array<double, N> TPoly;

int main () {
    float evalPoly(TPoly p, double x);
    return 0;
}

float evalPoly(TPoly p, double x) {
    double pow(double a, int n);

    double res = 0;
    for(int i = 0; i < N; i++) {
        double d = pow(x, i);
        res += (p[i]*d);
    }
    return res;
}

double pow(double a, int n) {
    double res = 1;
    for(int i = 0; i < n; i++) res *= a;
    return res;
}