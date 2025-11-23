#include <iostream>
using namespace std;

int main () {
    void charhilo(int &hi, int &lo, char c);

    char c;
    int hi = 0;
    int lo = 0;

    cout << "Start introducing characters: ";
    cin >> c;
    while(c != '.') {
        charhilo(hi, lo, c);
        cin >> c;
    }
    
    string res = "The number of uppercase letters is ";
    if(hi != lo) res += "not ";
    res += "equal to the number of lowercase letters";
    cout << res << endl;
    
    return 0;
}

void charhilo(int &hi, int &lo, char c) {
    int typeofchar(char c);
    switch(typeofchar(c)) {
        case 0:
            hi++;
            break;
        case 1:
            lo++;
            break;
    }
}

int typeofchar(char c) {
    // 0 = Upper
    // 1 = Lower
    // 2 = Not a letter from the english alphabet
    int d = int(c);
    int res;
    if((d < 91) and (d > 59)) {
        res = 0;
    } else if((d < 123) and (d > 96)) {
        res = 1;
    } else res = 2;
    return res;
}