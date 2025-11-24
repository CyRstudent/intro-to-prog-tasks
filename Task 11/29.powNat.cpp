#include <iostream>
using namespace std;

typedef string TNat;

int main () {
    TNat pow(TNat b, TNat exp);
    cout << (pow("25389450", "9") == "4384091780519125014579849117819331849485377415934587890625000000000") << endl;
    return 0;
}

TNat pow(TNat b, TNat exp) {
    TNat multBy(TNat a, TNat b);
    int str2int(string s);

    TNat res = "1";
    int intexp = str2int(exp);
    for(int i = 0; i < intexp; i++) {
        res = multBy(res, b);
    }

    return res;
}

TNat multBy(TNat a, TNat b) {
    TNat sumNat(TNat a, TNat b);
    void orderPair(TNat& x, TNat& y);
    string int2str(int n);
    int toNum(char c);
    string zeros(int n);

    string res = "";
    orderPair(a, b);
    // Main loop - Loops through the bigger number
    for(int i = a.size() - 1; i >= 0; i--) {
        // We define the digit we're going to be multiplying the lower number with, as well as the number of
        // zeroes we will be adding to the end (because of how the multiplication algorithm works)
        int d1 = toNum(a[i]);
        string final_zeroes = zeros(a.size() - (i + 1));
        string tempres = "";
        // Second loop - Loops through the smaller number
        for(int j = b.size() - 1; j >= 0; j--) {
            int d2 = toNum(b[j]);
            string starting_zeroes = zeros(b.size() - (j + 1));
            // Result of the small operation
            int sum =  d1*d2;
            string temp_tempres = int2str(sum) + starting_zeroes;
            tempres = sumNat(tempres, temp_tempres);
        }
        tempres += final_zeroes;
        res = sumNat(res, tempres);
    }
    return res;
}

TNat sumNat(TNat a, TNat b) {
    int toNum(char c);
    char toChar(int n);

    TNat res = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while((i >= 0) or (j >= 0) or (carry > 0)) {
        int d1 = (i >= 0)?toNum(a[i]):0;
        int d2 = (j >= 0)?toNum(b[j]):0;
        int sum = d1 + d2 + carry;
        carry = sum/10;
        sum %= 10;
        res += toChar(sum);
        i--;
        j--;
    }
    string newr = "";
    for(int k = res.size() - 1; k >= 0; k--) {
        newr += res[k];
    }
    int k = 0;
    while((k < newr.size() - 1) and (newr[k] == '0')) k++;
    newr = newr.substr(k);

    return newr;
}

void orderPair(TNat& x, TNat& y) {
    int toNum(char c);

    bool criteria = true; // Criteria is true if and only if x >= y

    if(x.size() == y.size()) {
        if(x != y) {
            int i = 0;
            while((i < x.size()) and (x[i] == y[i])) i++;
            criteria = not(toNum(x[i]) < toNum(y[i]));
        }
    } else {
        criteria = (x.size() > y.size());
    }

    // If criteria is false, we swap the values
    if(not criteria) {
        TNat temp = x;
        x = y;
        y = temp;
    }
}

string int2str(int n) {
    char toChar(int n);
    /**
     * Just a quick note:
     * While this is the most logical version of the function, it is also the most efficient.
     * The other way to do so is to start a loop based on the number of digits calculalated by a while loop, and then go down using powers of 10 and adding them to the resulting string
     * Time complexity for the version written below: O(d), where "d" is the number of digits.
     * Time complexity for the other version: O((log n)^2) => The first one is far more efficient.
     */
    string invres = "";
    while(n > 0) {
        char toadd = toChar(n%10);
        invres += toadd;
        n /= 10;
    }
    string res = "";
    for(int i = invres.size()-1; i >= 0; i--) {
        res += invres[i];
    }
    return res;
}

int toNum(char c) {
    return (int)(c - '0');
}

char toChar(int n) {
    return (char)(n + (int)'0');
}

string zeros(int n) {
    string res = "";
    for(int i = 0; i < n; i++) {
        res += '0';
    }
    return res;
}

int str2int(string s) {
    int pow(int a, int b);
    int n = 0;
    for(int i = 0; i < s.size(); i++) {
        int t = (int)s[i]-(int)'0';
        t *= pow(10, s.size()-i-1);
        n += t;
    }
    return n;
}

int pow(int a, int b) {
    int res = 1;
    for(int i = 0; i < b; i++) res *= a;
    return res;
}