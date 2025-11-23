#include <iostream>
using namespace std;

int main () {
    int gcd(int p, int q);
    cout << gcd(123432, 512) << endl;
    return 0;
}
int gcd(int p, int q) {
    while((p!=0) and (q != 0)) {
        if(p > q) {
            p = (p%q);
        } else {
            q = (q%p);
        }
    }
    return (p+q);
}