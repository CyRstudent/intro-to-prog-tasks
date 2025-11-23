#include <iostream>
using namespace std;

int main () {
    int rom2int(string s);
    cout << rom2int("iIi") << endl; // 3
    cout << rom2int("iv") << endl; // 4
    cout << rom2int("liv") << endl; // 54

    return 0;
}
int rom2int(string s) {
    string toLower(string s);
    int romchar2int(char c);

    // We convert everything to lowercase to avoid confusion
    s = toLower(s);
    int res = romchar2int(s[s.size() - 1]);
    // We iterate starting in s.size() - 2, since we want to access the last element for comparison.
    for(int i = s.size() - 2; i >= 0; i--) {
        int toadd = romchar2int(s[i]);
        if(romchar2int(s[i+1]) > toadd) toadd *= -1;
        res += toadd;
    }
    return res;
}

int romchar2int(char c) {
    int res = 0;
    switch(c) {
        case 'i':
            res++;
            break;
        case 'v':
            res += 5;
            break;
        case 'x':
            res += 10;
            break;
        case 'l':
            res += 50;
            break;
        case 'c':
            res += 100;
            break;
        case 'd':
            res += 500;
            break;
        case 'm':
            res += 1000;
            break;
    }
    return res;
}

string toLower(string s) {
    for(int i  = 0; i < s.size(); i++) {
        if((s[i] >= 'A') and (s[i] <= 'Z')) s[i] = ((int)s[i] + 32);
    }
    return s;
}