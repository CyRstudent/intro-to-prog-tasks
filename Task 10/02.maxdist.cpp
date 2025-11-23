#include <iostream>
#include <array>
using namespace std;

const int N = 6;
typedef array<int, N> TVec;

int main () {
    int maxDistBetwReps(TVec a, int x);
    
    cout << maxDistBetwReps((TVec){{10,10,4,3,5,6}},10) << endl; // 1
    cout << maxDistBetwReps((TVec){{ 1, 3,4,3,5,3}}, 3) << endl; // 4
    cout << maxDistBetwReps((TVec){{ 1, 3,4,3,5,6}}, 1) << endl; // 0
    cout << maxDistBetwReps((TVec){{ 1, 3,4,3,5,6}},33) << endl; //-1
    return 0;

}

int maxDistBetwReps(TVec a, int x) {
    int dist = -1;
    int i = 0;
    while((i < N) and (a[i] != x)) i++;
    if(i < N) {
        int f = 0;
        for(int j = i; j < N; j++) {
            if(a[j] == x) f = j;
        }
        dist = f - i;
    }
    return dist;
}