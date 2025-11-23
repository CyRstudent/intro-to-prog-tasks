#include <iostream>
#include <array>
using namespace std;

typedef array<int, 2> TCoord;

int main () {
    int manhattanDistance(TCoord pointA, TCoord pointB);
    cout << manhattanDistance({{1, 1}}, {{1, 1}}) << endl;
    return 0;
}

int manhattanDistance(TCoord pointA, TCoord pointB) {
    int abs(int n);
    int x = abs(pointA[0] - pointB[0]);
    int y = abs(pointA[1] - pointB[1]);
    return (x+y);
}
int abs(int n) {
    if(n < 0) n*=(-1);
    return n;
}