/*	******************************
	* Lab 9			Peijin Zhang *
	* Heart Rate				 *
	******************************
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getAge(int &age)
{
	cout << "Hi! How old are you? ";
	cin >> age;
	while (age < 0 || age > 150)
	{
		cout << "Ha, ha! You're a funny one! But seriously, how old are you? ";
		cin >> age;
	}
}
void calculate (int age, double &UL, double &LL)
{
	UL = 0.75 * (220 - age);
	LL = 0.60 * (220 - age);
}
void display(double UL, double LL)
{
	cout << "Your target heart rate zone is between " << LL << " and " << UL << " BPM.";
}

int main()
{
	double UL, LL;
	int age;
	getAge(age);
	calculate(age, UL, LL);
	display(UL, LL);
	return 0;
}

