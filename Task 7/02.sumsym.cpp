#include <iostream>
using namespace std;

int main () {
    void sumsymdigits(int n);

    int n;
    cout << "Introduce a number: ";
    cin >> n;
    
    sumsymdigits(n);

    return 0;
}

void sumsymdigits(int n) {
    int nodigits(int s);
    int digitAtp(int n, int pos);

    int num = nodigits(n);
    int c = num/2;
    bool isOdd = (num%2 == 1);
    if(isOdd) c++;

    for(int i = 1; i <= c; i++) {
        int left = digitAtp(n, num-i+1);
        int right = digitAtp(n, i);
        if(isOdd and (i == c)) {
            cout << left << endl;
        } else {
            cout << (left + right) << " ";
        }
    }
}

int nodigits(int s) {
    int c = 0;
    while(s != 0) {
        s/=10;
        c++;
    }
    return c;
}

int digitAtp(int n, int pos) {
    int pow(int b, int e);
    int res = n/pow(10, pos-1);
    return (res%10);
}

int pow(int b, int e) {
    int res = 1;
    for(int i = 0; i < e; i++) {
        res*=b;
    }
    return res;
}