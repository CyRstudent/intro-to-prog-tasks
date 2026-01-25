#include <iostream>
#include <array>
using namespace std;

const int N = 5;
typedef array<int, N> TVec;

int main () {
    void centreOfVector(TVec v, bool& exists, int& c);
    void printVec(TVec v);

    array<TVec, 2> testCases = {{
        {{6, 2, 3, 0, 1}},
        {{1, 2, 1, 1, 0}}
    }};

    for(int i = 0; i < 2; i++) {
        cout << "The vec is: ";
        printVec(testCases[i]);

        bool centreAvailable;
        int index;
        centreOfVector(testCases[i], centreAvailable, index);
        if(centreAvailable) {
            cout << "Centre = " << index;
        } else {
            cout << "No centre available";
        }
        cout << endl;
    }

    return 0;
}

void centreOfVector(TVec v, bool& exists, int& c) {
    c = -1;
    exists = false;
    while((c < (N - 1)) and (not exists)) {
        c++;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < c; i++) {
            sum1 += ((c - i)*v[i]);
        }
        for(int j = (c + 1); j < N; j++) {
            sum2 += ((j - c)*v[j]);
        }
        exists = (sum1 == sum2);
    }
}

void printVec(TVec v) {
    for(int i = 0; i < N; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}