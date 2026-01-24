#include <iostream>
#include <array>
using namespace std;

const int NCOL = 3;
const int NROW = 5;

typedef array<int, NCOL> TRow;
typedef array<TRow, NROW> TMat;

int main () {
    void printMat(TMat m);
    TMat genMat();
    void swapRows(TMat& m, int r1, int r2);

    TMat t = genMat();
    swapRows(t, 0, 2);
    printMat(t);
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

void swapRows(TMat& m, int r1, int r2) {
    TRow temp = m[r1];
    m[r1] = m[r2];
    m[r2] = temp;
}