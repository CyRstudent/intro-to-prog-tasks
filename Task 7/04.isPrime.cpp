#include <iostream>
using namespace std;

int main () {
    void isPrime(int n);
    int n;
    cout << "Introduce: ";
    cin >> n;
    isPrime(n);
    return 0;
}
void isPrime(int n) {
    //Since I am going to reuse a bool function for the next exercises, I will just declare this void because the exercise told me so
    bool prime(int n);
    string ans = "The number " + to_string(n) + " is ";
    if(not prime(n)) ans += "not ";
    ans += "prime";

    cout << ans << endl;

}
bool prime(int n) {
    bool answer;
    if (n <= 1) answer = false;
    else if (n == 2) answer = true;
    else if (n % 2 == 0) answer = false;
    else {
        int d = 3;
        while (d * d < n and n % d != 0) d += 2;
        answer = d*d > n;
    }
    return answer;

}