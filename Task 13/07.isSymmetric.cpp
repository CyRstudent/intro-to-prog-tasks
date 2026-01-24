#include <iostream>
#include <array>
using namespace std;

const int N = 5;

typedef array<array<int, N>, N> TSqMat;

int main () {
    TSqMat identSqMat();
    TSqMat genMat();
    bool isSymmetric(TSqMat m);

    TSqMat t1 = genMat();
    cout << isSymmetric(t1) << " " << isSymmetric(identSqMat()) << endl;
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

bool isSymmetric(TSqMat m) {
    TSqMat transpose(TSqMat a);
    return (m == transpose(m));
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

