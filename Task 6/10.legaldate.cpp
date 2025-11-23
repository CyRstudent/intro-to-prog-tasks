#include <iostream>
using namespace std;

int main () {
    bool isValid(int d, int m, int y);
    int d, m, y;

    cout << "Introduce a date in the format DD MM YYYY: ";
    cin >> d >> m >> y;
    if (isValid(d, m , y)) cout << "legal date"; else cout << "illegal date";
    cout << endl;
    return 0;
}
bool isValid(int d, int m, int y) {
    bool isLeap(int n);

    bool validm = (m > 0) and (m < 13);
    bool validy = y>=0;
    bool validd = (d > 0) and (d < 32);
    switch(m) {
        case 2:
            if(isLeap(y)) {
                validd = (d > 0) and (d < 30);
            } else {
                validd = (d > 0) and (d < 29);
            }
            break;
        case 4: case 6: case 9: case 11:
            validd = (d > 0) and (d < 31);
            break;
    }

    return (validd and validm and validy);
}
bool isLeap(int n) {
    bool s1 = (n%4 == 0);
    bool s2 = !(n%100 == 0);
    bool s3 = (n%400 == 0);
    return ((s1 and s2) or s3);
}