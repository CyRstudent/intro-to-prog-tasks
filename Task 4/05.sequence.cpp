#include <iostream>
using namespace std;

int main () {
    int n;
    int seq;
    cout << "Introduce an integer: ";
    cin >> n;
    if (n == 0) {
        cout << "You must introduce a number that is not 0. Try again next time" << endl;
        return 1;
    }
    cout << "Start introducing numbers: ";
    seq = cin.get();
    while ((seq != 0) and (seq != n)) {
        cout << "Introduce more numbers: ";
        seq = cin.get();
    }
    if (seq == 0) {
        cout << "The number was not found in the sequence." << endl;
    } else {
        cout << "The number " << n << " was found in the sequence" << endl;
    }
    return 0;
    
}