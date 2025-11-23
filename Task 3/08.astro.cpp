#include <iostream>
using namespace std;

int main () {
    int d;
    string month, res;
    res = "";
    cout << "Introduce your day of birth and the month (Starting with capital case): ";
    cin >> d >> month;
    if(month == "December") {
        res += ((d<22)?"Sagittarius":"Capricorn");
    } else if (month == "January") {
        res += ((d<20)?"Capricorn":"Aquarius");
    } else if (month == "February") {
        res += ((d<19)?"Aquarius":"Pisces");
    } else if (month == "March") {
        res += ((d<21)?"Pisces":"Aries");
    } else if (month == "April") {
        res += ((d<20)?"Aries":"Taurus");
    } else if (month == "May") {
        res += ((d<21)?"Taurus":"Gemini");
    } else if (month == "June") {
        res += ((d<21)?"Gemini":"Cancer");
    } else if (month == "July") {
        res += ((d<23)?"Cancer":"Leo");
    } else if (month == "August") {
        res += ((d<23)?"Leo":"Virgo");
    } else if (month == "September") {
        res += ((d<23)?"Virgo":"Libra");
    } else if (month == "October") {
        res += ((d<23)?"Libra":"Scorpio");
    } else if (month == "November") {
        res += ((d<20)?"Scorpio":"Sagittarius");
    }
    cout << "Your astrological sign is: " << res << endl;
    return 0;
}