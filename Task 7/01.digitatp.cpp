#include <iostream>
using namespace std;

int main () {
    int digitAtp (int n, int pos) ;
    cout << digitAtp (1492 , 1) << endl ; // 2
    cout << digitAtp (1492 , 3) << endl ; // 4
    cout << digitAtp (1492 , 6) << endl ; // 0

    return 0;
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