#include <iostream>
using namespace std;

int main () {
    int express2int(string s);
    
    string s;
    cout << "Introduce an expression: ";
    getline(cin, s);
    cout << "Result: " << express2int(s) << endl;

    return 0;
}

int express2int(string s) {
    int str2int(string s);
    // We add an space just so that we can make sure the last number will be added.
    s += ' ';
    /**
     * sign = Depending on the sign, the number that is added will be positive or negative
     * res = The result to return
     * tempn = The string of the number scanned, which is temporal:
     * whenever the scanned char is not an integer, tempn will be reset to an empty string
     */
    int sign = 1;
    int res = 0;
    string tempn = "";

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if((c >= '0') and (c <= '9')) {
            tempn += c;
        } else {
            if(tempn != "") {
                res += str2int(tempn)*sign;
                tempn = "";
            }
            switch(c) {
                case '+':
                    sign = 1;
                    break;
                case '-':
                    sign = -1;
                    break;
            }
        }
    }
    return res;
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