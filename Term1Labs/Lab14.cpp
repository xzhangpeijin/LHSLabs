//	******************************
//	* Lab 14		Peijin Zhang *
//	* Mini Golf			         *
//	******************************

#include <iostream>
#include <iomanip>
using namespace std;

void getstats(string &name, int hole[]);
void scores(int hole[], int &score, int &in1);
void display(string name, int hole[], int score, int in1);


int main()
{
	int hole[18], score=0, in1=0;
	string name;
	getstats(name, hole);
	scores(hole, score, in1);
	display(name, hole, score, in1);
	return 0;
}

void getstats(string &name, int hole[])
{
	cout << "Enter name of player: ";
	getline(cin, name);
	cout << "Enter the number of strokes for each hole." << endl;
	for (int x = 0; x < 18; x++)
	{
		cout << "Hole " << x + 1 << ": ";
		cin >> hole[x];
	}
}

void scores(int hole[], int &score, int &in1)
{
	for (int x = 0; x < 18; x++)
	{
		score = score + hole[x];
		if (hole[x] == 1)
		{
			in1 = in1 + 1;
		}
	}
}

void display(string name, int hole[], int score, int in1)
{
	cout << endl << name << ", here is your scorecard: \n\n" 
		 << "Hole :  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18\n"
		 << "------------------------------------------------------------\n"
		 << "Score:  ";
	for (int x = 0; x < 18; x++)
	{
		cout << hole[x] << "  ";
	}
	cout << "\n\nYour total is " << score << ". \nYou scored " << in1 << " holes-in-one. ";
}