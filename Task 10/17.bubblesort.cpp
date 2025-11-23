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
    void BubbleSort(TVec &a);
    TVec a;
    randFloatArr(a, 0, 100);
    cout << "Unsorted array below: " << endl;
    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    cout << "Sorted array: " << endl;
    BubbleSort(a);
    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
void randFloatArr(TVec& a, float min, float max) {
    for(int i = 0; i < a.size(); i++) {
        a[i] = (float(rand())/RAND_MAX) * (max-min) + min;
    }
}
void BubbleSort(TVec &a) {
    void swap(float &a, float &b);
    for (int top = a.size() - 1; top >= 1; top--)
        for (int i = 0; i < top; i++)
            if ( a[i] > a[i + 1]) swap(a[i], a[i + 1]);
}
void swap(float &a, float &b) {
    float t = a;
    a = b; 
    b = t;
}