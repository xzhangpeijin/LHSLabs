// *****************************************
// * Project I                Peijin Zhang *
// * Bowling App (Multiple Players)        *
// *****************************************

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void getscores(int score[][3][6], int players);
void total(int score[][3][6], int players);

int main()
{
	int players;
	int score[10][3][6];
	int valid = 1;
	cout << "Bowling Application" << endl;
	do
	{	
		cout << "Enter the amount of players (6 or less): ";
		cin >> players;
		if (players > 6)
		{
			valid = 0;
			cout << "That is not a valid number of players." << endl;
		}
		else if(players < 6 || players == 6)
		{
			valid = 1;
		}
	}while(valid == 0);
	cout << "Enter your scores" << endl;
	for (int x = 0; x < players; x++)
	{
		score[9][2][x] = 0;
	}
	getscores(score, players);
	total(score, players);
	return 0;
}

void getscores(int score[][3][6], int players)
// pre: one array, one int
// post: none
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < players; y++)
		{
			score[x][2][y] = 0;
			cout << "Frame " << x + 1 << ", Player " << y + 1 << ": ";
			cin >> score[x][0][y];
			if (score[x][0][y] != 10 && x != 9)
			{
				cin >> score[x][1][y];
			}
			if ( x == 9)
			{
				cin >> score[x][1][y];
			}
			if ( x == 9 && score[x][0][y] + score[x][1][y] == 10)
			{
				cin >> score[x][2][y];
			}
			else if ( x == 9 && score[x][0][y] == 10)
			{
				cin >> score[x][2][y];
			}
		}
	}
}

void total(int score[][3][6], int players)
// pre: one array, one int
// post: none
{
	int total[6];
	for (int x = 0; x < 6; x++)
	{
		total[x] = 0;
	}
	for(int x = 0; x < 10; x++)
	{
		int a = x + 1;
		int b = x + 2;
		for (int y = 0; y < players; y++)
		{
			if (x != 9)
			{
				if(score[x][0][y] == 10 && score[a][0][y] != 10)
				{
					total[y] = total[y] + score[x][0][y] + score[a][0][y] + score[a][1][y];
				}
				else if(score[x][0][y] == 10 && score[a][0][y] == 10)
				{
					if (x == 8)
					{
						total[y] = total[y] + score[x][0][y] + score[a][0][y] + score[a][1][y];
					}
					else
					{
						total[y] = total[y] + score[x][0][y] + score[a][0][y] + score[b][0][y];
					}
				}
				else if (score[x][0][y] + score[x][1][y] == 10)
				{
					total[y] = total[y] + score[x][0][y] + score[x][1][y] + score[a][0][y];
				}
				else
				{
					total[y] = total[y] + score[x][0][y] + score[x][1][y];
				}
			}
			else
			{
				total[y] = total[y] + score[x][0][y] + score[x][1][y] + score[x][2][y];
			}
		}
	}
	for (int y = 0; y < players; y++)
	{
		cout << "Player " << y + 1 << "'s Total: " << total[y] << endl;
	}
}
		
		
		
		
		
		
		
		
	
			