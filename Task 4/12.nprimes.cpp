#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    int k = 1;
    int i = 1;
    while ((k <= n)) {
        int divs = 0;
        for (int j = 1; j <= i; j++) {
            if(i%j==0) {
                divs++;
            }
        }
        if (divs == 2) {
            cout << i << endl;
            k++;
        }
        i++;
    }
    return 0;
}