#include <iostream>
#include <array>
using namespace std;

const int N = 3;
typedef array<int, N> TVec;

int main () {
    int scoreThrows(TVec a);
    TVec tests = {{scoreThrows((TVec){{ 1, 5, 11}} ), scoreThrows((TVec){{15, 20, 30}} ), scoreThrows((TVec){{ 1, 2, 3}} )}};
    for(int i = 0; i < N; i++) cout << tests[i] << endl;
    return 0;
}

int scoreThrows(TVec a) {
    TVec clp = {{0, 0, 0}}; // In order: x<5, 5 <= x <= 10; x > 10; 
    int res = 0;
    for(int i = 0; i < N; i++) {
        int rad = a[i];
        if(rad > 10) clp[2]++;
        else if(rad < 5) clp[0]++;
        else clp[1]++;
    }
    if(clp[0] == N)  {
        res += 100;
    }
    res += clp[0]*10;
    res += clp[1]*5;
    return res;
}