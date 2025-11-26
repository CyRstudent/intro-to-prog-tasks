#include <iostream>
#include <array>
using namespace std;

const int N = 4;
typedef array<string, N> TListWords;

int main () {
    TListWords under(string s);
    void printWords(TListWords a);
    printWords(under("a number: 3 is _fine_"));
    printWords(under(" 1 is not a word"));

    return 0;
}

TListWords under(string s) {
    bool comp(char a);
    TListWords newlist();

    TListWords res = newlist();

    int counter = 0;
    int i = 0;
    s += '.';

    string tempstring = "";
    while((counter < N) and ((unsigned __int64)i < s.size())) {
        char c = s[i];
        if(comp(c)) { // If the current character is a character specified within the conditions of the exercise...
            tempstring += c; // We add it to a temporal string
        } else {
            if((i > 0) and comp(s[i - 1])) { // On the other hand, if the iterator is greater than zero and the previous character of the string was a character, it means we had a word
                res[counter] = tempstring; // We add it to the correspondent position
                counter++;
            }
            tempstring = ""; // We reset the string and wait for a new word to form
        }
        i++;
    }
    return res;
}
void printWords(TListWords a) {
    for(int i = 0; i < N; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

bool comp(char a) {
    bool s1 = a >= 'a';
    bool s2 = a <= 'z';
    bool s3 = (a == '_');
    return ((s1 and s2) or s3);
}

TListWords newlist() {
    TListWords res;
    for(int i = 0; i < N; i++) {
        res[i] = "";
    }
    return res;
}