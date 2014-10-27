// *********************************
// * Peijin Zhang		Project II *
// * Road Map					   *
// *********************************

// Didn't see the example on the back. Instructions were vague. >:(

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void input(int &x, string &a, vector< vector<int> > &distances);
void maxmin(vector< vector<int> > distances, int cities, vector<string> citynames);
void travel(vector< vector<int> > distances, int cities, vector<string> citynames);

int main()
{	
	int cities;
	string a;
	ifstream infile("ProjectII.txt");
	getline(infile,a);
	cities = atoi(a.c_str());
	vector<string> citynames(cities);
	vector< vector<int> > distances(cities,vector<int>(cities,0));
	for(int x = 0; x < cities; x++)
		getline(infile,citynames[x]);
	for(int n = 0; n < cities - 1; n++)
	{
		getline(infile,a);
		input(n,a,distances);
	}
	maxmin(distances,cities,citynames);
	travel(distances,cities,citynames);
	return 0;
}

void input(int &row, string &a, vector< vector<int> > &distances)
{
	int space, y = 0;
	row++;
	do
	{
		space = a.find(' ');
		if(space == -1)
		{
			distances[row][row-1] = atoi(a.c_str());
			distances[row-1][row] = distances[row][row-1];
		}	
		else
		{
			string b;
			int size = a.size();
			b = a.substr(0,space);
			distances[row][y] = atoi(b.c_str());
			distances[y][row] = distances[row][y];
			int m = space + 1;
			int n = size - m;
			a = a.substr(m,n);
			y++;
		}
	}while(space != -1);
	row--;
}
	
void maxmin(vector< vector<int> > distances, int cities, vector<string> citynames)
{
	int max = 0, min = 20000;
	for(int x = 0; x < cities; x++)
	{
		for(int y = 0; y < cities; y++)
		{
			if(distances[x][y] > max)
				max = distances[x][y];
			if(distances[x][y] < min && distances[x][y] != 0)
				min = distances[x][y];
		}
	}
	for(int x = 0; x < cities; x++)
	{
		for(int y = 0; y < cities; y++)
		{
			if(max == distances[x][y])
			{
				cout << "The maxmimum distance is between " << citynames[x] << " and " << citynames[y] << ". (" << distances[x][y] << ")" << endl;
				max = -1;
			}
			if(min == distances[x][y])
			{
				cout << "The minimum distance is between " << citynames[x] << " and " << citynames[y] << ". (" << distances[x][y] << ")" << endl;
				min = -1;
			}
		}
	}
}

void travel(vector< vector<int> > distances, int cities, vector<string> citynames)
{
	int total = 0, city1, city2;
	cout << "\nMenu of Cities \n"
		 << "-------------- \n";
	for(int x = 0; x < cities; x++)
		cout << x << ". " << citynames[x] << endl;
	cout << "\nEnter your starting city: ";
	cin >> city1;
	do
	{
		cout << "Next stop after " << citynames[city1] << "? (Enter -1 to end): ";
		cin >> city2;
		if(city2 != -1)
		{
			total = total + distances[city1][city2];
		}
		city1 = city2;
	}while(city2 != -1);
	cout << "Your total distance traveled is: " << total;
}
	