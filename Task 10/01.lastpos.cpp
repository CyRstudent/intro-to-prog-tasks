#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main () {
    int rfind(TVec a, int x);
    cout << rfind((TVec){{3,15,9,0,9}}, 9) << endl;
    return 0;
}

int rfind(TVec a, int x) {
    int c = -1;
    for(int i = 0; i < N; i++) {
        if(a[i] == x) c = i;
    }
    return c;
}