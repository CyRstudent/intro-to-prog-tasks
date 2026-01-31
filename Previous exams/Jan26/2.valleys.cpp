/*
Sáez Madrid, Hugo
Software Engineering
PC0626
*/

#include <iostream>
#include <array>
using namespace std;

const int NROW = 3;
const int NCOL = 4;

typedef array<array<int, NCOL>, NROW> TMat;
typedef array<int, 2> TPos;

int main () {
    cout << "Hugo Saez Madrid" << endl;

    void printValleys(TMat a);

    printValleys(TMat{{
        {{4, 5, 3, 6}},
        {{6, 2, 2, 7}},
        {{1, 8, 7, 9}}
    }});
    cout << endl;

    printValleys(TMat{{
        {{1, 2, 3, 4}},
        {{5, 6, 7, 8}},
        {{9, 10, 11, 12}}
    }});
    cout << endl;

    printValleys(TMat{{
        {{4, 4, 4, 4}},
        {{4, 4, 4, 4}},
        {{4, 4, 4, 4}}
    }});

    return 0;
}

void printValleys(TMat a) {
    void printMat(TMat a);
    bool isValley(TMat a, TPos c);

    printMat(a);
    cout << endl;

    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            if(isValley(a, (TPos){{i, j}})) {
                cout << "Cell at row " << i << ", column " << j << ", with value " << a[i][j] << " is a valley" << endl;
            }
        }
    }
}
void printMat(TMat a) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

bool isValley(TMat a, TPos c) {
    bool outOfBounds(TPos c);

    int i = -1;
    bool found = false; // Whether we found a cell that is higher than the selected cell

    while((i <= 1) and (not found)) {
        int j = -1;
        while((j <= 1) and (not found)) {
            TPos s = {{
                (c[0] + i),
                (c[1] + j)
            }};
            if(not outOfBounds(s)) {
                found = (a[c[0]][c[1]] > a[s[0]][s[1]]);
            }
            if(not found) j++;
        }
        if(not found) i++;
    }
    return (not found);
}

bool outOfBounds(TPos c) {
    // Returns whether the selected cell is outside of the boundaries
    bool s1 = (c[0] >= NROW);
    bool s2 = (c[1] >= NCOL);
    bool s3 = (c[0] < 0);
    bool s4 = (c[1] < 0);

    return (s1 or s2 or s3 or s4);
}
