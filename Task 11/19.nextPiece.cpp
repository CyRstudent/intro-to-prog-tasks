#include <iostream>
using namespace std;
// The following exercise is wrong entirely.

int main () {
    string nextPiece(string s, char sep='\0');
    cout << nextPiece("*abc *cde**fg*", '*') << endl; // -> ""
    for(int i  = 0; i < 4; i++) {
        cout << nextPiece("*abc *cde**fg*") << endl;
    }
    return 0;
}

string nextPiece(string s, char sep='\0') {
    string substrneg(string s, int from, int end=-1);

    static char theSep = '\0';
    static int ind = 0;
    
    string res = "";

    if(sep != '\0') {
        theSep = sep;
        ind = 0;
    }
    
    int size = s.size();
    if(ind < size) {
        int i = ind;
        while((ind < size) and (s[ind] != theSep)) ind++;
        res = substrneg(s, i, ind-i);
        ind++;
    }
    return res;

}

string substrneg(string s, int from, int end=-1) {
    string res = "";
    if(from < 0) from += s.size();
    if(end < 0) end += s.size();
    if(not((from > s.size()-1) or (end > s.size()-1))) {
        for(int i = from; i <= end; i++) {
            res += s[i];
        }
    }
    return res;
}