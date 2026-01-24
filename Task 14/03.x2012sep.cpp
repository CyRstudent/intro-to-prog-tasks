#include <iostream>
#include <array>
using namespace std;

const int MAXPAL = 50;
const int MAXREP = 50;

typedef array<int, MAXREP> TPosMap;


struct TWord {
    string word;
    int freq = 0;
    TPosMap posmap;
};

typedef array<TWord, MAXPAL> TDiffWords;

struct TOpenArr {
    TDiffWords vec;
    int size;
};

int main () {
    void resFn(TDiffWords &db);
}