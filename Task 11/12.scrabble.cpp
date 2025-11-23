#include <iostream>
#include <array>
using namespace std;
const int N = 256;
typedef array<int, N> TFreq;

int main () {
    bool scrabble(string s1, string s2);
    string s1, s2;

    cout << "Introduce 2 words: ";
    cin >> s1 >> s2;

    string res = "The words are ";
    if(not scrabble(s1, s2)) res += "not ";
    res += "scrabbled";
    cout << res << endl;

    return 0;
}

bool scrabble(string s1, string s2) {
    TFreq freqs(string s);

    TFreq f1 = freqs(s1), f2 = freqs(s2);
    return (f1 == f2);
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