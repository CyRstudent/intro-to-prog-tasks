#include <iostream>
using namespace std;

typedef unsigned __int64 bign;

int main () {
    bign nprime(bign n);
    for(bign i = 1; i < 100; i+=10) {
        cout << i << ": " << nprime(i) << endl;
    }
    return 0;
}

bign nprime(bign n) {
    bool isPrime(bign n);
    bign i = 0;
    bign j = 1;
    while (i < n) {
        j++;
        if(isPrime(j)) i++;
    }
    return j;
}

bool isPrime(bign n) {
    bool answer;
    if (n <= 1) answer = false;
    else if (n == 2) answer = true;
    else if (n % 2 == 0) answer = false;
    else {
        bign d = 3;
        while (d * d < n and n % d != 0) d += 2;
        answer = d*d > n;
    }
    return answer;

}