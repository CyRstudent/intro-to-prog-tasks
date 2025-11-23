#include <iostream>
using namespace std;

int main () {
    bool palindrome(string s);

    string s;
    cout << "Introduce something: ";
    getline(cin, s);

    string res = "The string is ";
    if(not palindrome(s)) res += "not ";
    res += "palindromic";
    cout << res << endl;
    
    return 0;
}

bool palindrome(string s) {
    // The string ignoring any character other than the lowercase alphabet, as per the exercise instructions.
    string newstr = "";
    for(int i = 0; i < s.size(); i++) {
        if((s[i]>='a') and (s[i]<='z')) newstr += s[i];
    }
    string rev = "";
    for(int j = newstr.size()-1; j >= 0; j--) {
        rev += newstr[j];
    }
    return (rev == newstr);
}





