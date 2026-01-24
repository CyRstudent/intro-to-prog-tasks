#include <iostream>
#include <array>
using namespace std;

const int N = 100;

typedef array<int, N> TVector;

struct TOpenArr {
    int n;
    TVector arr;
};

int main () {
    void printOArr(TOpenArr a);
    TOpenArr sumOArr(TOpenArr a, TOpenArr b);

    TOpenArr a = {3, {{1, 2, 3}}};
    TOpenArr b = {3, {{3, 2, 1}}};
    printOArr(sumOArr(a, b));
    
    return 0;
}

void printOArr(TOpenArr a) {
    for(int i = 0; i < a.n; i++) {
        cout << a.arr[i] << " ";
    }
    cout << endl;
}

TOpenArr sumOArr(TOpenArr a, TOpenArr b) {
    void swap(TOpenArr &a, TOpenArr &b);
    
    if(a.n < b.n) swap(a, b);
    for(int i = 0; i < b.n; i++) {
        a.arr[i] += b.arr[i];
    }
    return a;
}

void swap(TOpenArr& a, TOpenArr& b) {
    TOpenArr temp = a;
    a = b;
    b = temp;
}