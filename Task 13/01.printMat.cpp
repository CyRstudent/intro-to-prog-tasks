#include <iostream>
#include <array>
using namespace std;

const int NCOL = 4;
const int NROW = 5;

typedef array<array<int, NCOL>, NROW> TMat;

int main () {
    void printMat(TMat m);
    TMat test = {{
        {{1, 2, 3, 4}},
        {{5, 6, 7, 8}},
        {{9, 10, 11, 12}},
        {{13, 14, 15, 16}},
        {{17, 18, 19, 20}}
    }};

    printMat(test);
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