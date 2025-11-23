#include <iostream>
using namespace std;
void printspaces (int j)  {
    for(int k = 1; k <= j; k++) {
        cout << " ";
    }
}
int main () {
    const int h = 5;
    const int n = 3;
    int sidew = h;
    int insidew = -1;
    for(int i = 1; i <= h; i++) {
        sidew--;
        insidew++;
        for(int j = 1; j <= n; j++) {
            if(i == 1) {
                printspaces(sidew);
                cout << '*';
                printspaces(sidew);
            } else {
                printspaces(sidew);
                cout << '*';
                printspaces(insidew);
                cout << '*';
                printspaces(sidew);
            }
        }
        cout << endl;
    }
}
