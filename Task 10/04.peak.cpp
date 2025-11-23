#include <iostream>
#include <array>
using namespace std;

const int N = 4;
typedef array<int, N> TVec;

int main () {
    int firstpeak(TVec a);
    TVec tests = {{firstpeak((TVec){{3,2,9,7}}), firstpeak((TVec){{3,3,3,3}}), firstpeak((TVec){{3,3,3,4}}), firstpeak((TVec){{3,3,5,4}})}};
    for(int i = 0; i < 4; i++) {
        cout << tests[i] << endl;
    }
    return 0;
}

int firstpeak(TVec a) {
    bool isPeak(TVec a, int i);
    for(int i = 0; i < N; i++) {
        if(isPeak(a, i)) return i;
    }
    return -1;
}

bool isPeak(TVec a, int i) {
    bool right = false;
    bool left = false;
    if(i == 0) {
        left = true;
        if(a[i] > a[i+1]) {
            right = true;
        }
    } else if(i == N-1) {
        right = true;
        if(a[i] > a[i-1]) {
            left = true;
        }
    } else {
        right = (a[i] > a[i+1]);
        left = (a[i] > a[i-1]);
    }
    return (left and right);
}