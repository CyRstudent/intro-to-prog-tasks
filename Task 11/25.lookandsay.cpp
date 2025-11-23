#include <iostream>
#include <array>
using namespace std;
const int N = 10;
typedef array<int, N> nums;

int main () {
    string lookandsay(string seed);

    string prev = "1";
    for(int i = 0; i < 20; i++) {
        string r = lookandsay(prev);
        cout << r << endl;
        prev = r;
    }
    return 0;
}

string lookandsay(string seed) {
    void initialize(nums &a);

    string res = "";
    nums counter;
    initialize(counter);

    // We loop over the string to know how much a number is repeated:
    for(int i = 0; i < seed.size(); i++) {
        int n = seed[i] - '0';
        counter[n]++;
    }

    // Now, we build the resulting string
    for(int i = 0; i < N; i++) {
        if(counter[i] != 0) {
            res += char(counter[i] + '0');
            res += char(i + '0');
        }
    }
    return res;
}

void initialize(nums &a) {
    for(int i = 0;i < N; i++) {
        a[i] = 0;
    }
}