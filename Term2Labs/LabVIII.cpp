// ********************************
// * LabVIII         Peijin Zhang *
// * Queens						  *
// ********************************

// My program didn't work because I spelled correct as coorect...

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void choose(vector< vector<char> > &board);
void fill(vector< vector<char> > &board, int &a, int &b);
bool correct(vector< vector<char> > &board);
bool full(vector< vector<char> > &board);
void display(vector< vector<char> > &board);
void clear(vector< vector<char> > &board);

int main()
{
	srand(time(0));
	bool solution;
	vector< vector<char> > board(8,vector<char>(8,' '));
	do
	{
		choose(board);
		solution = correct(board);
		if(! solution)
			clear(board);
	}while(! solution);
	display(board);
	return 0;
}

void choose(vector< vector<char> > &board)
{
	int a = (rand()) % 8;
	int b = (rand()) % 8;
	if(board[a][b] != 'Q' && board[a][b] != 'X')
		fill(board,a,b);
	else
		choose(board);
}

void fill(vector< vector<char> > &board, int &a, int &b)
{
	bool filled;
	for(int m = 0; m < 8; m++)
	{
		int w = a + m;
		int x = a - m;
		int y = b + m;
		int z = b - m;
		if(w < 7 && y < 7)
			board[w][y] = 'X';
		if(w < 7 && z > 0)
			board[w][z] = 'X';
		if(x > 0 && y < 7)
			board[x][y] = 'X';
		if(x > 0 && z > 0)
			board[x][z] = 'X';
		board[a][m] = 'X';
		board[m][b] = 'X';
	}
	board[a][b] = 'Q';
	filled = full(board);
	if(! filled)
		choose(board);
	
}

bool correct(vector< vector<char> > &board) 
{
	int a = 0;
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			if(board[x][y] == 'Q')
				a++;
		}
	}
	if(a == 8)
		return true;
	else
		return false;
}

bool full(vector< vector<char> > &board)
{
	int a = 0;
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			if(board[x][y] == ' ')
				a = 1;
		}
	}
	if(a == 1)
		return false;
	else
		return true;
}
	
void display(vector< vector<char> > &board)
{
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			cout << board[x][y] << " ";
		}
		cout << endl;
	}
}

void clear(vector< vector<char> > &board)
{
	for(int x = 0; x < 8; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			board[x][y] = ' ';
		}
	}
}