/**
 * Sáez Madrid, Hugo
 * Software Engineering, Group B
 * PCXXXX
 */

// Time: 15min 46sec

#include <iostream>
#include <array>
using namespace std;

const int MAX_NUM_DIST = 15;
typedef array<int, MAX_NUM_DIST> TVec;

struct TColec {
    TVec vec;
    int usedSpace = 0;
};

int main () {
    void addNum(TColec& a, int n, int pat);

    cout << "Sáez Madrid, Hugo" << endl;

    int pat = -1;
    int n;
    TColec a;

    while(pat <= 0) {
        cout << "Introduce a valid pattern: ";
        cin >> pat;
    }

    cout << "Start introducing numbers (0 to end): ";
    while((cin >> n) and (n != 0)) {
        if(n > 0) addNum(a, n, pat);
    }

    cout << "Result: ";
    for(int i = 0; i < a.usedSpace; i++) {
        cout << a.vec[i] << ' ';
    }
    cout << endl;

    return 0;
}

void addNum(TColec& a, int n, int pat) {
    int digitSum(int n);
    bool inColec(TColec a, int n);
    
    // We'll let main() take care of filtering negative integers
    int patSum = digitSum(pat);
    int nSum = digitSum(n);

    if((patSum == nSum) and (not inColec(a, n))) {
        a.vec[a.usedSpace] = n;
        a.usedSpace++;
    }

}

int digitSum(int n) {
    int sum = 0;

    while(n > 0) {
        sum += (n%10);
        n/=10;
    }
    return sum;
}

bool inColec(TColec a, int n) {
    bool found = false;
    int i = 0;
    while((i < a.usedSpace) and (not found)) {
        found = (n == a.vec[i]);
        i++;
    }

    return found;
}