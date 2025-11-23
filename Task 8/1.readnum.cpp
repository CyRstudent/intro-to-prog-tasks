#include <iostream>
using namespace std;

int main () {
    int readNum(int from, int to);

    int res = readNum(-250, 250);
    cout << res << endl;
    
    return 0;
} 

int readNum(int from, int to) {
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    while((n < from) or (n > to)) {
        cout << "Introduce another number: ";
        cin >> n;
    }
    return n;
}