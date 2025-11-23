#include <iostream>
using namespace std;

int main () {
    void primeDecomposition(int n);
    primeDecomposition(180);
    
    return 0;
}
void primeDecomposition(int n) {
    int nprime(int n);
    int prod = 1;
    int i = 1;
    int c = n;
    while (prod != n) {
        int div = nprime(i);
        if(n%div == 0){
            cout << div;
            int j = 0;
            while(c%div == 0) {
                j++;
                c/=div;
                prod*=div;
            }
            if(j > 1) cout << '^' << j;
            if(prod != n) cout << " * ";
        }
        i++;
    }
    cout << endl;
}
int nprime(int n) {
    bool isPrime(int n);
    int i = 0;
    int j = 1;
    while (i < n) {
        j++;
        if(isPrime(j)) i++;
    }
    return j;
}

bool isPrime(int n) {
    int aproxroot(int s);
    int i = 2;
    while ((i <= aproxroot(n)) and (n%i != 0)) {
        if(i == 2) i++; else i+=2;
    }
    return (i >= aproxroot(n));
}

int aproxroot(int s) {
    int i = 1;
    while (i*i <= s) i++;
    return i;
}