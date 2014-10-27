#include <iostream>
using namespace std;

int main()
{
	char in;
	int min, hour;
	do
	{
		cout << "A. Hours -> Minutes" << endl	
			 << "B. Minutes -> Hours" << endl
			 <<	"Q. Quit " << endl
			 << "Please choose an option: ";
		cin >> in;
		
		if ( in == 'A' )
		{
			cout << "Enter the number of hours: ";
			cin >> hour;
			cout << "That's " << hour*60 << " minutes." << endl;
			cout << endl;
		}
		else if ( in == 'B' )
		{
			cout << "Enter the number of minutes: ";
			cin >> min;
			cout << "That's " << min/60 << " and " << (min % 60) << " minutes." << endl;
			cout << endl;
		}
		else if ( in != 'B' && in != 'A' && in != 'Q' )
		{
			cout << "That is not a valid option." << endl;
			cout << endl;
		}
	
	}while(in != 'Q');
	
	cout << "Thank you for using my time conversion program";
	
	
	return 0;	
}