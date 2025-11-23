#include <iostream>
#include <array>
using namespace std;

const int N = 6;
typedef array<int, N> TVec;

int main () {

    void closestSum(TVec ns, int goal, int& a, int& b);
    int p1, p2;

    cout << 'x' << '\t' << 'y' << endl;
    closestSum((TVec){{9,-3, -10, -4, -5, 0}}, 4, p1, p2);
    cout << p1 << '\t' << p2 << endl;
    closestSum((TVec){{1, -1, -2,-4, 0, 0}}, 0, p1 , p2);
    cout << p1 << '\t' << p2 << endl;
    closestSum((TVec){{0, 2, -10, 10, 5, 4}}, 0, p1, p2);
    cout << p1 << '\t' << p2 << endl;

    return 0;
}

void closestSum(TVec ns, int goal, int& a, int& b) {
    int abs(int n);
    int currentClose = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(abs(ns[i] + ns[j] - goal) < currentClose) {
                a = ns[i];
                b = ns[j];
                currentClose = abs(a + b - goal);
            }
        }
    }
}

int abs(int n) {
    if(n < 0) n*=(-1);
    return n;
}