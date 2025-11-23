#include <iostream>
#include <array>
using namespace std;

const int N = 6;
typedef array<int, N> TVec;

int main () {
    int midpointSum(TVec a);
    array<int, 3> tests = {{midpointSum((TVec){{4, 1, 7, 9, 3, 9}}), midpointSum((TVec){{4, 4, 4, 4, 4, 4}}), midpointSum((TVec){{16, 4, 4, 4, 4, 4}})}};
    for(int i = 0; i < 3; i++){
        cout << tests[i] << endl;
    }
    return 0;
}

int midpointSum(TVec a) {
    int partialSum(TVec n, int a, int b);
    for(int i = 0; i < N; i++) {
        if(partialSum(a, 0, i) == partialSum(a, i+1, N)) {
            return i;
            break;
        }
    }
    return -1;
}

int partialSum(TVec n, int a, int b) {
    int res = 0;
    for(int i = a; i < b; i++) {
        res += n[i];
    }
    return res;
}