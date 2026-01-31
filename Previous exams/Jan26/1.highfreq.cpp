/*
Sáez Madrid, Hugo
Software Engineering
PC0626
*/

#include <iostream>
#include <array>
using namespace std;

const int MAX = 20;
typedef array<int, MAX> TVec;

struct TList {
    TVec vec;
    int usedSpace = 0;
};

const int NAT = 10;
typedef array<int, NAT> TFreqs; // The array contains the frequency of each number (which is given by the index)

int main () {
    cout << "Hugo Sáez Madrid" << endl;

    void addNum(TList& a, int n);
    void printList(TList a);
    void maxFreq(TList a, int& n, int& freq);
    void purgeList(TList& a, int n, int freq);

    int n;
    TList a;

    cout << "Start introducing numbers: ";
    while((cin >> n) and (n >= 0) and (a.usedSpace < MAX)) addNum(a, n);

    printList(a);

    if(a.usedSpace == 0) {
        cout << "Empty list" << endl;
    } else {
        int num = 0;
        int freq = 0;

        maxFreq(a, num, freq);

        cout << "The smallest number with the highest frequency is " << num << " with a frequency of " << freq << endl;

        purgeList(a, num, freq);
        cout << "Purged list: ";
        if(a.usedSpace == 0) {
            cout << "Empty list";
        } else {
            printList(a);
        }
        cout << endl;
    }

    return 0;

}

void addNum(TList& a, int n) {
    if(((n >= 0) and (n <= 9)) and (a.usedSpace < MAX)) {
        a.vec[a.usedSpace] = n;
        a.usedSpace++;
    }
}


void printList(TList a) {
    for(int i = 0; i < a.usedSpace; i++) {
        cout << a.vec[i] << ' ';
    }
    cout << endl;
}

void maxFreq(TList a, int& n, int& freq) {
    TFreqs freqGen(TList a);

    TFreqs freqs = freqGen(a);

    for(int i = 0; i < NAT; i++) {
        if(freqs[i] > freq) {
            n = i;
            freq = freqs[i];
        }
    }

}

TFreqs freqGen(TList a) {
    TFreqs res;

    for(int i = 0; i < NAT; i++) res[i] = 0; // We initialize the array

    for(int i = 0; i < a.usedSpace; i++) {
        res[a.vec[i]]++;
    }
    return res;
}

void purgeList(TList& a, int n, int freq) {
    int indexFinder(TList a, int c, int n);
    for(int i = 0; i < a.usedSpace; i++) {
        if(a.vec[i] == n) {
            int ind = indexFinder(a, i, n);
            if(ind != -1) {
                a.vec[i] = a.vec[ind];
                a.vec[ind] = n;
            }
        }
    }
    a.usedSpace -= freq;
}

int indexFinder(TList a, int c, int n) {
    int i = c;
    bool found = false;
    while((i < a.usedSpace) and (not found)) {
        found = (a.vec[i] != n);
        if(not found) i++;
    }
    if(not found) i = -1;
    return i;
}
