/* part of the assignment to find the algorithm. put it in object terms. algorithm for converting between Julian daet to calendar date. cite it
//hide in in the object and use it without understanding it. encapsulate this mess
365 days in a year

LEAP YEAR: any year divisible by 4 --> LEAP YEAR
EXCEPT: if the year is divisible by 100 --> NOT LEAP
EXCEPT if the year is divisible by 400 --> LEAP
year  = 365.2425 days


2000 LEAP
2004 LEAP since div by 4
2100 NOT LEAP

J2000 = Jan. 1, 2000 = 0

	Jan 2, 2000 = 1
	Jan 3, 2000 = 2


*/

class JulianDate {
private: 
	double jday;


};


int main() {
	// hh:mm:ss 20/24 20/24.0
	const JulianDate d1(2017, 2, 13, 20, 00, 00); //8 at night on feb 13 2017. year, month, day, hour, min, sec
	const JulianDate d1b(2017, 2, 13, 22, 00, 00);
	cout << d1b-d1; //2 hours = 2/24 day

	JulianDate tomorrow = d1 + 1;
	cout << tomorrow; // 2017 2 14 20 00 00
	cout << tomorrow - d1 << '\n';

	const JulianDate d2(2017, 2, 19) //default time is midnight on that day
	const JulianDate d3 = d2 + 3; //what is it 3 days later? account for month ending. do we need to account for leap year?
	double days = d3 - d1;


	int year = d3.getYear();
	int month = d3.getMonth();
	int day = d3.getDay();
	int hour = d3.getHour();
	int min = d3.getMin();
	int sec = d3.getSec();
	cout << d1 << '\n';
	cout << d2 << '\n';
	cout << d3 << '\n';
	cout << year << " " << month << " " << day << " " << hour << " " << min << " " << sec << '\n';

	// this doesn't make sense to add two JulianDates. JulianDate d5 = d3 + d1
	JulianDate torture(2017, 2, 27); // 00:00:00
	for (int i = 0; i < 3; i++) {
		cout torture.getYear() << " " << torture.getMonth() << " " torture.getDay() << '\n';
		torture = torture + 1;

	}

	return 0;
}