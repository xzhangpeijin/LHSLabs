/*	***********************************
	* Lab 8				Peijin Zhang  *
	* Birthdates					  *
	***********************************
*/

#include <iostream>
using namespace std;

int main()
{
	int m = 0, d = 0, y = 0, y4, y100, y400, leap, first2, last2, mnum, firsttotal, completetotal;
	cout << "Enter your birth date (month day year): ";
	cin >> m >> d >> y;
	y4 = y % 4;
	y100 = y % 100;
	y400 = y % 400;
	first2 = y / 100;
	last2 = y % 100;
	
	if (y4 == 0 && y100 != 0)
	{
		leap = 1;
	}
	else if (y100 == 0 && y400 == 0)
	{
	leap = 1;
	}
	else if (y4 != 0 || y100 == 0)
	{
		leap = 0;
	}
	if (leap = 0)
	{
		switch (m)
		{
			case 1:		mnum = 1; break;
			case 2:		mnum = 4; break;
			case 3:		mnum = 4; break;
			case 4:		mnum = 0; break;
			case 5:		mnum = 2; break;
			case 6:		mnum = 5; break;
			case 7:		mnum = 0; break;
			case 8:		mnum = 3; break;
			case 9:		mnum = 6; break;
			case 10:	mnum = 1; break;
			case 11:	mnum = 4; break;
			case 12:	mnum = 6; break;
		}
	}
	else
	{
		switch (m)
		{
			case 1:		mnum = 0; break;
			case 2:		mnum = 3; break;
			case 3:		mnum = 4; break;
			case 4:		mnum = 0; break;
			case 5:		mnum = 2; break;
			case 6:		mnum = 5; break;
			case 7:		mnum = 0; break;
			case 8:		mnum = 3; break;
			case 9:		mnum = 6; break;
			case 10:	mnum = 1; break;
			case 11:	mnum = 4; break;
			case 12:	mnum = 6; break;
		}
	}
	
	firsttotal = 2*(3 - (first2 % 4));
	
	completetotal = firsttotal + last2 + (last2 / 4) + mnum + d;
	
	switch ( completetotal % 7 )
	{
		case 1:	 cout << "You were born on a Sunday"; break;
		case 2:	 cout << "You were born on a Monday"; break;
		case 3:  cout << "You were born on a Tuesday"; break;
		case 4:  cout << "You were born on a Wednesday"; break;
		case 5:  cout << "You were born on a Thursday"; break;
		case 6:  cout << "You were born on a Friday"; break;
		case 0:  cout << "You were born on a Saturday"; break;
	}
	return 0;
	
}
	
	
	
