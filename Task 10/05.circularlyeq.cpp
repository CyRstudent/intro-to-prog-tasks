#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main () {
    bool circularlyEq(TVec a, TVec b);
    cout << circularlyEq((TVec){{1,2,3,4,5}}, (TVec){{5,1,2,3,4}}) << endl;
    cout << circularlyEq((TVec){{1,2,3,4,5}}, (TVec){{1,2,3,5,4}}) << endl;
    return 0;
}

bool circularlyEq(TVec a, TVec b) {
    int first = -1;
    for(int i = 0; i < N; i++) {
        if(a[0] == b[i]) {
            first = i;
            break;
        }
    }
    if(first == -1) return false;

    int incidents = 0;
    for(int i = 0; i < N; i++) {
        int comp = first + i;
        comp = comp % N;
        if(a[i] != b[comp]) incidents++;
    }
    return (incidents == 0);
}
