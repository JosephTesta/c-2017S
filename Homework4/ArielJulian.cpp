//
// Created by Ariel Feliz on 11/3/16.
// Source: http://codereview.stackexchange.com/questions/38893/calculating-julian-dates


#include <iostream>
using namespace std;

class JulDate {
private:
const static int BASEYEAR; // turns into extern
    double jdate;

    double calcJDate(int year, int month, int day) {
        double date;
        int a = (14 - month) / 12;
        int y = year + 4800 - a;
        int m = month + 12 * a - 3;
        if (year > BASEYEAR || (year == BASEYEAR && month > 10) || (year == 1582 && month == 10 && day >= 15))
            return date = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
        else
            return date = day + (153 * m + 2) / 5 + 365 * y + y / 4 - 32083;
    }

public:
    JulDate() {
        time_t t = time(0);
        struct tm *now = localtime(&t);
        int todDay = now->tm_mday;
        int todMonth = now->tm_mon + 1;
        int todYear = now->tm_year + 1900;
        jdate = calcJDate(todYear, todMonth, todDay);

    }

    JulDate(double jd) : jdate(jd) {}

    JulDate(int yr, int m, int d) {
        jdate = calcJDate(yr, m, d);
    }

friend double operator-(JulDate d1, JulDate d2)
    {
return d1.jdate - d2.jdate;
    }

friend JulDate operator +(JulDate d1, JulDate d2)
    {
return JulDate(d1.jdate + d2.jdate);
    }


friend JulDate operator +(JulDate d1, int days)
    {
return JulDate(d1.jdate + (double)days);
    }
friend JulDate operator +(int days, JulDate d1)
    {
return JulDate(d1.jdate + (double)days);
    }


friend ofstream& operator <<(ofstream& o, JulDate jd)
    {
return o << jd.date;
    }


};

const int JulDate::BASEYEAR = 2000;  // (2000, 1,1, 0, 0, 0) = 0    (2000, 1, 2) = 1
/*
Every year has 365 days except... if y divisible by 4 leapyear 366 (Feb. 29)
except if the year mod 100 == 0  NO LEAP YEAR EXCEPT if year MOD 400 == 0 YES, it's a leap year.
  1900 NO (divisible by 100)
  1904 LEAP
  2000 LEAP (divisible by 400)
Jan Meeus "Astronomical Algorithms"
 */

int main() {
    JulDate d1 = JulianDate::now();
    JulDate d2(2005, 1, 15); // Jan 15, 2005
    // cout << d1 + d2; // makes no sense!!!

    JulDate d2 = d1 + 1; // tomorrow
    JulDate d3(2052, 1, 1, 12, 00, 00);
    JulDate d4(2061, 2, 28, 11, 00, 00);
    double del = d4 - d3;
    cout << del  << "\n";
    cout << d4.getYear() << ":" << d4.getMonth() << ":" << d4.getDay() << '\n';
    JulDate d5(2004, 2,29);
    // extra 5 points if you get the following right!
    cout << d5.getYear() << ":" << d5.getMonth() << ":" << d5.getDay() << '\n';
}