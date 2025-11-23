#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
    int strcmp(string s1, string s2);
    cout << strcmp("", "") << endl; // 0
    cout << strcmp("a", "b") << endl; // -1
    cout << strcmp("b", "a") << endl; // 1
    cout << strcmp("a", "a") << endl; // 0
    cout << strcmp("avion", "avioneta") << endl;// -1
    cout << strcmp("ave", "avioneta") << endl; // -1
    cout << strcmp("avioneta", "ave") << endl; // 1

    return 0;
}

int strcmp(string s1, string s2) {
    void comparison(int a, int b, int &res);
    int res = 0;

    // Starting variables to determine when to stop the while loop;
    int sz1 = s1.size();
    int sz2 = s2.size();
    int n = (sz1<sz2)?sz1:sz2;

    // We start a loop that ends whenever we're about to end the string or we found a character diffferent from the other string
    int i = 0;
    while((i < n) and (res == 0)) {
        comparison(s1[i], s2[i], res);
        i++;
    }
    // If the result is still zero, we compare the string's sizes;
    if(res == 0) comparison(sz1, sz2, res);
    return res;
}

void comparison(int a, int b, int &res) {
    // Used to simplify the code
    if(a > b) res = 1;
    else if(a < b) res = -1;
    else res = 0;
}