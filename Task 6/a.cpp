#include <iostream>
using namespace std;

int main () {
    void pow2(int &n);
    int n = 5;
    cout << n << endl;
    pow2(n);
    cout << n << endl;
    return 0;
}
void pow2(int &n) {
    int res = 1;
    for(int i = 0; i < n; i++) {
        res *=2;
    }
    n = res;
}