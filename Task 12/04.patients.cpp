#include <iostream>
#include <array>
using namespace std;

const int MAX_HOURS = 24*31;
const int MAX_GEN = 1000;

typedef array<int, MAX_HOURS> TBPressure;
typedef array<double, MAX_GEN> TGenExp;

struct TPatient {
    string id;
    TBPressure bp;
    TGenExp GenExp;
    int GenExpn;
};

int main () {
    int maxbp(TPatient a);
    void firstmax(TPatient a, int& day, int& hour);
    int maxbpsurpass(TPatient a, int bp);
    
    return 0;
}

int maxbp(TPatient a) {
    int max = INT_MIN;
    for(int i = 0; i < MAX_HOURS; i++) {
        int n = a.bp[i];
        if(n > max) max = n;
    }

    return max;
}

void firstmax(TPatient a, int& day, int& hour) {
    int i = 1;
    while(not (
        (a.bp[i - 1] < a.bp[i])
        and (a.bp[i + 1] < a.bp[i])
    ) and (i < (MAX_HOURS - 1))) i++;

    day = (i%24);
    hour = (i - (day * 24));
}

int maxbpsurpass(TPatient a, int bp) {
    int counter = 0;
    for(int i = 0; i < MAX_HOURS; i++) {
        if(a.bp[i] >= bp) counter++;
    }
    return counter;
}