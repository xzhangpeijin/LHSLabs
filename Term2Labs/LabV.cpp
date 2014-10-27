// **********************************
// * Lab V             Peijin Zhang *
// * Battleship						*
// **********************************

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void display(vector <vector <int> > spaces);
int coordinates(vector <vector <int> > spaces, int &x, int &y, int &ammo);
int detect(int &value);
char ascii(int &a);

int main()
{
	srand(time(0));
	int ammo, hit, x, y, start1, start2, orient, sink;
	vector< vector<int> > spaces(8,vector<int>(8,0));
	start1 = rand() % 4;
	start2 = rand() % 4;
	orient = rand() % 2;
	spaces[start1][start2] = 1;
	if(orient == 0)
	{
		int a = start1 + 1;
		int b = start1 + 2;
		int c = start1 + 3;
		spaces[a][start2] = 1;
		spaces[b][start2] = 1;
		spaces[c][start2] = 1;
	}
	else if (orient == 1)
	{
		int a = start2 + 1;
		int b = start2 + 2;
		int c = start2 + 3;
		spaces[start1][a] = 1;
		spaces[start1][b] = 1;
		spaces[start1][c] = 1;
	}
	for (int d = 15; d > 0; d--)
	{
		ammo = d;
		display(spaces);
		hit = coordinates(spaces,x,y,ammo);
		if (hit == 1)
		{
			spaces[x][y] = 2;
			cout << "Hit!" << endl;
		}
		else 
		{
			spaces[x][y] = 3;
			cout << "Miss!" << endl;
		}
		if(orient == 0)
		{
			int a = start1 + 1;
			int b = start1 + 2;
			int c = start1 + 3;
			if (spaces[start1][start2] == 2 && spaces[a][start2] == 2 && spaces[b][start2] == 2 && spaces[c][start2] == 2)
			{
				display(spaces);
				cout << "You've sunk the battleship!";
				d = 0;
				sink = 1;
			}
		}
		else if (orient == 1)
		{
			int a = start2 + 1;
			int b = start2 + 2;
			int c = start2 + 3;
			if (spaces[start1][start2] == 2 && spaces[start1][a] == 2 && spaces[start1][b] == 2 && spaces[start1][c] == 2)
			{
				display(spaces);
				cout << "You've sunk the battleship!";
				d = 0;
				sink = 1;
			}
		}
		if (d == 1)
		{
			cout << "You've run out of torpedoes.";
		}
	}
	return 0;
}

void display(vector<vector <int> > spaces)
{
	int a;
	for(int y = 0; y < 8; y++)
	{
		for(int x = 0; x < 8; x++)
		{	
			a = spaces[x][y];
			char b = ascii(a);
			cout << b << " ";
		}
		cout << endl;
	}
}

int coordinates(vector< vector <int> > spaces, int &x, int &y, int &ammo)
{
	int hit;
	cout << ammo << " Torpedoes remain. Fire where? ";
	cin >> x >> y;
	x = x - 1;
	y = y - 1;
	hit = detect(spaces[x][y]);
	return hit;
}

int detect(int &a)
{
	if(a == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char ascii(int &a)
{
	if(a == 0 || a == 1) 
	{
		return '.';
	}
	else if (a == 2)
	{
		return 'x';
	}
	else
	{
		return 'o';
	}
}	

