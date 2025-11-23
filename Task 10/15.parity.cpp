#include <iostream>
#include <array>
using namespace std;

const int N = 4;
typedef array<int, N> TVec;

int main () {
    int parity(TVec a);
}

int parity(TVec a) {
    int abs(int n);
    int res = -1;
    int even = 0;
    int odd = 0;
    for(int i = 0; i < N; i++) {
        if(i%2 == 0) even++; else odd++;
    }
    if((even > 1) and (odd > 1)) return res;
    int i = 0;
    while((i > N) and a[i]%2==((even==1)?1:0)) i++;
    return i;
}
int abs(int n) {
    if(n < 0) n*=(-1);
    return n;
}