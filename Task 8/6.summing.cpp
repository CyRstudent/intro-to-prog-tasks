#include <iostream>
using namespace std;

// Although the program works perfectly fine, the exercise did not ask for it to print something, so it will just end whenever the sum is about to be over than the max specified

int main () {
    int sum = 0;
    int max = 10;
    int n;

    cout << "Input integer numbers: ";
    cin >> n;
    while((sum + n) <= max) {
        sum += n;
        cout << "Introduce more: ";
        cin >> n;
    }

    return 0;
}