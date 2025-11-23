#include <iostream>
using namespace std;

int main () {
    int n = 0;
    char k;
    while (k != '.' and n < 3) {
        cout << "Introduce a character: ";
        k = cin.get();
        if (k == 'a' and n == 0) {
            n++;
        } else if (k == 'b' and n == 1) {
            n++;
        } else if (k == 'c' and n == 2) {
            n++;
        } else {
            n-=n;
        }

    }
    if(n==3) {
        cout << "The string \"abc\" was found on the sequence";
    } else {
        cout << "The string \"abc\" was not found on the sequence";
    }
    cout << endl;
    return 0;
}