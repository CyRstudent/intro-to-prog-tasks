#include <iostream>
#include <array>
using namespace std;

const int NCOL = 3;
const int NROW = 2;


typedef array<array<int, NCOL>, NROW> TMat;

int main () {
    void printMat(TMat m);
    TMat genMat();

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

TMat genMat() {
    TMat res;
    static int c = 0;
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            c++;
            res[i][j] = c;
        }
    }
    return res;
}