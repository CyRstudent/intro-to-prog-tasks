// Sáez Madrid, Hugo
// Software Engineering, Group B
// PC-XXXX

// Time: 23min 44 sec
#include <iostream>
#include <array>
using namespace std;

const int N = 5;

typedef array<array<int, N>, N> TMat;

int main () {
    // Subprograms
    void printMat(TMat m);
    void addMatVal(TMat &m, int n);
    int indCol(TMat m);
    double diagAvg(TMat m);

    // We declare the matrix and we fill it with the values 
    TMat m;
    for(int i = 0; i < N; i++) {
        int n = 0;
        cout << "Introduce the values of row " << (i + 1) << " (" << N << " values needed): ";
        for(int j = 0; j < N; j++) {
            cin >> n;
            addMatVal(m, n);
        }
    }
    
    // Now, we print the matrix
    cout << endl << "The matrix is: " << endl;
    printMat(m);
    cout << endl;

    // We calculate the average of the diagonal
    cout << "Average of the diagonal of the matrix: " << diagAvg(m) << endl;
    int ind = indCol(m);

    // As we explained in the function, if the function returns -1 it's because it did not find the 
    if(ind == -1) {
        cout << "There is no column in the matrix which meets the condition";
    } else {
        cout << "Index of the first column which meets the condition: " << ind;
    }
    cout << endl;

    return 0;
}

void printMat(TMat m) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void addMatVal(TMat &m, int n) {
    static int c = 0; // This counter helps us to locate which cell we're at
    int i = (c/N);
    int j = (c%N);
    m[i][j] = n;
    c++;
}

int indCol(TMat m) {
    /**
     * Returns the index of the first column whose average is greater or equal than the average of the diagonalç
     * Returns -1 if no index was found
     */
    double diagAvg(TMat m);
    
    double dAvg = diagAvg(m);
    int j = 0;
    bool found = false;
    while((j < N) and (not found)) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += m[i][j];
        }
        double avg = ((double)sum/N);
        found = (avg >= dAvg);
        if(not found) j++;
    }

    if(not found) j = -1;

    return j;
}

double diagAvg(TMat m) {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += m[i][i];
    }
    return ((double)sum/N);
}