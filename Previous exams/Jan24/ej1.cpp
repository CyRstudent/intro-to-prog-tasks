// Sáez Madrid, Hugo
// Software Engineering, Group B
// PC-XXXX


// Time: 20min 56sec
#include <iostream>
#include <array>
using namespace std;

const int MAX_LONG_DIST = 15;
typedef array<array<int, 2>, MAX_LONG_DIST> TVec;

/**
 * An element of TVec contains the following: Length, frequency
 */

struct TColec { // Open array so we don't waste space
    TVec vec;
    int usedSpace = 0;
};

int main () {
    void addLen(TColec& colec, int n);
    cout << "Hugo Sáez Madrid" << endl;

    int n;
    TColec colec;

    cout << "Start introducing numbers (0 to end): ";
    while((cin >> n) and (n != 0)) addLen(colec, n);

    cout << "L\t V" << endl;
    for(int i = 0; i < colec.usedSpace; i++) {
        cout << colec.vec[i][0] << '\t' << colec.vec[i][1] << endl;
    }

    return 0;

}

void addLen(TColec& colec, int n) {
    int numLen(int n);
    int findLenColecPos(TColec colec, int n);

    int len = numLen(n);
    int index = findLenColecPos(colec, len);

    if(index == colec.usedSpace) colec.usedSpace++;

    colec.vec[index][0] = len;
    colec.vec[index][1]++;
}

int numLen(int n) { // Returns the length of a number
    int c = 0;
    while(n != 0) {
        n /= 10;
        c++;
    }
    return c;
}

int findLenColecPos(TColec colec, int n) {
    /**
     * Returns the index where the length appears at the collection
     * Returns colec.usedSpace if no length was found
     */
    int i = 0;
    while((i < colec.usedSpace) and (colec.vec[i][0] != n)) i++;

    if(colec.vec[i][0] != n) i = colec.usedSpace;
    return i;
}