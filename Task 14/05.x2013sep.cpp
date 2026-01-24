#include <iostream>
#include <array>
using namespace std;

const int MAXDIFNUMS = 50;
const int MAXREPETIT = 50;

struct TNum {
    int n = 0;
    int pos = -1;
};

typedef array<TNum, MAXDIFNUMS> TVec;

struct TOpenArr {
    int size = 0;
    TVec nums;
};

int main () {
    void updateGreatests(TOpenArr &a, int n, int counter);

    int m;
    int counter = 0;
    int n;

    TOpenArr res;

    cout << "Introduce a valid number";
    while((cin >> m) and not((m > 0) and (m <= MAXDIFNUMS))) cout << "Introduce a VALID number: ";
    res.size = m;

    cout << "Start introducing numbers (0 to end): ";
    while(((cin >> n) and (n != 0))) {
        counter++;
        updateGreatests(res, n, counter);
    }

    int top = (counter < m)?counter:m;
    for(int i = 0; i < top; i++) {
        cout << res.nums[i].n << ": " << res.nums[i].pos << endl;
    }

    return 0;
}

void updateGreatests(TOpenArr &a, int n, int counter) {
    int accessPos(TOpenArr a, int n);
    void sortOpen(TOpenArr &a);

    sortOpen(a);
    int p = accessPos(a, n);
    if(p != -1) {
        a.nums[p].n = n;
        a.nums[p].pos = counter;
    }
}

int accessPos(TOpenArr a, int n) {
    /**
     * Returns the access position of a number inside a **SORTED** Open Array
     * Returns -1 if the number is lower than all of the numbers
     */
    int i = 0;
    while((i < a.size) and (n < a.nums[i].n)) i++;
    if(n < a.nums[i].n) i = -1;
    return i;

}

void sortOpen(TOpenArr &a) {
    void swap(TNum &a, TNum &b);
    for(int i = (a.size - 1); i >= 1; i--) {
        for(int j = 0; j <i; j++) {
            if(a.nums[j].n > a.nums[j + 1].n) {
                swap(a.nums[j], a.nums[j + 1]);
            }
        }
    }
}

void swap(TNum &a, TNum &b) {
    TNum t = a;
    a = b;
    b = t;
}