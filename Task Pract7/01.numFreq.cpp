#include <iostream>
#include <array>
using namespace std;

const int NFRE = 10;
const int NINT = 6;

typedef array<int,NINT> TVec;

struct TNumFreq {
    int n;
    int freq;
};

typedef array<TNumFreq, NFRE> TFreqs;

int main() {
    void writeFreqs(TFreqs a);
    TFreqs freqsOf(TVec a);

    writeFreqs(freqsOf((TVec){{10, 800, 4, 3, 4, 10}})); // 10:2 800:1 4:2 3:1
    writeFreqs(freqsOf((TVec){{10, 10, 10, 10, 10, 10}})); // 10:6

    return 0;
}

// Non-essential subprogram
void writeFreqs(TFreqs a) {
    cout << "Number: Frequency" << endl;
    for(int i = 0; i < NFRE; i++) {
        if(a[i].n != 0) cout << a[i].n << ": " << a[i].freq << endl;
    }
}

// Main point of the exercise
TFreqs freqsOf(TVec a) {
    // Utility
    void BubbleSort(TVec &a);
    TFreqs initialize();
    void purge(TVec &v);

    // We create a TVec which contains the numbers entered sorted and non-repeated;
    BubbleSort(a);
    TVec clearedSorted = a;
    purge(clearedSorted);

    // Now, we start the TFreqs which contains all non-repeated numbers as the parameter n, with freq = 0.
    TFreqs res = initialize();
    int counter = 0; // Will help us to get right the positions
    for(int i = 0; i < NINT; i++) {
        if(clearedSorted[i] != 0) {
            res[counter].n = clearedSorted[i];
            counter++;
        }
    }

    // Once we have the TFreqs properly defined, we loop over the input array
    counter = 0;
    for(int i = 0; i < NINT; i++) {
        // If it is starting the loop, we just add one to the frequency of the first element
        if(i == 0) {
            res[counter].freq++;
        } else {
            if(a[i] != a[i-1]) counter++;
            res[counter].freq++;
        }
    }
    return res;
}

// Bubble sort
void BubbleSort(TVec &a) {
    void swap(int &a, int &b);
    for(int i = a.size() - 1; i >= 1; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Initialization of an empty TFreqs
TFreqs initialize() {
    TFreqs res;
    for(int i = 0; i < NFRE; i++) {
        res[i].n = 0;
        res[i].freq = 0;
    }
    return res;
}

// Purge for non-repeated elements
void purge(TVec &v) {
    bool containedIn(TVec a, int x, int starting, int ending);
    for(int i = 1; i < NINT; i++) {
        if(containedIn(v, v[i], 0, i)) v[i] = 0;
    }
}

bool containedIn(TVec a, int x, int starting, int ending) {
    int incidents = 0;
    for(int i = starting; i < ending; i++) {
        if(a[i] == x) incidents++;
    }
    return (incidents != 0);
}