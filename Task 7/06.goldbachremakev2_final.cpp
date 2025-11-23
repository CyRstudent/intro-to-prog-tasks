#include <iostream>
using namespace std;

int main () {
    void checkGoldbach(int s, int l);
    checkGoldbach(20, 2000);
    return 0;
}

void checkGoldbach(int s, int l) {
    int nprime(int n);
    bool isPrime(int n);

    for(int i = s; i <= l; i += (i%2 == 0)?2:1) {
        int j = 1;
        // We know for a fact that n = p + q <=> q = n - p => (n-p) is a prime number by definition
        while((not isPrime(i - nprime(j))) and (i >= (nprime(j)))) j++;
        // As per the last comment, the result must be a prime number, and by definition, greater than zero, or zero (because "i" could be prime itself)
        if (isPrime(i - nprime(j)) and ((i - nprime(j)) >= 0)) {
            cout << i << " = " << nprime(j) << " + " << (i-nprime(j)) << " --> SUCCESSFUL" << endl;
        } else {
            cout << i << " Does not follow Goldbach's conjecture" << endl;
            break;
        }
    }
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
    bool answer;
    if (n <= 1) answer = false;
    else if (n == 2) answer = true;
    else if (n % 2 == 0) answer = false;
    else {
        int d = 3;
        while (d * d < n and n % d != 0) d += 2;
        answer = d*d > n;
    }
    return answer;

}