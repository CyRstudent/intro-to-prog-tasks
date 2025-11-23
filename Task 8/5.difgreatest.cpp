#include <iostream>
using namespace std;

int main () {
    void varact(int &an, int &an1, int n);

    int an = INT_MIN+1;
    int an1 = INT_MIN;
    int n;

    cout << "Start introducing numbers: ";
    cin >> n;
    while(n != 0) {
        varact(an, an1, n);
        cin >> n;
    }
    cout << an - an1 << endl;

    return 0;
}

void varact(int &an, int &an1, int n) {
    if(n > an) {
        an1 = an;
        an = n;
    } else if(n > an1) an1 = n;
}