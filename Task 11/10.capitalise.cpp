#include <iostream>
using namespace std;

int main () {
    string capitalise(string s);
    string str;
    cout << "Introduce a string: ";
    getline(cin, str);

    cout << capitalise(str) << endl;
    return 0;
}

string capitalise(string s) {
    bool alphabet(char a);
    int switcher = 0;
    for(int i = 0; i < s.size(); i++) {
        if(not alphabet(s[i])) switcher = 0;
        else if((switcher == 0) and (s[i] >= 'a')) {
            s[i] -= 32;
            switcher++;
        }
    }
    return s;
}

bool alphabet(char a) {
    bool s1 = a >= 'a';
    bool s2 = a <= 'z';
    bool s3 = a >= 'A';
    bool s4 = a <= 'Z';
    return ((s1 and s2) or (s3 and s4));
}