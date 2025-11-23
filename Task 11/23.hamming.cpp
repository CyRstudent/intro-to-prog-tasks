#include <iostream>
using namespace std;

int main () {
    int hamming(string s1, string s2);
    cout << hamming("0101", "1010") << endl;
    cout << hamming("11010", "11101") << endl;
    return 0;
}

int hamming(string s1, string s2) {
    int res = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i]) res++;
    }
    return res;
}