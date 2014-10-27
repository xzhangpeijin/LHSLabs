#include <iostream>
using namespace std;

void get(int scores[][2]);
void calculate(int scores[][2]);
void display (int scores[][2]);

int main()
{
	int scores[6][2];
	get(scores);
	calculate(scores);
	display(scores);
	return 0;
}

void get(int scores[][2])
{	
	cout << "Enter your scores" << endl;
	cout << "Enter Home team, First Quarter: ";
	cin >> scores[0][0];
	cout << "Enter Visiting team, First Quarter: ";
	cin >> scores[0][1];
	cout << "Enter Home team, Second Quarter: ";
	cin >> scores[1][0];
	cout << "Enter Visiting team, Second Quarter: ";
	cin >> scores[1][1];
	cout << "Enter Home team, Third Quarter: ";
	cin >> scores[3][0];
	cout << "Enter Visiting team, Third Quarter: ";
	cin >> scores[3][1];
	cout << "Enter Home team, Fourth Quarter: ";
	cin >> scores[4][0];
	cout << "Enter Visiting team, Fourth Quarter: ";
	cin >> scores[4][1];
}

void calculate(int scores[][2])
{
	scores[2][0] = scores[0][0] + scores[1][0];
	scores[2][1] = scores[0][1] + scores[1][1];
	scores[5][0] = scores[2][0] + scores[3][0] + scores[4][0];
	scores[5][1] = scores[2][1] + scores[3][1] + scores[4][1];
}

void display(int scores[][2])
{	
	cout << "           1st Quarter     2nd Quarter      Halftime     3rd Quarter     4th Quarter     Final" << endl
		 << "Home Team       " << scores[0][0] << "              " << scores[1][0] << "             " << scores[2][0] << "             " << scores[3][0] << "              " << scores[4][0] << "          " << scores[5][0] << endl
		 << "Visiting Team   " << scores[0][1] << "              " << scores[1][1] << "             " << scores[2][1] << "             " << scores[3][1] << "              " << scores[4][1] << "          " << scores[5][1] << endl;
	if (scores[5][0] > scores[5][1])
	{
		cout << "Home Team Wins";
	}
	else if (scores[5][1] > scores[5][0])
	{
		cout << "Visiting Team Wins";
	}
	else if (scores[5][0] == scores[5][1])
	{
		cout << "Game is a tie";
	}
}
	
		
	