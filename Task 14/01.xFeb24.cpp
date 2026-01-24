#include <iostream>
#include <array>
using namespace std;

const int NMAX_DIFF = 50;
typedef array<int, NMAX_DIFF> TVec;
struct TArr {
    int usedSpace;
    TVec vec;
};

int main () {
    void initialize(TArr &a);
    void actualizeDb(int n, int pat, TArr& db);

    TArr db;
    initialize(db);

    int pattern = -1;
    int n;

    while(pattern <= 0) {
        cout << "Introduce a valid pattern: ";
        cin >> pattern;
    }
    
    cout << "Introduce a list of numbers ending in 0: ";
    while((cin >> n) and (n != 0)) {
        actualizeDb(n, pattern, db);
    }

    for(int i = 0; i < db.usedSpace; i++) {
        cout << db.vec[i] << ' ';
    }
    cout << endl;
    return 0;
}

void initialize(TArr &a) {
    a.usedSpace = 0;
    for(int i = 0; i < NMAX_DIFF; i++) {
        a.vec[i] = 0;
    }
}

void actualizeDb(int n, int pat, TArr& db) {
    int sumDigits(int n);
    bool containedIn(TArr a, int n);

    if((sumDigits(n) == sumDigits(pat)) and (not containedIn(db, n))) {
        db.vec[db.usedSpace] = n;
        db.usedSpace++;
    }
}

int sumDigits(int n) {
    int res = 0;
    while(n > 0) {
        res += (n%10);
        n /= 10;
    }
    return res;
}

bool containedIn(TArr a, int n) {
    int i = 0;
    while((i < (a.usedSpace - 1)) and (a.vec[i] != n)) i++;
    return (a.vec[i] == n);
}