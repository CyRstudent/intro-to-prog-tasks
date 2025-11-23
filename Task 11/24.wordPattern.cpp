#include <iostream>
#include <array>

using namespace std;
const int N = 27;
typedef array<string, N> alfa;

int main () {
    bool wordPattern(string pat, string s);
    
    cout << wordPattern("abab", "truck car truck car") << endl; // true
    cout << wordPattern("aaaa", "dog dog dog dog") << endl; // true
    cout << wordPattern("abab", "apple banana banana apple") << endl;// false
    cout << wordPattern("abab", "apple banana apple banana") << endl;// true
    cout << wordPattern("aaaa", "cat cat dog cat") << endl; // false

    return 0;
}

bool wordPattern(string pat, string s) {
    int noOfWords(string s);
    void initialize(alfa &a);

    // Starting variables
    bool res = true;
    int wordn = noOfWords(s);
    int patsize = pat.size();
    
    alfa words;
    alfa mappedWords;
    initialize(words);
    initialize(mappedWords);

    // The program starts here
    if(patsize == wordn) {
        int ind = 0;
        string current = "";
        for(int i = 0; i <= s.size(); i++) {
            if((i == s.size()) or (s[i] == ' ')) {
                if(current != "") {
                    words[ind] = current;
                    ind++;
                    current = "";
                }
            } else {
                current += s[i];
            }
        }
        int j = 0;
        while((j < wordn) and res) {
            char c = pat[j];
            int identifier = c - 'a';

            if(mappedWords[identifier] == "") {
                int k = 0;
                bool used = false;
                bool done = false;
                while((k < N) and not done) {
                    if(mappedWords[k] == words[j]) {
                        used = true;
                        done = true;
                    }
                    k++;
                }
                if(not used) {
                    mappedWords[identifier] = words[j];
                } else res = false;
            } else res = (mappedWords[identifier] == words[j]);
            j++;
        }
    } else {
        res = false;
    }

    return res;
}

int noOfWords(string s) {
    bool alphabet(char a);

    int switcher = 0;
    int n = 0;
    if(alphabet(s[s.size()-1])) s += '.';
    
    for(int i = 0; i < s.size(); i++) {
        if(alphabet(s[i])) {
            if(switcher == 0) switcher++;
        } else {
            if(switcher == 1) {
                n++;
                switcher -= 1;
            }
        }
    }
    return n;
}

bool alphabet(char a) {
    bool s1 = a >= 'a';
    bool s2 = a <= 'z';
    bool s3 = a >= 'A';
    bool s4 = a <= 'Z';
    return ((s1 and s2) or (s3 and s4));
}

void initialize(alfa &a) {
    for(int i = 0;i < N; i++) {
        a[i] = "";
    }
}