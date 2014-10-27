/*	******************************
	* Lab 10		Peijin Zhang *
	* Baseball OPS				 *
	******************************
*/

#include <iostream>
#include <iomanip>
using namespace std;

	 
string getName();
void getStats(int &AB, int &H, int &BB, int &HBP, int &SF, int &TB);
double calculate(int AB, int H, int BB, int HBP, int SF, int TB);
void display(double OPS, string name);

int main()
{
	double OPS;
	int AB, H, BB, HBP, SF, TB;
	string name;
	name = getName();
	getStats(AB, H, BB, HBP, SF, TB);
	OPS = calculate(AB, H, BB, HBP, SF, TB);
	display(OPS, name);
	return 0;
}

string getName()
{
	string name;
	cout << "Enter the player's name: ";
	getline(cin,name);
	return name;
}
void getStats(int &AB, int &H, int &BB, int &HBP, int &SF, int &TB)
{
	cout << "Enter the player's total at bats: ";
	cin >> AB;
	cout << "Enter the player's total number of hits: ";
	cin >> H;
	cout << "Enter the player's total number of walks: ";
	cin >> BB;
	cout << "Enter the player's total number of times hit by a pitch: ";
	cin >> HBP;
	cout << "Enter the player's total number of sacrifice flies: ";
	cin >> SF;
	cout << "Enter the player's total number of bases: ";
	cin >> TB;
}
double calculate(int AB, int H, int BB, int HBP, int SF, int TB)
{
	double OPS;
	OPS = ( (  1.000 * ( AB * ( H + BB + HBP ) + TB * ( AB + BB + SF + HBP ) ) ) / ( 1.000 * ( AB * ( AB + BB + SF + HBP ) ) ) );
	return OPS;
}
void display(double OPS, string name)
{
	cout << name << "'s OPS is: " << OPS;
}