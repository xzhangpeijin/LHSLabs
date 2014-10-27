//	******************************
//	* Lab 15		Peijin Zhang *
//	* Mastermind		         *
//	******************************

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void getstats(vector<int> n, vector<int> c, int correct);
int value(vector<int> n, vector<int> c);
int location(vector<int> n, vector<int> c);

int main()
{
	srand(time(0));
	vector<int> n (4);
	vector<int> c (4);
	int correct=0;
	getstats(n, c, correct);
	return 0;
}

void getstats(vector<int> n, vector<int> c, int correct)
{
	for(int x = 0; x < 4; x++)
	{	
		n[x] = rand() % 6 + 1;
	}
	cout << "Welcome to Mastermnd" << endl;
	while (correct == 0)
	{
		int cnum=0, cloc=0;
		cout << "\nPlease enter your four numerical guesses (space separated) : ";
		cin >> c[0] >> c[1] >> c[2] >> c[3];
		cnum = value(n, c);
		cloc = location(n, c);
		if (cloc == 4)
		{
			correct = 1;
		}
		if (correct != 1)
		{
			cout << "You have " << cnum << " correct numbers and " << cloc << " correct locations.";
		}
	}
	cout << "Correct! \n\nYou are a MasterMind!";
}

int value(vector<int> n, vector<int> c)
{
	int num=0;
	for(int x = 0; x < 4; x++)
	{
		if (c[x] == n[0] )
		{
			num++;
			n[0] = 7;
		}
		else if ( c[x] == n[1] )
		{
			num++;
			n[1] = 7;
		}
		else if ( c[x] == n[2] )
		{
			num++;
			n[2] = 7;
		}
		else if ( c[x] == n[3] )
		{
			num++;
			n[3] = 7;
		}
	}
	return num;
}

int location(vector<int> n, vector<int> c)
{
	int num=0;
	for(int x = 0; x < 4; x++)
	{
		if (c[x] == n[x])
		{
			num=num+1;
		}
	}
	return num;
}
