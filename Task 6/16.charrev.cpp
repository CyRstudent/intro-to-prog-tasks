#include <iostream>
using namespace std;

int main () {
    void revchars();
    revchars();
    return 0;
}

void revchars () {
    string res = "";
    string revres = "";
    int i = -1;
    char c = cin.get();
    while (c != '.') {
        i++;
        res += c;
        c = cin.get();
    }
    for(int j = i; j >= 0; j--) {
        revres += res[j];
    }
    cout << revres << endl;
}