#include <iostream>
#include <array>
using namespace std;

const int N = 16;
typedef array<int, N> TVec;

int main() {
    int lcs(TVec a);
    cout << lcs((TVec){{3,9,9,0,9,3,9,9,9,0,9,3,9,9,0,9}}) << endl;
    cout << lcs((TVec){{1,1,1,1,2,3,4,0,0,0,0,0,0,0,0,0}}) << endl;
    return 0;
}

int lcs(TVec a) {
    int maxlen = 0;
    for(int i = 0; i < N-1; i++) {
        if(a[i] == a[i+1]) {
            int clen = 0;
            int j = i+1;
            while((j < N) and (a[j] == a[i])) {
                j++;
                clen++;
            }
            if(clen > maxlen) maxlen = clen;
        }
    }
    maxlen++;
    if(maxlen == 0) maxlen--;
    return maxlen;
}