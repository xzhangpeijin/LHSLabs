#include <iostream>
using namespace std;

int main()
{
	int year, r4, r100, r400;
	
	do
	{
		cout << "Press 1 to quit" << endl
			 << "Enter a year: ";
		cin >> year;
		
		r4 = year % 4;
		r100 = year % 100;
		r400 = year % 400;
		if ( r4 == 0 && r100 != 0 || r100 == 0 && r400 == 0)
		{
			cout << "That is a leap year" << endl;
		}
		else
		{
			cout << "That is not a leap year" << endl;
		}
	
	}while ( year != 1);
	
	cout << "Thank you for using my happy leap year program!";
	
	return 0;
}
	