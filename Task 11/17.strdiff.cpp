#include <iostream>
#include <array>
using namespace std;
const int N = 256;
typedef array<int, N> TFreq;

int main () {
    string diff(string s, string t);
    cout << diff("telephone", "phonograph") << endl;
    cout << diff("holograph", "dog") << endl;

    return 0;
}

string diff(string s, string t) {
    TFreq freqs(string s);

    string res = "";
    TFreq tcounter = freqs(t);
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(tcounter[(int)c] > 0) {
            tcounter[(int)c]--;
        } else res += c;
    }
    return res;
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