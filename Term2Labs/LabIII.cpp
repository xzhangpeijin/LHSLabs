// *********************************
// * Lab III          Peijin Zhang *
// * Arithmetic Functions          *
// *********************************

#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

double mean(int integer[], int integers);
double median(int integer[], int integers);
void mode(int integer[], int integers);
double range(int integer[], int integers);
double standev(int integer[], int integers);
void swap(int &a, int &b);

int main()
{
	string a;
	int integer[50]; // maximum amount of integers is 50, change if more.
	int choice;
	int integers = 0;
	double result;
	ifstream infile("LabIII.txt");
	for (int x = 0; x < 50; x++)
	{
		if (getline(infile,a))
		{
			integer[x] = atoi(a.c_str());
			integers = integers + 1;
		}
	}
	infile.close();
	do
	{
		cout << "Enter your choice: \n"
			 << "0. Quit \n"
			 << "1. Mean \n"
			 << "2. Median \n"
			 << "3. Mode \n"
			 << "4. Range \n"
			 << "5. Standard Deviation \n";
		cin >> choice;
		switch(choice)
		{
			case 1:		result = mean(integer, integers); break;
			case 2:		result = median(integer, integers); break;
			case 4:		result = range(integer, integers); break;
			case 5:		result = standev(integer, integers);
		}
		switch(choice)
		{
			case 1:		cout << "The mean is: " << result << endl; break;
			case 2:		cout << "The median is: " << result << endl; break;
			case 4:		cout << "The range is: " << result << endl; break;
			case 5:		cout << "The standard deviation is: " << result << endl;
		}
		if (choice == 3)
		{
			mode(integer, integers);
		}
	}while(choice != 0);
	return 0;
}

double mean(int integer[], int integers)
{
	double sum = 0;
	double mean;
	for (int x = 0; x < integers; x++)
	{
		sum = sum + integer[x];
	}
	mean = sum * 1.000 / integers;
	return mean;
}

double median(int integer[], int integers)
{
	int stop = 1;
	int limit = integers - 1;
	double median;
	while (stop != 0)
	{
		stop = 0;
		for (int x = 0; x < limit; x++)
		{
			int a = x + 1;
			if (integer[x] < integer[a])
			{
				swap(integer[x],integer[a]);
				stop = stop + 1;
			}
		}
	}
	if (integers % 2 == 0)
	{
		int a = (integers / 2) - 1;
		int b = integers / 2;
		median = (integer[a] + integer[b]) / 2;
	}
	else
	{
		int a = (integers / 2);
		median = integer[a];
	}
	return median;
}
	
void mode(int integer[], int integers)
{
	int values[integers][2];
	int start = 0;
	int valid;
	int max = 0; 
	for (int x = 0; x < integers; x++)
	{
		values[x][1] = -1;
		values[x][0] = -1;
	}
	for (int x = 0; x < integers; x++)
	{
		for (int y = 0; y < integers; y++)
		{
			if (integer[x] == values[y][0])
			{
				values[y][1] = values[y][1] + 1;
				valid = 1;
			}
		}
		if ( valid != 1)
		{
			values[start][0] = integer[x];
			values[start][1] = 1;
			start = start + 1;
		}
	}
	valid = 0;
	for (int x = 0; x < integers; x++)
	{
		if ( values[x][1] > max)
		{
			max = values[x][1];
		}
	}
	for (int x = 0; x < integers; x++)
	{
		if(max == values[x][1])
		{
			valid = valid + 1;
		}
	}
	if ( valid == 1)
	{
		cout << "The mode is: "; 
	}
	else
	{
		cout << "The modes are: ";
	}
	for (int x = 0; x < integers; x++)
	{	
		if(max == values[x][1])
		{
			cout << values[x][0] << " ";
		}
	}
	cout << endl;
}		

double range(int integer[], int integers)
{
	double range;
	int stop = 1;
	int limit = integers - 1;
	while (stop != 0)
	{
		stop = 0;
		for (int x = 0; x < limit; x++)
		{
			int a = x + 1;
			if (integer[x] < integer[a])
			{
				swap(integer[x],integer[a]);
				stop = stop + 1;
			}
		}
	}
	range = integer[0] - integer[limit];
	return range;
}

double standev(int integer[],int integers)
{
	double average = mean(integer, integers);
	double standev = 0;
	for ( int x = 0; x < integers; x++)
	{
		standev = standev + integer[x] - average;
	}
	standev = standev / (integers - 1);
	standev = pow(standev,0.5);
	return standev;
}
	
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b; 
	b = temp;
}













