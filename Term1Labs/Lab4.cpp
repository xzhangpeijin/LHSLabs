#include <iostream>
#include <iomanip>
using namespace std;
int main()
{	
	cout << setiosflags(ios_base::fixed)
		 << setiosflags(ios_base::showpoint)
		 << setprecision(2);
	double a, pay, sum = 0;
	for(int y=1; y<5; y++)
	{
		cout << "How many hours did you work this week? ";
		cin >> a; 
		pay = a*7.50*0.70;
		sum = sum + pay;
		cout << "Your take-home pay is " << pay << endl;
	}
	
	cout << "Your total pay for this month is " << sum << endl;
	return 0;
	
}

