#include <iostream>
using namespace std;

int main () {
    bool isValidEAN(string s);
    cout << isValidEAN("4003301018398") << endl << isValidEAN("4003301018392") << endl;
    return 0;
}

bool isValidEAN(string s) {
    int res = 0;
    int checksum = 0;
    for(int i = 0; i < s.size() - 1; i++) {
        int toadd = (int)s[i] - 48;
        if((i % 2) == 1) toadd*=3;
        res += toadd;
    }
    if((res % 10) != 0) checksum = 10 - (res % 10);
    return (checksum == ((int)s[12]-48));
}