#include <iostream>
#include <array>
using namespace std;

struct TElement {
    string id;
    int n;
};

const int N = 118;
typedef array<TElement, N> TVec;

struct TMolecule {
    int n;
    TVec arr;
};

int main () {
    TMolecule string2Molec(string s);
    void printMol(TMolecule a);
    array<string, 5> testCases = {{"NaOH", "Rb2SeO4", "H2SO4", "H2O", "K2Cr2O7"}};

    for(int i = 0; i < 5; i++) {
        TMolecule res = string2Molec(testCases[i]);
        printMol(res); // The proof that the answer to this exercise works is that the output matches exactly the string of the test case
    }
    return 0;
}

TMolecule string2Molec(string s) {
    int charType(char c);
    void initialize(TMolecule& a);
    void resetElement(TElement &a);

    TMolecule res;
    initialize(res);

    TElement temp;
    resetElement(temp);

    s += 'A'; // We add an uppercase letter so that it triggers the addition of the last element

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        switch(charType(c)) {
            case 0: //We've encountered a new element, by definition (because new elements always start with an upper case letter of the alphabet)
                if(temp.id != "") { //If the temporary element wasn't empty, it means we need to add the temporary element and start with a new one
                    if(temp.n == 0) temp.n++; // If the temporary element wasn't already assigned a number, we just add one
                    res.arr[res.n] = temp; // We add the temporary element to the array of elements
                    res.n++;
                }
                resetElement(temp);
                temp.id += c;
                break;
            case 1:
                temp.id += c;
                break;
            case 2:
                temp.n = (int)(c - '0');
                break;
        }
    }
    return res;
}

void printMol(TMolecule a) {
    for(int i = 0; i < a.n; i++) {
        TElement e = a.arr[i];
        cout << e.id;
        if(e.n > 1) cout << e.n;
    }
    cout << endl;
}

// Util
int charType(char c) {
    /**
     * Returns 0 if it is an upper case letter of the alphabet
     * Returns 1 if it is a lower case letter of the alphabet
     * Returns 2 if it is a number
     * Returns -1 if it's none of the above
     */

    int res = -1;
    bool s1 = (c >= 'A' and c <= 'Z');
    bool s2 = (c >= 'a' and c <= 'z');
    bool s3 = (c >= '0' and c <= '9');

    if(s1) res = 0;
    else if(s2) res = 1;
    else if(s3) res = 2;

    return res;
}

void initialize(TMolecule& a) {
    a.n = 0;
    for(int i = 0; i < N; i++) {
        a.arr[i] = {"", 0};
    }
}

void resetElement(TElement &a) {
    a.id = "";
    a.n = 0;
}