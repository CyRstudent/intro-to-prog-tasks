#include <iostream>
using namespace std;

int main () {
    int a, b, c, d;
    cout << "Introduce 4 integers: ";
    cin >> a >> b >> c >> d;
    string res = "The largest integer is: ";
    if ((a>b) and (a>c) and (a>d)) {
        res += a;
    } else if ((b>a) and (b>c) and (b>d)) {
        res += b;
    } else if ((c>a) and (c>b) and (c>d)) {
        res += c;
    } else {
        res += d;
    }
    cout << res << endl;
    return 0;
}