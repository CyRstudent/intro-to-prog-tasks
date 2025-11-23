#include <iostream>
#include <array>
using namespace std;
const int N = 256;
typedef array<int, N> TFreq;

int main () {
    TFreq freqs(string s);
    bool previouslyPrinted(string subs, char c);
    string substrneg(string s, int from, int end = -1);

    string str;
    cout << "Introduce a string: ";
    getline(cin, str);
    TFreq res = freqs(str);

    for(int i = 0; i < str.size(); i++) {
        if((i == 0) or (not previouslyPrinted(substrneg(str, 0, i-1), str[i]))) {
            cout << res[(int)str[i]] << ' ' << str[i] << endl;
        }
    }

    return 0;
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
bool previouslyPrinted(string subs, char c) {
    int i = 0;
    while((i < subs.size()-1) and (subs[i] != c)) i++;
    return (subs[i] == c);
}
string substrneg(string s, int from, int end=-1) {
    string res = "";
    if(from < 0) from += s.size();
    if(end < 0) end += s.size();
    if(not((from > s.size()-1) or (end > s.size()-1))) {
        for(int i = from; i <= end; i++) {
            res += s[i];
        }
    }
    return res;
}