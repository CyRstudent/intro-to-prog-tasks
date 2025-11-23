#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Introduce a number: ";
    cin >> n;
    for(int i = 1; i < n; i++) {
        int divs = 0;
        for(int j = 1; j <= i; j++) {
            if(i%j == 0) divs++;
        }
        if (divs <= 2) cout << i << endl;
    }
    return 0;
}