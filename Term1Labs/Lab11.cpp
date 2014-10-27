/*	******************************
	* Lab 11		Peijin Zhang *
	* Gallons of Paint			 *
	******************************
*/
#include <iostream>
#include <iomanip>
using namespace std;

void getstats(int &l, int &wid, int &h, int &win, int &d);
double calculate(int l, int wid, int h, int win, int d);
char display(int grandtotal, int total, char cont, double gallons, int totalgallons );

int main()
{
	int l, wid, h, win, d, grandtotal = 0, total;
	double gallons, totalgallons;
	char cont = 'y';
	while (cont == 'y')
	{
	cout << setiosflags(ios_base::fixed)
		 << setiosflags(ios_base::showpoint)
		 << setprecision(2);
		getstats(l, wid, h, win, d);
		total = calculate(l, wid, h, win, d);
		grandtotal = total + grandtotal;
		cont = display(grandtotal, total, cont, gallons, totalgallons);
	}
	return 0;
}

void getstats(int &l, int &wid, int &h, int &win, int &d)
// pre: six integers
// post: none
{
	cout << "Enter dimensions (length width height): ";
	cin >> l >> wid >> h;
	cout << "Enter number of windows and doors: ";
	cin >> win >> d;
}
double calculate(int l, int wid, int h, int win, int d)
// pre: five integers
// post: total area to be painted
{
	double total;
	total = 2 * h * ( l + wid ) - 15 * win - 21 * d;
	return total;
}
char display(int grandtotal, int total, char cont, double gallons, int totalgallons)
// pre: five variables
// post: whether or not to do another room
{
	gallons = total * 1.00 / 400; 
	cout << grandtotal;
	cout << "That room will take " << gallons << " gallons of paint.";
	cout << endl;
	cout << "Another room (y/n)? ";
	cin >> cont;
	if (cont == 'n')
	{
		if ( grandtotal % 400 == 0 )
		{
			totalgallons = grandtotal / 400; 
		}
		else 
		{
			totalgallons = grandtotal / 400 + 1;
		}
		gallons = grandtotal * 1.00 / 400;
		cout << "All the rooms combined will take " << gallons << " gallons of paint.";
		cout << endl;
		cout << totalgallons << " gallon-containers of paint will be required.";
		return cont;
	}
	else 
	{
		return cont;
	}
}
		
