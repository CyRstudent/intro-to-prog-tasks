#include <iostream>
using namespace std;

int main () {
    int n;
    float res = 0;
    cout << "Enter a dog's age in human years: ";
    cin >> n;
    if (n <=2 ) {
        res += (n*10.5);
    } else {
        res += 21;
        res += ((n-2)*4);
    }
    cout << "The dog's age in dog's years is " << res << endl;
    return 0;
}