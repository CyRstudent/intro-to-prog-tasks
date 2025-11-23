#include <iostream>
using namespace std;

int main () {
    bool isPrime(int n);
    cout << isPrime(2) << endl; // 1 (Even prime)
    cout << isPrime(17) << endl; // 1 (Odd prime)
    cout << isPrime(16) << endl; // 0(Even composite)
    cout << isPrime(21) << endl; // 0 (Odd composite)
    return 0;
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