#include <iostream>
#include <array>
using namespace std;

const int N = 100;

typedef array<double, N> TPoly;

int main () {
    void printPoly(TPoly a);
    void addMono(TPoly& p, int degree, float coef);
    void addPoly(TPoly& a, TPoly b);
    return 0;
}

void printPoly(TPoly a) {
    int counter = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(a[i] != 0) {
            counter++;
            if(counter > 1) {
                cout << " + ";
            }
            cout << a[i];
            if(i != 0) {
                cout << "x^" << i;
            }
        }
    }
    cout << endl;
}

void addMono(TPoly& p, int degree, float coef) {
    p[degree] += coef;
}

void addPoly(TPoly& a, TPoly b) {
    for(int i = 0; i < N; i++) {
        a[i] += b[i];
    }
}