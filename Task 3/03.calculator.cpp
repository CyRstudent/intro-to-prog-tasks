#include <iostream>
#include <cmath>
using namespace std;

int main () {
    double a, b, res;
    char o;
    res = 0;
    cout << "Write 2 real numbers and the desired operation (+, -, *, /, \% or ^): ";
    cin >> a >> b >> o;
    switch (o) {
        case '+':
            res += (a + b);
            break;
        case '-':
            res += (a-b);
            break;
        case '*':
            res += (a*b);
            break;
        case '/':
            res += (a/b);
            break;
        case '%':
            res += ((int (a)) % (int(b)));
            break;
        case '^':
            res += pow(a, b);
            break;
        default:
            cout << "Introduce a valid operation next time" << endl;
            return 1;
    }
    cout << "The result of " << a << o << b << " is " << res << endl;
    return 0;
}