#include <iostream>
using namespace std;

int main () {
    for (int i = 1500; i <= 2700; i++) {
        if(i%35 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}