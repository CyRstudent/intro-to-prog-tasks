#include <iostream>
#include <array>
using namespace std;

const int N = 100;

struct TMono {
    float coef;
    int deg;
};

typedef array<TMono, N> TVec;

struct TPoly {
    int n; // Number of monomials inside the array
    TVec pol;
};

int main () {
    float evalPoly(TPoly p, float x);
}

float evalPoly(TPoly p, float x) {
    float pow(float a, int n);
    float res = 0;
    for(int i = 0; i < p.n; i++) {
        TMono m = p.pol[i];
        float d = pow(x, m.deg);
        res += (d*m.coef);
    }
    return res;
}

float pow(float a, int n) {
    float res = 1;
    for(int i = 0; i < n; i++) res *= a;
    return res;
}