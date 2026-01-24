#include <iostream>
#include <array>
using namespace std;

const int NCOL = 3;
const int NROW = 2;


typedef array<array<int, NCOL>, NROW> TMat;
typedef array<int, 2> TPosType;

int main () {
    void printMat(TMat m);
    TMat genMat();
    void firstMax(TMat m, int& x, int& y);

    int x, y;
    TMat example = genMat();
    firstMax(example, x, y);
    printMat(example);
    cout << x << " " << y << endl;

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

void firstMax(TMat m, int& x, int& y) {
    TPosType cellLocation(int i, int j);

    bool found = false;
    int i = 0;

    while((i < (NROW) and (not found))) {
        int j = 0;
        while((j < (NCOL)) and (not found)) {
            TPosType pos = cellLocation(i, j);
            switch(pos[0]) {
                case 0: {
                    array<int, 5> neighbours;
                    switch(pos[1]) {
                        case 0: {
                            neighbours = {{
                                m[i][j - 1], 
                                m[i][j + 1], 
                                m[i + 1][j - 1], 
                                m[i + 1][j], 
                                m[i + 1][j + 1]
                            }};
                            break;
                        }
                        case 1: {
                            neighbours = {{ 
                                m[i - 1][j], 
                                m[i - 1][j - 1], 
                                m[i][j - 1], 
                                m[i + 1][j], 
                                m[i + 1][j - 1]
                            }};
                            break;
                        }
                        case 2: {
                            neighbours = {{
                                m[i - 1][j],
                                m[i - 1][j + 1],
                                m[i][j + 1],
                                m[i + 1][j],
                                m[i + 1][j + 1]
                            }};
                            break;
                        }
                        case 3: {
                            neighbours = {{
                                m[i - 1][j],
                                m[i][j - 1],
                                m[i - 1][j - 1],
                                m[i - 1][j + 1],
                                m[i][j  + 1]
                            }};
                            break;
                        }
                    }
                    int c = 0;
                    for(int k = 0; k < 5; k++) {
                        if(m[i][j] > neighbours[k]) c++;
                    }
                    if(c == 5) {
                        found = true;
                        x = j;
                        y = i;
                    }
                    break;
                }
                case 1: {
                    array<int, 3> neighbours;
                    switch(pos[1]) {
                        case 0: {
                            neighbours = {{
                                m[i][j + 1],
                                m[i + 1][j],
                                m[i + 1][j + 1]
                            }};
                            break;
                        }
                        case 1: {
                            neighbours = {{
                                m[i][j - 1],
                                m[i + 1][j],
                                m[i + 1][j - 1]
                            }};
                            break;
                        }
                        case 2: {
                            neighbours = {{
                                m[i][j + 1],
                                m[i - 1][j],
                                m[i - 1][j + 1]
                            }};
                            break;
                        }
                        case 3: {
                            neighbours = {{
                                m[i][j - 1],
                                m[i - 1][j],
                                m[i - 1][j - 1]
                            }};
                            break;
                        }
                    }
                    int c = 0;
                    for(int k = 0; k < 3; k++) {
                        if(m[i][j] > neighbours[k]) c++;
                    }
                    if(c == 3) {
                        found = true;
                        x = j;
                        y = i;
                    }
                    break;
                }
                case 2: {
                    array<int, 8> neighbours = {{
                        m[i + 1][j - 1],
                        m[i + 1][j],
                        m[i + 1][j + 1],
                        m[i][j - 1],
                        m[i][j + 1],
                        m[i - 1][j - 1],
                        m[i - 1][j],
                        m[i - 1][j + 1]
                    }};
                    int c = 0;
                    for(int k = 0; k < 8; k++) {
                        if(m[i][j] > neighbours[k]) c++;
                    }
                    if(c == 8) {
                        found = true;
                        x = j;
                        y = i;
                    }
                    break;
                }
            }
            j++;
        }
        i++;
    }
    if(not found) {
        x = -1;
        y = x;
    }
}

TPosType cellLocation(int i, int j) { // Corner boundary inside
    /**
     * Returns the type of location the cell is at
     * TPosType[0] returns:
     * 1: The cell is at a corner
     * 0: The cell is at a boundary
     * 2: The cell is inside the boundaries of the matrix
     * TPosType[1] returns:
     * -1: The cell is inside the boundaries, thus not relevant
     * 0: For corners, it is on the up-left corner; for boundaries, it is on the upper boundary
     * 1: For corners: up-right; for boundaries: right boundary
     * 2: For corners: down-left boundary; for boundaries: left boundary
     * 3: For corners: down-right; for boundaries: lower boundary
     */
    TPosType r;

    bool top = (i == 0);
    bool bottom = (i == NROW - 1);
    bool left = (j == 0);
    bool right = (j == NCOL - 1);

    if(not(top or bottom or left or right)) { // If the cell is inside the boundaries, the result is straight-forward
        r = {{2, -1}};
    } else if((top or bottom) and (left or right)) { // If the cell is in a corner...
        r[0] = 1;
        if(top) {
            if(left) r[1] = 0;
            else r[1] = 1;
        } else {
            if(left) r[1] = 2;
            else r[1] = 3;
        }
    } else { // Anything else is a boundary
        r[0] = 0;
        if(top) r[1] = 0;
        else if(right) r[1] = 1;
        else if (left) r[1] = 2;
        else r[1] = 3;
    }
    return r;
}