#include <iostream>
#include <array>
using namespace std;

const int MAX_SB = 50;

typedef array<int, MAX_SB> TSbIdent;
typedef array<double, MAX_SB> TMarks;

struct student {
    string id;
    TSbIdent subjects;
    TMarks marks;
    int nsb;
};

int main () {
    double mingrade(student a);
    bool marksurpass(student a, double vmark);
}
double mingrade(student a) {
    double res = a.marks[0];
    for(int i = 1; i < a.nsb; i++) {
        if(a.marks[i] < res) res = a.marks[i];
    }
    return res;
}

bool marksurpass(student a, double vmark) {
    int i = 0;
    while((i < a.nsb - 1) and (a.marks[i] > vmark)) i++;
    return (a.marks[i] > vmark);
}