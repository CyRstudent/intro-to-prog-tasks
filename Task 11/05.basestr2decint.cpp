#include <iostream>
using namespace std;

int main () {
    int str2int(string s, int base = 10);

    cout << str2int("121231") << endl; // 121231
    cout << str2int("1111", 2) << endl; // 15
    cout << str2int("77", 8) << endl; // 63
    cout << str2int("A", 16) << endl; // 10
    cout << str2int("FFFF", 16) << endl; // 65535
    
    return 0;
}

int str2int(string s, int base = 10) {
    int pow(int a, int b);
    int n = 0;
    for(int i = 0; i < s.size(); i++) {
        int t;
        char c = s[i];
        if(c >= '0' and c <= '9') {
            t = (int)c - (int)'0';
        } else {
            t = (int)tolower(c) - 87;
        }
        t *= pow(base, s.size()-i-1);
        n += t;
    }
    return n;
}

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= a;
    return res;
}