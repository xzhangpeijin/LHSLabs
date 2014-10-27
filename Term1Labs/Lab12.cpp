/*	******************************
	* Lab 12		Peijin Zhang *
	* Fractions					 *
	******************************

	Output format only works if all fractions are single digits. :(
	
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getstats(int &n1, int &d1, int &n2, int &d2);
int menu(int &choice);
void display(int n1, int d1, int n2, int d2, int choice);
char repeat(char cont);
int gcd(int a, int b);
void swap(int n1, int n2);

int main()
{
	int n1, d1, n2, d2, choice;
	char cont = 'y';
	while(cont == 'y')
	{
		getstats(n1, d1, n2, d2);
		choice = menu(choice);
		display(n1, d1, n2, d2, choice);
		cont = repeat(cont);
	}
}

void getstats(int &n1, int &d1, int &n2, int &d2)
{
	int valid = 0;
	while(valid == 0)
	{
		cout << "Enter the numerator and denominator of the first fraction: ";
		cin >> n1 >> d1;
		if ( d1 == 0)
		{
			cout << "That is not a valid fraction" << endl;
			cout << endl;
		}
		else
		{
			valid = 1;
		}
	}
	valid = 0;
	while(valid == 0)
	{
		cout << "Enter the numerator and denominator of the second fraction: ";
		cin >> n2 >> d2;
		if ( d2 == 0 )
		{
			cout << "That is not a valid fraction" << endl;
			cout << endl;
		}
		else
		{
			valid = 1;
		}
	}
}
	
		

int menu(int &choice)
{
	cout <<	endl
		 << "Menu of Operations" << endl
		 << "Add.....................1" << endl
		 << "Subtract................2" << endl
		 << "Multiply................3" << endl
		 << "Divide..................4" << endl
		 << endl
		 << "Which operation? ";
	cin >> choice;
	cout << endl;
	return choice;
}

void display(int n1, int d1, int n2, int d2, int choice)
{
	int a, b, n3, d3;
	if (choice == 1)
	{
		a = d1;
		b = d2;
		d3 = d1 / gcd(d1, d2) * d2;
		n3 = d1 / gcd(d1, d2) * n2 + d2 / gcd(d1, d2) * n1;
		if (gcd(d3, n3) == 1)
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << endl
				 << "---  +  ---  =  --- " << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << endl;
		}
		else 
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << "     " << n3 / gcd(n3, d3) << endl
				 << "---  +  ---  =  --- = ---" << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << "     " << d3 / gcd(n3, d3) << endl;
		}

	}	
	else if (choice == 2)
	{	
		if (n2 > n1)
		{
			swap(n1, n2);
		}
		a = d1;
		b = d2;
		d3 = d1 / gcd(d1, d2) * d2;
		n3 = d2 / gcd(d1, d2) * n1 - d1 / gcd(d1, d2) * n2;
		if (gcd(d3, n3) == 1)
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << endl
				 << "---  -  ---  =  --- " << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << endl;
		}
		else 
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << "     " << n3 / gcd(n3, d3) << endl
				 << "---  -  ---  =  --- = ---" << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << "     " << d3 / gcd(n3, d3) << endl;
		}
	}
	else if (choice == 3)
	{
		n3 = n1 * n2;
		d3 = d1 * d2;
		if (gcd(d3, n3) == 1)
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << endl
				 << "---  *  ---  =  --- " << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << endl;
		}
		else 
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << "     " << n3 / gcd(n3, d3) << endl
				 << "---  *  ---  =  --- = ---" << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << "     " << d3 / gcd(n3, d3) << endl;
		}
	}
	else if (choice == 4)
	{
		n3 = n1 * d2;
		d3 = d1 * n2;
		if (gcd(d3, n3) == 1)
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << endl
				 << "---  /  ---  =  --- " << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << endl;
		}
		else 
		{
			cout << " " << n1 << "       " << n2 << "       " << n3 << "     " << n3 / gcd(n3, d3) << endl
				 << "---  /  ---  =  --- = ---" << endl
				 << " " << d1 << "       " << d2 << "       " << d3 << "     " << d3 / gcd(n3, d3) << endl;
		}
	}
	
}
		

char repeat(char cont)
{
	cout << endl << "Another problem (y for yes, n for no)? ";
	cin >> cont;
	return cont;
}

int gcd(int a, int b)
{   
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

void swap(int n1, int n2)
{
     int temp;
     temp=n1;
     n1=n2;
     n2=temp;
}
