#include <iostream>
#include <array>
using namespace std;

const int N = 3;

struct TMono {
    float coef;
    int deg;
};

typedef array<TMono, N> TPoly;

int main () {

    return 0;
}

TPoly add(TPoly p, TMono m) {
    int findDegPos(TPoly p, int deg);
    int nextZero_pos(TPoly p);

    int degPos = findDegPos(p, m.deg);
    if(degPos == -1) {
        int newPos = nextZero_pos(p);
        p[newPos].coef = m.coef;
        p[newPos].deg = m.deg;
    } else {
        p[degPos].coef += m.coef;
    }

    return p;
}

TPoly derivative(TPoly p) {
    TPoly initialize();

    TPoly res = initialize(); // New, empty polinomial
    for(int i = 0; i < N; i++) {
        if((p[i].coef == 0) or (p[i].deg == 0)) { // If we try to derive a constant or an empty monomial, the result is going to be zero;
            res[i] = {0, 0};
        } else { // (x^n)' = (nx)^(n-1);
            res[i].deg = p[i].deg - 1;
            res[i].coef = ((float)p[i].deg * p[i].coef);
        }
    }
    return res;
}

int findDegPos(TPoly p, int deg) {
    /**
     * Finds the position of the matching degree
     * Returns a positive int if a position was found, returns -1 in case no position was found
     */
    int i = 0;
    while((i < N - 1) and ((p[i].deg != deg) or (p[i].coef == 0))) i++;
    if((p[i].deg != deg) or (p[i].coef == 0)) i = -1;

    return i;
}

int nextZero_pos(TPoly p) {
    /**
     * Finds the position where there is a free slot to allocate memory
     * Returns a positive int if there is still space in the array, returns -1 if the array is full
     */
    int i = 0;
    while((i < N - 1) and ((p[i].coef == 0) and (p[i].deg == 0))) i++;
    if(not ((p[i].coef == 0) and (p[i].deg == 0))) i = -1;

    return i;

}
TPoly initialize() {
    TPoly res;
    TMono empty = {0, 0};
    for(int i = 0; i < N; i++) {
        res[i] = empty;
    }
    return res;
}

void printPoli(TPoly p) {
    for(int i = 0; i < N; i++) {
        float co = p[i].coef;
        float deg = p[i].deg;
    }
}