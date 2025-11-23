// Using arrays here is EXTREMELY inefficient
#include <iostream>
#include <array>

using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main () {
    void purge(TVec& v);
    TVec purgev2(TVec v);

    TVec a = {{1, 1, 1, 2, 1}};
    TVec newa = purgev2(a);
    purge(a);

    cout << "Procedure" << '\t' << "Function" << endl;
    for(int i = 0; i < N; i++) {
        cout << a[i] << '\t' << newa[i] << endl;
    }
    return 0;
}

void purge(TVec& v) {
    bool containedIn(TVec a, int x, int starting, int ending);
    for(int i = 1; i < N; i++) {
        if(containedIn(v, v[i], 0, i)) v[i] = 0;
    }
}

TVec purgev2(TVec v) {
    bool containedIn(TVec a, int x, int starting, int ending);
    TVec res;
    for(int i = 0; i < N; i++) {
        res[i] = (containedIn(v, v[i], 0, i))?0:v[i];
    }
    return res;
}

bool containedIn(TVec a, int x, int starting, int ending) {
    int incidents = 0;
    for(int i = starting; i < ending; i++) {
        if(a[i] == x) incidents++;
    }
    return (incidents != 0);
}