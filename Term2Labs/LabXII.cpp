#include <iostream>
#include <fstream>
using namespace std;

class Date
{
	public:
		Date();
		Date(int m, int d, int y);
		bool leapyear();
		bool isAfter(const Date &date2);
		bool operator == (const Date &date2);
		Date operator + (int days);
		bool operator > (const Date &date2);
		bool operator < (const Date &date2);
		friend ostream& operator << (ostream& output, const Date &d);
		friend istream& operator >> (istream& input, Date &d);
	private:
		int year;
		int month;
		int day;
};

Date :: Date()
{
	year = 1980;
	month = 1;
	day = 1;
}

Date :: Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

bool Date :: leapyear()
{
	int r4 = year % 4;
	int r100 = year % 100;
	int r400 = year % 400;
	if ( r4 == 0 && r100 != 0 || r100 == 0 && r400 == 0)
		return true;
	else
		return false;
}

bool Date :: isAfter(const Date &date2)
{
	if(year < date2.year)
		return false;
	else if (year > date2.year)
		return true;
	else
	{
		if(month < date2.month)
			return false;
		else if(month > date2.month)
			return true;
		else
		{
			if(day > date2.day)
				return true;
			else
				return false;
		}
	}
}

bool Date :: operator == (const Date &date2)
{
	if(year == date2.year && month == date2.month && day == date2.day)
		return true;
	else
		return false;
}

Date Date :: operator + (int days)
{
	day = day + days;
	bool thirtyone = false, thirty = false, feb = false, leap = leapyear();
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
		thirtyone = true;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
		thirty = true;
	else if(month == 2)
		feb = true;
	if(feb && leap && day > 29 || feb && ! leap && day > 28 || thirtyone && day > 31 || thirty && day > 30)
	{	
		do
		{
			if(thirtyone && day > 31)
			{
				day = day - 31;
				month++;
				if(month > 12)
				{
					month = month - 12;
					year++;
				}	
			}
			if(thirty && day > 30)
			{
				day = day - 30;
				month++;
			}
			if(feb && leap && day > 29)
			{
				day = day - 29;
				month++;
			}
			thirtyone = false;
			thirty = false;
			feb = false;
			if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 )
				thirtyone = true;
			else if(month == 4 || month == 6 || month == 9 || month == 11)
				thirty = true;
			else if(month == 2)
				feb = true;
		}while(feb && leap && day > 29 || feb && ! leap && day > 28 || thirtyone && day > 31 || thirty && day > 30);
	}
	return Date(month, day, year);
}

bool Date :: operator > (const Date &date2)
{
	if(year < date2.year)
		return false;
	else if (year > date2.year)
		return true;
	else
	{
		if(month < date2.month)
			return false;
		else if(month > date2.month)
			return true;
		else
		{
			if(day > date2.day)
				return true;
			else
				return false;
		}
	}
}

bool Date :: operator < (const Date &date2)
{
	if(year < date2.year)
		return true;
	else if (year > date2.year)
		return false;
	else
	{
		if(month < date2.month)
			return true;
		else if(month > date2.month)
			return false;
		else
		{
			if(day < date2.day)
				return true;
			else
				return false;
		}
	}
}

ostream& operator << (ostream& output, const Date &d)
{
	switch(d.month)
	{
		case 1:		output << "January "; break;
		case 2:		output << "February "; break;
		case 3:		output << "March "; break;
		case 4:		output << "April "; break;
		case 5:		output << "May "; break;
		case 6:		output << "June "; break;
		case 7:		output << "July "; break;
		case 8:		output << "August "; break;
		case 9:		output << "September "; break;
		case 10:	output << "October "; break;
		case 11:	output << "November "; break;
		case 12:	output << "December ";
	}
	output << d.day << ", " << d.year << endl;
	return output;
}

istream& operator >> (istream& input, Date &d)
{
	cout << "Enter year: ";
	input >> d.year;
	cout << "Enter month: ";
	input >> d.month;
	cout << "Enter day: ";
	input >> d.day;
	return input;
}

int main()
{
	Date a; // default constructor
	Date b(10,22,1980); // alternate constructor
	bool after = a.isAfter(b); // returns true if a is after b, false if otherwise
	bool equal = a == b; // returns true if a is the same as b, false if otherwise
	Date c = a + 30; // c is 30 days after a
	bool greater = a > b; // returns true if a is after b, false if otherwise, same thing as isAfter
	bool less = a < b; // returns true if a is before b, false if otherwise
	cout << a << b << c;
	Date d;
	cin >> d;
	cout << d;
	return 0;
}