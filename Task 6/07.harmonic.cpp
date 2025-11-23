#include <iostream>
#include <iomanip>
using namespace std;


int main () {
    long double harmonic( __int64 n);

    cout << fixed << setprecision(17);

    __int64 n;
    cout << "Introduce a natural number: ";
    cin >> n;

    long double a_n1 = harmonic(n);
    long double a_n2 = harmonic(n + 1);

    cout << "The harmonic series for n = " << n << " is: " << a_n1 << endl;
    cout << "The harmonic series for n+1 = " << a_n2 << endl;
    //
    cout << "The ratio of the harmonic series for said values is: " <<a_n2/a_n1 << endl;
    
    if(a_n1 < a_n2) {
        cout << "The ratio test is greater than 1 because the harmonic series for n is lower than the harmonic series for n+1, thus the series diverges q.e.d" << endl;
    } else {
        cout << "The ratio test is less than 1, thus the series converges and something is wrong with the code I wrote" << endl;
    }
    
    return 0;
}

long double harmonic( __int64 n) {
    long double res = 0.0L;
    for(__int64 i = 1; i <= n; i++) {
        res += (1.0L / i);
    }
    return res;
}
