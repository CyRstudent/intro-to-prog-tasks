#include <iostream>
#include <array>
using namespace std;

const int NCOL = 3;
const int NROW = 2;

typedef array<array<int, NCOL>, NROW> TMat;

int main () {
    void printMat(TMat m);
    TMat genMat();
    TMat sumMats(TMat a, TMat b);

    TMat test1 = genMat();
    TMat test2 = genMat();
    TMat res = sumMats(test1, test2);

    printMat(test1);
    cout << endl;
    printMat(test2);
    cout << endl;
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

TMat sumMats(TMat a, TMat b) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            a[i][j] += b[i][j];
        }
    }
    return a;
}