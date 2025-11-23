#include <iostream>
using namespace std;

int main () {
    int lcm(int a, int b);
    cout << lcm(12, 8) << endl;
    return 0;
}

int lcm(int a, int b) {
    int gcd(int a, int b);
    int res = a*b;
    res /= gcd(a, b);
    return res;
}

int gcd(int a, int b) {
    while((a!=0) and (b != 0)) {
        if(a > b) {
            a = (a%b);
        } else {
            b = (b%a);
        }
    }
    return (a+b);
}