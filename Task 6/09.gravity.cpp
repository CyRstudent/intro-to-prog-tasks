#include <iostream>
using namespace std;

int main () {
    float gravity(float m1, float m2, float d);
    float powx(float x, int n);

    float m1 = 5.974*powx(10, 24);
    float m2 = 1;
    float d = 6378140;
    float res = gravity(m1, m2, d);
    cout << res << endl;

    d += 35786*1000;
    res = gravity(m1, m2, d) - 0.03373;
    
    d = 245*2;
    m1 = 7.329*powx(10, 10);
    res = gravity(m1, m2, d) - 0.00004082;

    return 0;
}
float gravity(float m1, float m2, float d) {
    float powx(float x, int n);
    const float G = 6.67428*powx(10, -11);
    float t1 = G*m1*m2*(-1);
    float t2 = powx(d, 2);
    return (t1/t2);
}

float powx(float x, int n) {
    float res = 1;
    int absval = n;
    if(n < 0) absval*=-1;
    for (int i = 0; i < absval; i++) res*=x;
    if (n < 0) return (1/res);
    return res;
}