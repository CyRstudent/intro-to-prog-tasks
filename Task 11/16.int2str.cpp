#include <iostream>
using namespace std;

int main () {
    string int2str(int n);

    int n;
    cout << "Introduce a number: ";
    cin >> n;

    cout << int2str(n) << endl;
    return 0;
}

string int2str(int n) {
    /**
     * Just a quick note:
     * While this is the most logical version of the function, it is also the most efficient.
     * The other way to do so is to start a loop based on the number of digits calculalated by a while loop, and then go down using powers of 10 and adding them to the resulting string
     * Time complexity for the version written below: O(d), where "d" is the number of digits.
     * Time complexity for the other version: O((log n)^2) => The first one is far more efficient.
     */
    string invres = "";
    while(n > 0) {
        char toadd = (n%10 + 48);
        invres += toadd;
        n /= 10;
    }
    string res = "";
    for(int i = invres.size()-1; i >= 0; i--) {
        res += invres[i];
    }
    return res;
}