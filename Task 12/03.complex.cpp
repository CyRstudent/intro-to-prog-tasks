#include <iostream>
#include <cmath>
using namespace std;

struct TComp {
    float re, im;
};

int main () {
    void printCom(TComp c);
    TComp sumCom(TComp a, TComp b);
    TComp subCom(TComp a, TComp b);
    TComp mulCom(TComp a, TComp b);
    TComp divCom(TComp a, TComp b);

    TComp w = {2, 1}, z = {4, 3};
    printCom(sumCom(w, z));
    printCom(subCom(w, z));
    printCom(mulCom(w, z));
    printCom(divCom(w, z));

    return 0;
}

void printCom(TComp c) {
    cout << c.re << " ";
    if(c.im > 0) {
        cout << "+ ";
    }
    cout << c.im << 'i' << endl;
}

TComp sumCom(TComp a, TComp b) {
    a.re += b.re;
    a.im += b.im;
    return a;
}

TComp subCom(TComp a, TComp b) {
    a.re -= b.re;
    a.im -= b.im;
    return a;
}

TComp mulCom(TComp a, TComp b) {
    TComp res;
    res.re = ((a.re*b.re) - (a.im*b.im));
    res.im = ((a.re*b.im) + (b.re*a.im));
    return res;
}

TComp divCom(TComp a, TComp b) {
    //(a + bi)/(c + di) = (1/((c^2) + (d^2)))((ac + bd) + (bc - ad)i)
    TComp res;
    float dmod = sqrt(pow(b.re, 2) + pow(b.im, 2));
    res.re = ((a.re*b.re) + (a.im*b.im));
    res.im = ((b.re*a.im) - (a.re*b.im));

    res.re /= dmod;
    res.im /= dmod;

    return res;
}