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
    void printPoly(TPoly a);
    void addPoly(TPoly& a, TPoly &b);
    void addMono(TPoly& p, TMono m);
    return 0;
}

void printPoly(TPoly a) {
    void sort(TPoly& a);

    sort(a);
    int counter = 0;

    for(int i = a.n - 1; i >= 0; i--) {
        TMono el = a.pol[i];

        if(el.coef != 0) {
            counter++;
            if(counter > 1) {
                cout << " + ";
            }
            cout << el.coef;
            if(el.deg != 0) {
                cout << "x^" << el.deg;
            }
        }
    }
    cout << endl;
}
void addPoly(TPoly& a, TPoly b) {
    void addMono(TPoly& p, TMono m);
    void swapPoly(TPoly& a, TPoly& b);

    if(a.n < b.n) swapPoly(a, b);
    for(int i = 0; i < b.n; i++) {
        addMono(a, b.pol[i]);
    }
}

void addMono(TPoly& p, TMono m) {
    void sort(TPoly& a);
    sort(p);
    p.pol[m.deg].coef += m.coef;
}

// Util
void sort(TPoly& a) {
    void swap(TMono& a, TMono &b);
    for(int i = a.n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a.pol[j].deg > a.pol[j + 1].deg) swap(a.pol[j], a.pol[j+1]);
        }
    }
}

void swap(TMono& a, TMono &b) {
    TMono t = a;
    a = b;
    b = t;
}

void swapPoly(TPoly& a, TPoly& b) {
    TPoly t = a;
    a = b;
    b = t;
}