/*	******************************
	* Lab 13		Peijin Zhang *
	* Las Vegas			         *
	******************************
*/
#include <iostream>
#include <iomanip>
using namespace std;

void names();
void roll();

int main()
{
	names();
	roll();
	return 0;
}

void names()
{
	int choice;
	string names[10];
	choice = rand() % 10;
	cout << "Enter the names of your 10 best friends. " << endl;
	for (int x = 0; x < 10; x++)
	{
		cout << x + 1 << ": ";
		getline(cin, names[x]);
	}
	cout << "INDEX      NAME" << endl
		 << "-----------------------------" << endl;
	for (int x = 0; x < 10; x++)
	{
		cout << " " << x << "        " << names[x] << endl;
	}
	cout << "-----------------------------" << endl
		 << "And the winner of the free trip is ... " << names[choice] << endl << endl;
}
		

void roll()
{
	int die, dice[6];
	for (int x = 0; x < 6; x++)
	{
		dice[x] = 0;
	}
	for (int x = 0; x< 100; x++)
	{
		die = rand() % 6;
		switch (die)
		{
			case 0:		dice[0] = dice[0] + 1; break;
			case 1:		dice[1] = dice[1] + 1; break;
			case 2:		dice[2] = dice[2] + 1; break;
			case 3:		dice[3] = dice[3] + 1; break;
			case 4:		dice[4] = dice[4] + 1; break;
			case 5:		dice[5] = dice[5] + 1; break;
		}
	}
	cout << " Die        Frequency" << endl
		 << "--------------------------" << endl;
	for (int x = 0; x < 6; x++)
	{
		cout << " " << x + 1 << "        " << dice[x] << endl;
	}
	cout << "--------------------------" << endl;
}