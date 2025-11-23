#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int n, pos;
    cout << "Introduce an integer and a position: ";
    cin >> n >> pos;
    if(pos == 0) return 0;
    int pos10 = 1;
    for(int i = 1; i <= pos; i++) {
        pos10*=10;
    }
    int res = n%(pos10);
    for(int i = 1; i < ((int)log10(res) + 1); i++) {
        int pow10 = 1;
        for(int j = 1; j<=i; j++) {
            pow10*= 10;
        }
        res -= (res%pow10);
    }
    cout << (10*res)/pos10 << endl;
    return 0;
}