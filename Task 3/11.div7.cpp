#include <iostream>
using namespace std;

int main () {
    int n, n1, rem, t;
    cout << "Introduce a number: ";
    cin >> n;
    n1 = n%10;
    rem = (n-n1)/10;
    n1 *= 2;
    string res = "The number is ";
    t = (rem - n1)%7;
    res += ((t == 0) ? "divisible by 7" : "not divisible by 7");
    cout << res << endl;
    return 0;
}