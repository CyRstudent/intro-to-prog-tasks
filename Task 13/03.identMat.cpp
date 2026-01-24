#include <iostream>
#include <array>
using namespace std;

const int N = 3;

typedef array<array<int, N>, N> TSqMat;

int main () {
    void printMat(TSqMat m);
    TSqMat identSqMat();

    TSqMat res = identSqMat();
    printMat(res);

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