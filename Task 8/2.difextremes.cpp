#include <iostream>
using namespace std;

int main () {
    int n = 1;
    int h = INT_MIN;
    int l = INT_MAX;
    cout << "Introduce a sequence of number ending in 0: ";
    cin >> n;
    while(n != 0) {
        if(n > h) h = n;
        if(n < l) l = n;
        cin >> n;
    }
    cout << (h-l) << endl;
    
    return 0;
}