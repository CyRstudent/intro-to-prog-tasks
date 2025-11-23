#include <iostream>
#include <array>
using namespace std;

int main () {
    int find(string s, string pat);
    array<string, 3> tests = {{"Potatoes are not a fruit", "This is another test", "This tests returns -1"}};
    array<string, 3> subt = {{
        "tatoe", // 2
        "another", // 8
        "Universitat" // -1
    }};
    cout << "Phrase\t" << "Substring\t" << "Result" << endl;
    for(int i = 0; i < 3; i++) {
        int n = find(tests[i], subt[i]);
        cout << tests[i] << '\t' << subt[i] << '\t' << n << endl;
    }
    return 0;
}

int find(string s, string pat) {    
    int i = 0;
    string res = "";
    while((i < (s.size() - (s.size()%pat.size()))) and res != pat) {
        res = "";
        for(int j = 0; j < pat.size(); j++) {
            res += s[i + j];
        }
        i++;
    }
    return ((res == pat)?(i - 1):(-1));
}