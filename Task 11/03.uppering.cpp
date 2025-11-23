#include <iostream>
using namespace std;

int main () {
    string toUpper(string s);
    cout << toUpper("hola pataTA)") << endl;
    return 0;
}
string toUpper(string s) {
    for(int i  = 0; i < s.size(); i++) {
        if(((int)s[i] > 96) and ((int)s[i] < 123)) s[i] = ((int)s[i] - 32);
    }
    return s;
}