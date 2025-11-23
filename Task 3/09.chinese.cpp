#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<string> animals = {"Rat", "Ox", "Tiger", "Hare", "Dragon", "Snake", "Horse", "Ram", "Monkey", "Rooster", "Dog", "Pig"};
    int n;
    cout << "Enter your year of birth: ";
    cin >> n;
    n = (n + 8)%12;
    cout << "Your Zodiac sign: " << animals[n] << endl;
    return 0;
}