#include <iostream>
using namespace std;

int main () {
    bool validBraces(string s);
    
    string s;
    cout << "Introduce a string: ";
    cin >> s;
    string res = "The string is ";
    if(not validBraces(s)) res += "not ";
    res += "valid";
    cout << res << endl;

    return 0;
}

bool validBraces(string s) {
    int aperture(char c);
    char matching(char c);

    string new_s = "";
    // We eliminate those characters that aren't the mentioned
    for(int i = 0; i < s.size(); i++) {
        if(aperture(s[i]) != -1) new_s += s[i];
    }

    bool switcher = true;
    while(switcher) {
        switcher = false;
        string temp = "";
        int j = 0;
        while(j < new_s.length()) {
            if(((j + 1) < new_s.length()) and (aperture(new_s[j]) == 0) and (new_s[j + 1] == matching(new_s[j]))) {
                j += 2;
                switcher = true;
            } else {
                temp += new_s[j];
                j++;
            }
        }
        new_s = temp;
    }
    return (new_s.size() == 0);
}

int aperture(char c) {
    /**
     * int aperture(char c) -> int
     * 0 => The character is open
     * 1 => The character is closed
     * -1 => The character is neither a curly brace, nor a bracket, nor a parenthesis
     */
    int res = 0;
    switch(c) {
        case '{': case '(': case '[':
            res = 0;
            break;
        case '}': case ')': case ']':
            res = 1;
            break;
        default:
            res = -1;
    }
    return res;
}

char matching(char c) {
    char res = '\0';
    switch(c) {
        case '{':
            res = '}';
            break;
        case '(':
            res = ')';
            break;
        case '[':
            res = ']';
            break;
        case '}':
            res = '{';
            break;
        case ')':
            res = '(';
            break;
        case ']':
            res = '[';
            break;
    }
    return res;
}