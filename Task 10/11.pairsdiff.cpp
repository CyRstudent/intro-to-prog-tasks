#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main() {
    int pairsDiff(TVec a, int n);
    cout << pairsDiff((TVec){{1,1,5,6,9}}, 4) << endl << pairsDiff((TVec){{1,1,3,3,9}}, 2) << endl;
    return 0;
}

int pairsDiff(TVec a, int n) {
    int c = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if((a[j] - a[i]) == n) c++;
        }
    }
    return c;
}