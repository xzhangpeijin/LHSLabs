// *******************************
// * Lab VI			Peijin Zhang *
// * Mathematical Functions      *
// *******************************

#include <iostream>
using namespace std;

int factorial(int n);
int fibonacci(int n);
int triangularNumber(int n);
char getChoice(); 
int getNum();

int main()
{
	int n;
	char answer;
	do
	{
		answer = getChoice();
		if(answer != 'Q')
			n = getNum();
		switch(answer)
		{
			case 'A': cout << "The factorial of " << n << " is " << factorial(n) << "." << endl; break;
			case 'B': cout << "The " << n << "th Fibonacci number is " << fibonacci(n) << "." << endl; break;
			case 'C': cout << "The " << n << "th triangular number is " << triangularNumber(n) << "." << endl; break;
		}
	}while(answer != 'Q');
	return 0;
}

int factorial(int n)
{
	int total;
	if(n == 1)
	{	
		return 1;
	}
	else
	{
		total = n * factorial(n - 1);
		return total;
	}
}

int fibonacci(int n)
{
	int total;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		total = fibonacci(n-1) + fibonacci(n-2);
		return total;
	}
}			

int triangularNumber(int n)
{
	int total;
	if(n == 1)
	{
		return 1;
	}
	else
	{
		total = n + triangularNumber(n - 1);
		return total;
	}
}

char getChoice()
{
	char choice;
	int valid;
	do
	{
		valid = 1;
		cout << "Math Functions: \n"
		 	 << "A) Factorial \n"
			 << "B) Fibonacci Number \n"
			 << "C) Triangular Number \n"
			 << "Q) Quit \n"
			 << "Enter your choice: ";
		cin >> choice;
		if (choice != 'A' && choice != 'B' && choice != 'C' && choice != 'Q')
			valid = 0;
	}while(valid == 0);
	return choice;
}

int getNum()
{
	int n, valid;
	do
	{
		valid = 1;
		cout << "Enter your number: ";
		cin >> n;
		if (n < 1)
		{
			cout << "That is not a valid number";
			valid = 0;
		}
	}while(valid == 0);
	return n;
}