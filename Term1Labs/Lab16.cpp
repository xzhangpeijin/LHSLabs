//	******************************
//	* Lab 16		Peijin Zhang *
//	* Extra Additives	         *
//	******************************

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int asciitoint (char ch);
void calculate(vector<char> &int1, vector<char> &int2, vector<int> largeint1,vector<int> largeint2, vector<int> finalint, int &int1digits, int &int2digits);

int main ()
{
	vector<int> largeint1 (12,0); 
	vector<int> largeint2 (12,0); 
	vector<int> finalint (13,0);
	vector<char> int1 (12,'0');
	vector<char> int2 (12,'0');
	int int1digits, int2digits;
	for (int x = 0; x < 4; x++)
	{
		cout << "Enter your two numbers \n";
		string int1a, int2a;
		getline(cin,int1a);
		getline(cin,int2a);
		int1digits = int1a.size();
		int2digits = int2a.size();
		for (int x = 0; x < 12; x++)
		{	
			int1[x] = int1a[x];
		}
		for (int x = 0; x < 12; x++)
		{
			int2[x] = int2a[x];
		}
		calculate(int1, int2, largeint1, largeint2, finalint, int1digits, int2digits);
	}
    return 0;
}

int asciitoint(char ch)
// pre: a character
// post: an integer
{
	return (ch - '0');
}


void calculate(vector<char> &int1, vector<char> &int2, vector<int> largeint1, vector<int> largeint2, vector<int> finalint, int &int1digits, int &int2digits)
// pre: four vectors, two integers
// post: none
{
	int begin = 0;
	for (int x = 0; x < int1digits; x++)
	{
		int a = 12 - int1digits + x;
		largeint1[a] = asciitoint(int1[x]);
	}
	for (int x = 0; x < int2digits; x++)
	{
		int a = 12 - int2digits + x;
		largeint2[a] = asciitoint(int2[x]);
	}
	for (int x = 0; x < 12; x++)
	{
		int a = 11 - x;
		int b = 12 - x;
		finalint[b] = finalint[b] + largeint1[a] + largeint2[a];
		if (finalint[b] > 9)
		{
			finalint[b] = finalint[b] - 10;
			finalint[a] = 1;
		}
	}
	for (int x = 0; x < 13; x++)
	{
		if (finalint[x] > 0 && finalint[x] < 10)
		{
			begin = 1;
		}
		if (begin == 1)
		{
			cout << finalint[x];
		}
	}
	cout << endl;
}
