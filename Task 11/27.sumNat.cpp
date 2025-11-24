#include <iostream>
using namespace std;

typedef string TNat;

int main () {
    void test(TNat a, TNat b);
    test("1", "1");
    test("122345", "98765");
    test("1111222233333444455556666677778888999", "1111222233333444455556666677778888999");
    return 0;
}
void test(TNat a, TNat b) {
    TNat sumNat(TNat a, TNat b);
    cout << sumNat(a, b) << endl;
}
TNat sumNat(TNat a, TNat b) {
    TNat res = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while((i >= 0) or (j >= 0) or (carry > 0)) {
        int d1 = (i >= 0)?(a[i] - '0'):0;
        int d2 = (j >= 0)?(b[j] - '0'):0;
        int sum = d1 + d2 + carry;
        carry = sum/10;
        sum %= 10;
        res += char(sum + '0');
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