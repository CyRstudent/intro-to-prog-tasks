#include <iostream>
using namespace std;
int main () {
    char c;
    string res = "It is a ";
    cout << "Introduce a chart: ";
    cin >> c;
    int n = int(c);
    if ((n >= 97) and (n <= 122)) {
        res += "lowercase ";
        if ((n == 97) or (n == 101) or (n == 105) or (n == 111) or (n == 117)) {
            res += "vowel";
        } else {
            res += "consonant";
        }
    } else if ((n >= 65) and (n <= 90)) {
        res += "uppercase";
        if ((n == 65) or (n == 69) or (n == 73) or (n == 79) or (n == 85)){
            res += "vowel";
        } else {
            res += "consonant";
        }
    } else if ((n >= 48) and (n <= 57)) {
        res += "digit";
    } else {
        res = "";
        res += "It is something else";
    }
    cout << res << endl;
    return 0;
}