#include <iostream>
using namespace std;

int main () {
    bool isLeap(int n);
    int x;
    cout << "Introduce a year: ";
    cin >> x;
    string res = isLeap(x)?"leap":"not leap";
    cout << "The year is " << res << endl;
    return 0;
}

bool isLeap(int n) {
    bool s1 = (n%4 == 0);
    bool s2 = !(n%100 == 0);
    bool s3 = (n%400 == 0);
    return ((s1 and s2) or s3);
}