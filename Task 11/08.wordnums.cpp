#include <iostream>
using namespace std;

int main () {
    void tryWith(string s);
    tryWith(" I Love Programming"); // 3
    tryWith(" some; (like) a2b"); // 4
    tryWith(" live on time, - emit no evil "); // 6

    return 0;
}

void tryWith(string s) {
    int noOfWords(string s);
    cout << noOfWords(s) << endl;
}

int noOfWords(string s) {
    bool alphabet(char a);

    int switcher = 0;
    int n = 0;
    if(alphabet(s[s.size()-1])) s += '.';
    
    for(int i = 0; i < s.size(); i++) {
        if(alphabet(s[i])) {
            if(switcher == 0) switcher++;
        } else {
            if(switcher == 1) {
                n++;
                switcher -= 1;
            }
        }
    }
    return n;
}

bool alphabet(char a) {
    bool s1 = a >= 'a';
    bool s2 = a <= 'z';
    bool s3 = a >= 'A';
    bool s4 = a <= 'Z';
    return ((s1 and s2) or (s3 and s4));
}