#include <iostream>
using namespace std;

int main () {
    int nprime(int n);
    cout << nprime(0) << endl;
    return 0;
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