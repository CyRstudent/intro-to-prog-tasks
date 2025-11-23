#include <iostream>
using namespace std;

int main () {
    int numdigits(int n, int base);
    cout << numdigits(2021, 10) << endl;
    cout << numdigits(2021, 2) << endl;
    return 0;
}

int numdigits(int n, int base) {
    if(n == 0) return 1;
    int res = 0;
    int power = 1;
    while (n > 0) {
        n/=base;
        res++;
    }
    return res;
}