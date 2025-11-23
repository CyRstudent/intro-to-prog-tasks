#include <iostream>
using namespace std;

// Main program
int main () {
    void test(int a, int b);
    test(12, 18);
    test(54, 24);
    test(12, 30);
    test(1260, 600);
    return 0;
}

// Test procedure and c)
void test(int a, int b) {
    void simplify(int num, int den, int &nnum, int &nden);
    int na, nb;
    simplify(a, b, na, nb);
    cout << a << "/" << b << " = " << na << "/" << nb << endl;
}
void simplify(int num, int den, int &nnum, int &nden) {
    int gcd(int a, int b);
    int g = gcd(num, den);
    nnum = num/g;
    nden = den/g;
}

// a) and b)
int gcdBruteForce(int a, int b) {
    int d = (a < b)?a:b;
    while(not ((a%d == 0) and (b%d == 0))) d--;
    return d;
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