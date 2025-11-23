#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1000;
typedef array<float, N> TVec;

int main() {
    srand(time(NULL));
    void randFloatArr(TVec& a, float min, float max);
    TVec a;
    randFloatArr(a, 0, 100);
    float sum = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i];
        cout << a[i] << ' ';
    }
    cout << endl;
    sum /= (float)N;
    cout << sum << endl;
    return 0;
}
void randFloatArr(TVec& a, float min, float max) {
    for(int i = 0; i < a.size(); i++) {
        a[i] = (float(rand())/RAND_MAX) * (max-min) + min;
    }
}
