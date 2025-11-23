#include <iostream>
using namespace std;

int main () {
    int n, d, h, m, s;
    const int conv1 = 60;
    const int conv2 = 24;
    cout << "Introduce a number of seconds: ";
    cin >> n;
    s = n%conv1;
    m = ((n-s)/conv1)%conv1;
    h = ((n-((m*conv1)+s))/(conv1*conv1))%conv2;
    d = (n-((m*conv1) + (h*conv1*conv1)+s))/(conv1*conv1*conv2);
    cout << "The quantity of seconds introduced (" << n << ") is the equivalent to " << d << " days, " << h << " hours, " << m << " minutes and " << s << " seconds." <<endl;
    return 0;
}