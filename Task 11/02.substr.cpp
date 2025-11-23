#include <iostream>
using namespace std;

int main () {
    string substrneg(string s, int from, int end=-1);
    string a = "abcdefgh";
    cout << substrneg(a, 2, -1) << endl;
    return 0;
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