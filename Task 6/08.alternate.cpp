#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    long double alternate(int n);
    cout << fixed << setprecision(17);
    const long double ln2 = 0.69314718055994530942L;
    const int lim = 2147483646;
    for(int i = 1; i <= lim; i*=2) {
        double res = alternate(i);
        cout << "i = " << i << " "<< (100*i)/(double)lim <<"\tResult: " << res << "\t delta = " << res - ln2 << endl;
    }
    return 0;
}
long double alternate(int n) {
    long double res = 0.0L;
    for(int i = 1; i <= n; i++) {
        long double term = (1.0L/i);
        if(i%2 == 0) term*=(-1);
        res += term;
    }
    return res;
}