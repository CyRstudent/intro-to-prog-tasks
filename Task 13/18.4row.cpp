#include <iostream>
#include <array>
using namespace std;

const int NROW = 6;
const int NCOL = 7;

typedef array<array<int, NCOL>, NROW> TBoard; // The main board


int main () {
    void initBoard(TBoard &tab);
    void insertToken(TBoard& tab, int token, int col, bool& ok, int& row);
    bool fourInARow(TBoard& tab, int fil, int col);
}

void initBoard(TBoard &tab) {
    for(int i = 0; i < NROW; i++) {
        for(int j = 0; j < NCOL; j++) {
            tab[i][j] = 0;
        }
    }
}

void insertToken(TBoard& tab, int token, int col, bool& ok, int& row) {
    int i = 0;
    while((i < (NROW - 1)))
}

bool fourInARow(TBoard& tab, int fil, int col);

bool outOfBounds(int row, int col) {
    bool s1 = row >= 0;
    bool s2 = row < NROW;
    bool s3 = col >= 0;
    bool s4 = col < NCOL;

    return not(s1 and s2 and s3 and s4);
}