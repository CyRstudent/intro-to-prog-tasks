#include <iostream>
using namespace std;

int main () {
    int n, vowels, uppercase, nonletters;
    char c;
    cout << "Start introducing characters: ";
    c = cin.get();
    while (c != '.') {
        n = int(c);
        if((c=='a') or (c=='e') or (c=='i') or (c=='o') or (c == 'u') or (c=='A') or (c=='E') or (c=='I') or (c=='O') or (c=='U')) {
            vowels++;
        }
        if ((n<=90) and (n>=65)) {
            uppercase++;
        }
        if (not(((n<=90) and (n>=65)) or ((n>=97) and (n<=122)))) {
            nonletters++;
        }
    }
}