#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NCOL = 3;
const int NROW = 2;
const int RANDMAX = 100;

typedef array<array<int, NCOL>, NROW> TMat;

int main () {
    void printMat(TMat m);
    void fillRandMat(TMat& m);

    srand(time(0));
    TMat res;
    fillRandMat(res);
    printMat(res);

    return 0;
}

void printMat(TMat m) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void fillRandMat(TMat& m) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            m[i][j] = rand();
        }
    }
}