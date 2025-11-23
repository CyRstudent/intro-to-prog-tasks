#include <iostream>
#include <array>
using namespace std;

const int N = 256;
typedef array<int, N> TFreq;

int main () {
    bool isIsogram(string a);

    string s;
    cout << "Introduce something: ";
    cin >> s;

    string res = "The word is ";
    if(not isIsogram(s)) res += "not ";
    res += "an isogram";
    cout << res << endl;

    return 0;
}

bool isIsogram(string a) {
    TFreq freqs(string s);
    string toLower(string s);
    a = toLower(a);

    TFreq res = freqs(a);
    int i = 0;

    while((i < 255) and (res[i] <= 1)) i++;
    return (res[i] <= 1);
}

TFreq freqs(string s) {
    // We declare the variable to return and we initialize it setting all values to 0;
    TFreq res;
    for(int i = 0; i < N; i++) {
        res[i] = 0;
    }
    // We loop over the string
    for(int j = 0; j < s.size(); j++) {
        int pos = (int)s[j];
        res[pos]++;
    }
    return res;
}

string toLower(string s) {
    for(int i  = 0; i < s.size(); i++) {
        if((s[i] >= 'A') and (s[i] <= 'Z')) s[i] = ((int)s[i] + 32);
    }
    return s;
}