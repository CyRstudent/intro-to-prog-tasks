#include <iostream>
#include <array>
using namespace std;

typedef array<int, 3> TRGB;

int main () {
    string rgbtohex(TRGB code);

    cout << rgbtohex((TRGB){{255, 255, 255}}) << endl; // "FFFFFF"
    cout << rgbtohex((TRGB){{255, 255, 300}}) << endl; // "FFFFFF"
    cout << rgbtohex((TRGB){{0,0,0}}) << endl; // "000000"
    cout << rgbtohex((TRGB){{148, 0, 211}}) << endl; // "9400D3"

    return 0;
}

string rgbtohex(TRGB code) {
    string dectohex(int n);
    string res = "";

    for(int i = 0;i < 3; i++) {
        if(code[i] > 255) code[i] = 255;
        res += dectohex(code[i]);
    }
    return res;
}

string dectohex(int n) {
    string res = "";
    if(n == 0) res = "00";
    while(n > 0) {
        int rem = n%16;
        string toadd = "";
        if(rem > 10) toadd += (char)(rem - 10 + 'A');
        else toadd += (char)(rem + 48);
        res += toadd;
        n/=16;
    }
    if(res.size() == 1) res += '0';
    string newres = "";
    for(int i = res.size()-1; i >= 0; i--) newres += res[i];
    return newres;
}
