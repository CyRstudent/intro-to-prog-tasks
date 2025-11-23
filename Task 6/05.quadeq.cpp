#include <iostream>
#include <cmath>
using namespace std;

int main () {
    void quadeq(float a, float b, float c, float& x1 , float& x2 , int& type, float& i1, float& i2);
    float a, b, c, x1, x2, i1, i2;
    int type;
    cout << "Introduce by order the coefficients of the equation ax^2 + bx + c: ";
    cin >> a >> b >> c;
    quadeq(a, b, c, x1, x2, type, i1, i2);
    switch(type) {
        case 1:
            cout << "The equation returns 2 different real numbers." << endl;
            break;
        case 2:
            cout << "The equation returns the real/integer parts of a conjugated complex number." << endl;
            cout << "Solutions are: " << endl;
            cout << "\tx1: " << x1;
            if(i1 < 0) {
                cout << " ";
            } else {
                cout << " + ";
            }
            cout << i1 <<"i" << endl;

            cout << "\tx2: " << x2;
            if(i2 < 0) {
                cout << " ";
            } else {
                cout << " + ";
            }
            cout << i2 <<"i" << endl;
            break;
        case 3:
            cout << "The equation returns a double real solution" << endl;
            break;
        case 4:
            cout << "The equation returns a simple number." << endl;
            break;
        case 5:
            cout << "The equation is impossible to do." << endl;
            break;
        case 6:
            cout << "The equation is trivial, and is valid for all x belonging to the set of real numbers" << endl;
            break;
    }
    if((type == 1) or (type == 3) or (type == 4)) {
        cout << "Solutions are: " << endl;
        cout << "\tx1: " << x1 << endl;
        cout << "\tx2: " << x2 << endl;
    }
    return 0;
}

void quadeq(float a, float b, float c, float& x1 , float& x2 , int& type, float& i1, float& i2) {
    double power(double x, int n);
    double d = (power(b, 2)-(4*a*c));
    if(d == 0) {
        if((a == 0) and (b == 0)) {
            x1 = 0;
            x2 = x1;
            if(c != 0) {
                type = 5;
            } else {
                type = 6;
            }
        } else {
            type = 3;
            x1 = (-b)/(2*a);
            x2 = x1;
        }
    } else if(d > 0) {
        if(a == 0) {
            type = 4;
            x1 = (-c)/b;
            x2 = x1;
        } else {
            type = 1;
            x1 = (-b + sqrt(d))/(2*a);
            x2 = ((-1)*(b + sqrt(d)))/(2*a);
        }
    } else {
        type = 2;
        x1 = (-b)/(2*a);
        x2 = x1;
        i1 = (-1)*sqrt(d*(-1));
        i2 = sqrt(d*(-1));
        i1 /= (2*a);
        i2 /= (2*a);
    }
}

double power(double x, int n) {
    double res = 1;
    int absval = n;
    if(n < 0) absval*=-1;
    for (int i = 0; i < absval; i++) res*=x;
    if (n < 0) return (1/res);
    return res;
}