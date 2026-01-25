#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<array<int, N>, N> TSqMat;

int main () {
    void printMat(TSqMat m);
    TSqMat getMat(int p);
    void clockwise(TSqMat &m);

    TSqMat a = getMat(0);
    printMat(a);
    cout << endl;
    clockwise(a);
    printMat(a);
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

TSqMat getMat(int p) {
    TSqMat res;
    static int c = p;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            c++;
            res[i][j] = c;
        }
    }
    return res;
}

void clockwise(TSqMat &m) {
    void transpose(TSqMat &m);
    
    transpose(m);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < (N/2); j++) {
            int temp = m[i][j];
            m[i][j] = m[i][N - (j + 1)];
            m[i][N - (j + 1)] = temp;
        }
    }
}

void transpose(TSqMat &m) {
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

