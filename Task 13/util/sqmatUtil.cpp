#include <iostream>
#include <array>
using namespace std;

const int N = 3;

typedef array<array<int, N>, N> TSqMat;

int main () {
    void printMat(TSqMat m);
    TSqMat identSqMat();
    TSqMat genMat();
    return 0;
}

void printMat(TSqMat m) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

TSqMat identSqMat() {
    TSqMat res;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res[i][j] = ((i == j)?1:0);
        }
    }
    return res;
}

TSqMat genMat() {
    TSqMat res;
    static int c = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            c++;
            res[i][j] = c;
        }
    }
    return res;
}