#include<iostream>
#include <array>
using namespace std;

const int R = 4;
const int C = 3;

typedef array<array<int, C>, R> TMat;
typedef array<int, 2> point;

int main () {
    void test(TMat a);

    array<TMat, 3> testCases = {{
        {{
            {3, 1, 2},
            {2, 16, 2},
            {1, 3, 2},
            {5, 1, 6}
        }},
        {{
            {2, 1, 7},
            {2, 5, 8},
            {2, 2, 1},
            {7, 7, 2}
        }},
        {{
            {2, 1, 7},
            {2, 5, 8},
            {2, 2, 1},
            {7, 6, 9}
        }}
    }};

    for(int i = 0; i < 3; i++) {
        test(testCases[i]);
    }
    return 0;
}

void test(TMat a) {
    void display(TMat a);
    point firstCent(TMat a);

    point res = firstCent(a);

    cout << "Matrix: " << endl;
    display(a);

    cout << "First cell satisfying the condition: (" << res[1] << ", " << res[0] << ')' << endl;
}

void display(TMat a) {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

point firstCent(TMat a) {
    int sumNeigbours(TMat a, point p);

    point res = {{-1, -1}};
    bool found = false;
    int i = 0;
    while((i < R) and (not found)) {
        int j = 0;
        while((j < C) and (not found)) {
            point p = {{i, j}};
            if(sumNeigbours(a, p) == a[i][j]) {
                res = p;
                found = true;
            }
            j++;
        }
        i++;
    }
    return res;
}

int sumNeigbours(TMat a, point p) {
    bool canBeChecked(point a);

    int sum = 0;
    for(int tmpy = 0; tmpy < 3; tmpy++) {
        int currenty = (p[0] - 1 + tmpy);
        for(int tmpx = 0; tmpx < 3; tmpx++) {
            int currentx = (p[1] - 1 + tmpx);
            if(
                not((currentx == p[1]) and (currenty == p[0]))
                and canBeChecked((point){{currenty, currentx}})
            ) {
                sum += a[currenty][currentx];
            }
        }
    }
    return sum;
}

bool canBeChecked(point a) {
    bool s1 = ((a[0] < R) and (a[0] >= 0));
    bool s2 = ((a[1] < C) and (a[1] >= 0));
    return (s1 and s2);
}