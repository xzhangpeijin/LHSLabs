// **************************
// * Peijin Zhang    Quiz 1 *
// * Days Alive             *
// **************************

#include <iostream>
#include <iomanip>
using namespace std;

void getdata(string& name, int& birthdate, int& birthmonth, int& birthyear);
int calculatedays(int birthdate, int birthmonth, int birthyear);
void displaydata(string name, int days);

int main()
{
	int daysalive;
	int day, month, year;
	string name;
	for (int loop = 0; loop < 3; loop++)
	{
		getdata(name, day, month, year);
		daysalive = calculatedays(day, month, year);
		displaydata(name, daysalive);
		getline(cin,name);
	}
	return 0;
}

void getdata(string& name, int& birthdate, int& birthmonth, int& birthyear)
// pre: one string, three integers
// post: none
{
	cout << "Enter your name: ";
	getline(cin,name);
	cout << "Enter your bithdate (Month Day Year): ";
	cin >> birthmonth >> birthdate >> birthyear;
}

int calculatedays(int birthdate, int birthmonth, int birthyear)
// pre: three integers
// post: number of days you've been alive
{
	int daysalive = 308;
	int r4, r100, r400;
	int leap = 0;
	r4 = birthyear % 4;
	r100 = birthyear % 100;
	r400 = birthyear % 400;
	if ( r4 == 0 && r100 != 0 || r100 == 0 && r400 == 0)
	{
		leap = 1;
	}
	for (int x = birthyear + 1; x < 2009; x++)
	{
		r4 = x % 4;
		r100 = x % 100;
		r400 = x % 400;
		if ( r4 == 0 && r100 != 0 || r100 == 0 && r400 == 0)
		{
			daysalive = daysalive + 366;
		}
		else
		{
			daysalive = daysalive + 365;
		}
	}
	for (int x = birthmonth + 1; x < 13; x++)
	{
		if ( x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
		{
			daysalive = daysalive + 31;
		}
		else if ( x == 4 || x == 6 || x == 9 || x == 11)
		{
			daysalive = daysalive + 30;
		}
		else if ( x == 2)
		{
			if ( leap == 1)
			{
				daysalive = daysalive + 29;
			}
			else
			{
				daysalive = daysalive + 28;
			}
		}
	}
	if ( birthmonth == 1 || birthmonth == 3 || birthmonth == 5 || birthmonth == 7 || birthmonth == 8 || birthmonth == 10 || birthmonth == 12)
	{
		daysalive = daysalive + 31 - birthdate + 1;
	}
	else if (birthmonth == 4 || birthmonth == 6 || birthmonth == 9 || birthmonth == 11)
	{
		daysalive = daysalive + 30 - birthdate + 1;
	}
	else if (birthmonth == 2)
	{
		if (leap == 1)
		{
			daysalive = daysalive + 29 - birthdate + 1;
		}
		else
		{
			daysalive = daysalive + 28 - birthdate + 1;
		}
	}
	return daysalive;
}
	
void displaydata(string name, int days)
// pre: one string, one integer
// post: none
{
	cout << name << ", You have been alive for " << days << " Days.\n";
}
		
		
		
		
