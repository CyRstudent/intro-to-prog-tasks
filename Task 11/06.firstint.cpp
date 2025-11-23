#include <iostream>
using namespace std;

int main () {
    int firstInt(string s);
    cout << firstInt("You owe me 10, doesn't you?") << endl; // 10
    cout << firstInt("No ten, but -12") << endl; // 12
    return 0;

}

int firstInt(string s) {
    int n = 0;
    int i = 0;
    while((i < s.size()-2) and not((s[i] <= '9') and (s[i] >= '0'))) i++;
    while(s[i] <= '9' and s[i] >= '0') {
        n *= 10;
        n += (s[i] - '0');
        i++;
    }
    return n;
}
