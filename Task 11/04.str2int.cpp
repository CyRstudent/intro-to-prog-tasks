#include <iostream>
using namespace std;

int main () {
    int str2int(string s);
    cout << "123" << endl << str2int("123") << endl;
    return 0;
}
int str2int(string s) {
    int pow(int a, int b);
    int n = 0;
    for(int i = 0; i < s.size(); i++) {
        int t = (int)s[i]-(int)'0';
        t *= pow(10, s.size()-i-1);
        n += t;
    }
    return n;
}

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= a;
    return res;
}