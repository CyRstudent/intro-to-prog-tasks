#include <iostream>
using namespace std;

int main () {
    int n, sum;
    sum = 0;
    cout << "Introduce a number: ";
    cin >> n;
    while ((n != 0) and (n != sum)) {
        sum += n;
        cout << "Introduce another number: ";
        cin >> n;
    }
    return 0;
    
}