#include <iostream>
using namespace std;

int main() {
    string breakCamelCase(string s);

    cout << breakCamelCase("camelCasing") << endl; // camel_casing
    cout << breakCamelCase("__A__aA_A_") << endl; // ___a__a_a__a_
    cout << breakCamelCase("camelC") << endl; // camel_c
    cout << breakCamelCase("camElC") << endl; // cam_el_c
    cout << breakCamelCase("APPLE") << endl; // _a_p_p_l_e

    return 0;
}

string breakCamelCase(string s) {
    string res = "";
    for(int i = 0; i < (int)s.size(); i++) {
        int c = (int)s[i];
        if((c > 64) and (c < 91)) {
            res += "_";
            res += (s[i]+32);
        } else res += s[i];
    }
    return res;
}