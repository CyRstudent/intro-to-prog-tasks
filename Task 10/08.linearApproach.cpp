#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<float, N> TVec;

int main () {
    void linearApproach(TVec x, TVec y, float& a, float& b);
    float a, b;
    linearApproach( {{0,1,3,5,7}}, {{1,0,2,4,6}}, a, b);
    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}

void linearApproach(TVec x, TVec y, float& a, float& b) {
    float xi = 0, yi = 0, xiyi = 0, xi2 = 0;
    for(int i = 0; i <= (N-1); i++) {
        xi += x[i];
        yi += y[i];
        xiyi += x[i]*y[i];
        xi2 += x[i]*x[i];
    }

    //Calculations for b
    float n1 = N*xiyi;
    float n2 = xi*yi;
    float d1 = N*xi2;
    float d2 = xi*xi;
    b = (n1-n2)/(d1-d2);

    //Calculations for a
    float n = yi - (b*xi);
    a = n/N;
}