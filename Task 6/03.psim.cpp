#include <iostream>
using namespace std;

int main () {
    int digit(int n, int p, int base);
    cout << digit(25064, 10, 10) << endl;
    return 0;
}

int digit(int n, int p, int base) {
    int multiplier = 1;
    for(int i = 0; i < p; i++) multiplier *= 10;
    int digit = (n/multiplier)%10;

    int res = 0;
    int ex = 1;
    while (digit > 0) {
        int rem = digit%base;
        res += ex*rem;
        ex*=10;
        digit/=base;
    }
    return res;
}