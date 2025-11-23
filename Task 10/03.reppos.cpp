#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main () {
    int firstRep(TVec a);
    array<int, 3> tests = {{firstRep((TVec){{1, 2, 3, 2}}), firstRep((TVec){{1, 2, 1, 2}}), firstRep((TVec){{1, 2, 3, 4}})}};
    for(int i = 0; i < 3; i++) {
        cout << tests[i] << endl;
    }
    return 0;
}

int firstRep(TVec a) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(a[i] == a[j]) return i;
        }
    }
    return -1;
}