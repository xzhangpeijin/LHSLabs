//Peijin Zhang

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void getscores(int score[][3]);
void total(int score[][3]);

int main()
{
	int score[10][3];
	for(int x = 0; x < 10; x++)
	{
		score[x][0] = 0;
		score[x][1] = 0;
		score[x][2] = 0;
	}
	cout << "Bowling Application" << endl << "Enter your scores" << endl;
	getscores(score);
	total(score);
	return 0;
}

void getscores(int score[][3])
{
	for (int x = 0; x < 10; x++)
	{	
		cout << "Frame " << x + 1 << ": ";
		cin >> score[x][0];
		if (score[x][0] != 10 && x != 9)
		{
			cin >> score[x][1];
		}
		if (x == 9)
		{
			cin >> score[x][1];
		}
		if (x == 9 && score[x][0] + score[x][1] == 10)
		{
			cin >> score[x][2];
		}
		else if (x == 9 && score[x][0] == 10)
		{
			cin >> score[x][2];
		}
	}
}

void total(int score[][3])
{
	int total = 0;
	for(int x = 0; x < 10; x++)
	{
		int a = x + 1;
		int b = x + 2;
		if (x != 9)
		{
			if(score[x][0] == 10 && score[a][0] != 10)
			{
				total = total + score[x][0] + score[a][0] + score[a][1];
			}
			else if(score[x][0] == 10 && score[a][0] == 10)
			{
				if (x == 9)
				{
					total = total + score[x][0] + score[a][0] + score[a][1];
				}
				else
				{
					total = total + score[x][0] + score[a][0] + score[b][0];
				}
			}
			else if (score[x][0] + score[x][1] == 10)
			{
				total = total + score[x][0] + score[x][1] + score[a][0];
			}
			else
			{
				total = total + score[x][0] + score[x][1];
			}
		}
		else
		{
			total = total + score[x][0] + score[x][1] + score[x][2];
		}
	}
	cout << "Total: " << total;
}
		
		
		
		
		
		
		
		
	
			