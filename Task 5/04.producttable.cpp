#include <iomanip>
#include <iostream>
using namespace std;

int main () {
    const int low = 1;
    const int upper = 10;
    for(int i = low; i <= upper; i++) {
        for(int j = low; j <= upper; j++) {
            cout << setw(4) << j*i;
        }
        cout << endl;
    }
    return 0;
}