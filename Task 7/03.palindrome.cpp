#include <iostream>
using namespace std;

int main () {
    bool isPalindromic(int n);

    int n;
    cout << "Introduce a number: ";
    cin >> n;
    string res = "The number is ";
    res += isPalindromic(n)?"palindromic":"not palindromic";
    cout << res << endl;
    return 0;

}

bool isPalindromic(int n) {
    if(n < 0) return false;

    int digitAtp(int n, int pos);
    int nodigits(int s);
    int pow(int b, int e);

    int res = 0;
    int len = nodigits(n);

    for(int i = 1; i <= len; i++) {
        int d = digitAtp(n, len-i+1);
        res += d*pow(10, i-1);
    }

    return (res == n);
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
int nodigits(int s) {
    int c = 0;
    while(s != 0) {
        s/=10;
        c++;
    }
    return c;
}