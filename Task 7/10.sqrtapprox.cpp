#include <iostream>
using namespace std;

typedef unsigned __int64 bign;

int main () {
    int prevSq(int n);
    cout << prevSq(968) << endl;
    return 0;
}

int prevSq(int n) {
    int d = 1;
    while((d*d) <= n) d++;
    return d-1;
}