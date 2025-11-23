#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 8;
typedef array<int, N> TVec;

int main () {
    void trend(TVec a, int& trend, bool& ok);
    TVec a;
    int tr;
    bool rep;
    
    cout << "Introduce all 8 elements: ";
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    trend(a, tr, rep);

    if(!rep) {
        cout << "The series introduced has no trend" << endl;
    } else {
        cout << "Trend: " << tr << endl;
    }

    return 0;
}

void trend(TVec a, int& trend, bool& ok) {
    vector<int> counters;
    vector<int> identifiers; // The identifier 

    for(int i = 0; i < N; i++) {
        if(count(identifiers.begin(), identifiers.end(), a[i]) == 0) { // If we detect an element that hasn't been identified before...
            identifiers.push_back(a[i]); // We open a new slot for the new identifier
            counters.push_back(count(a.begin(), a.end(), a[i])); // We assign to the same index the amount of times the element is repeated in the array
        }
    }

    int maxcounter = counters[0];
    int max_index = 0;
    ok = true;

    for(int i = 1; i < counters.size(); i++) {
        int curcount = counters[i];
        if(curcount > maxcounter) {
            max_index = i;
            maxcounter = counters[i];
        }
        ok = (count(counters.begin(), counters.end(), curcount) <= 1);
    }

    trend = identifiers[max_index];
}