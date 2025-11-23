#include <iostream>
using namespace std;

int main () {
    int lcmBruteForce(int a, int b);
    cout << lcmBruteForce(8, 12) << endl;
    return 0;
}

int lcmBruteForce(int a, int b) {
    int m = (a>b)?a:b;
    while((m%a != 0) or (m%b != 0)) m++;
    return m;
}