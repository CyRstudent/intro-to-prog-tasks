#include <iostream>
#include <array>
using namespace std;

const int N = 5;

typedef array<array<int, N>, N> TSqMat;

int main () {
    void printMat(TSqMat m);
    TSqMat genMat();
    TSqMat transpose(TSqMat a);

    TSqMat t1 = genMat();
    printMat(t1);
    cout << endl;
    printMat(transpose(t1));

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

TSqMat transpose(TSqMat a) {
    TSqMat res;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            res[j][i] = a[i][j];
        }
    }
    return res;
}