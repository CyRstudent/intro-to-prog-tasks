#include <iostream>
#include <array>
using namespace std;

typedef array<int, 2> TRes;
/**
 * First value holds the displacement
 * Second value holds the number of matching characters
 */

int main () {
    TRes slide(string s1, string s2);
    
}

TRes slide(string s1, string s2) {
    int matching(string s1, string s2);

    TRes res = {{0, 0}};
    string t = s1;

    for(int i = 0; i < s1.size(); i++) {
        if(i > 0) t.pop_back();
        if(matching(s2, t) > res[1]) {
            res = {{i, matching(s2, t)}};
        }
    }
    return res;
}

int matching(string s1, string s2) {
    int c = 0;

    if(s2.size() > s1.size()) {
        string t = s1;
        s1 = s2;
        s2 = t;
    }

    for(int i = 0; i < s2.size(); i++) {
        if(s1[i] == s2[i]) c++;
    }
    return c;
}