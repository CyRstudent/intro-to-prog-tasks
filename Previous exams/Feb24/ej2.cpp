/**
 * Sáez Madrid, Hugo
 * Software Engineering, Group B
 * PCXXXX
 */

// Time: 40min 49sec
#include <iostream>
#include <array>
using namespace std;

const int NROW = 4;
const int NCOL = 3;

typedef array<array<int, NCOL>, NROW> TMat;
typedef array<int, 2> TPos; // i j

int main () {
    void addCell(TMat &a, int n);
    void printMat(TMat a);
    TPos cellPos(TMat a);

    cout << "Sáez Madrid, Hugo" << endl;

    TMat a;

    for(int i = 0; i < NROW; i++) {
        cout << "Start introducing the numbers of row " << (i + 1) <<": ";
        int n;
        for(int j = 0; j < NCOL; j++) {
            cin >> n;
            cout << n;
            addCell(a, n);
        }
    }
    cout << endl << "The introduced matrix is: " << endl;
    printMat(a);
    cout << endl;

    TPos res = cellPos(a);
    if(res[0] == -1) {
        cout << "No cell was found that meets the condition";
    } else {
        cout << "The first cell that meets the condition is found at: (" << res[0] << ", " << res[1] << ")";
    }

    cout << endl;

    return 0;
}

void addCell(TMat &a, int n) {
    static int c = 0;

    int i = (c/NCOL);
    int j = (c%NCOL);

    a[i][j] = n;

    c++;
}

void printMat(TMat a) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

TPos cellPos(TMat a) {
    int sumAdjacentCells(TPos cell, TMat a);

    int i = 0;
    int j = 0;
    bool found = false;
    TPos cell;

    while((i < NROW) and (not found)) {
        j = 0;
        while((j < NCOL) and (not found)) {
            cell = {{i, j}};
            int sum = sumAdjacentCells(cell, a);
            found = (sum == a[i][j]);

            if(not found) j++;
        }
        if(not found) i++;
    }
    if(not found) cell = {{-1, -1}};
    else cell = {{i, j}};

    return cell;
}

int sumAdjacentCells(TPos cell, TMat a) {
    bool outOfBounds(TPos cell);

    int sum = 0;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            TPos selectedCell = {{
                (cell[0] + i),
                (cell[1] + j)
            }};
            
            if((cell != selectedCell) and (not outOfBounds(selectedCell))) sum += a[selectedCell[0]][selectedCell[1]];
        }
    }
    return sum;

}

bool outOfBounds(TPos cell) {
    bool s1 = ((cell[0] >= NROW) or (cell[0] < 0));
    bool s2 = ((cell[1] >= NCOL) or (cell[1] < 0));
    return (s1 or s2);
}