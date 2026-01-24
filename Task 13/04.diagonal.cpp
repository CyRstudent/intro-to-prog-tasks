#include <iostream>
#include <array>
using namespace std;

const int N = 3;

typedef array<array<int, N>, N> TSqMat;

int main () {
    void printMat(TSqMat m);
    TSqMat identSqMat();
    bool isDiagonal(TSqMat m);

    TSqMat identity = identSqMat();
    TSqMat test = {{
        {{1, 2, 3}},
        {{4, 5, 6}},
        {{7, 8, 9}}
    }};
    
    printMat(identity);
    cout << isDiagonal(identity) << endl;
    printMat(test);
    cout << isDiagonal(test) << endl;

    return 0;
}

void printMat(TSqMat m) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

bool isDiagonal(TSqMat m) {
    bool correctElement(TSqMat m, int i, int j);
    int i = 0;
    bool isCorrect = true;
    while((i < N - 1) and isCorrect) {
        int j = 0;
        while((j < N - 1) and isCorrect) {
            isCorrect = correctElement(m, i, j);
            j++;
        }
        i++;
    }
    return isCorrect;
}

bool correctElement(TSqMat m, int i, int j) {
    bool s;
    if(i == j) s = (m[i][j] != 0);
    else s = (m[i][j] == 0);
    return s;
}
