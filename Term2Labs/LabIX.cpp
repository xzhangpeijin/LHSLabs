// ***********************************
// * Lab IX				Peijin Zhang *
// * Jar o' Marbles					 *
// ***********************************
//
// Analysis:
// 1. Suppose there are x white marbles and x black marbles. If they are the same, the probability is merely 1 * (x - 1)/(2x -1).
//    If they are different, the probability is 1 * (x)/(2x - 1). Since x > x - 1, it will always be more probable that the two 
//    Marbles are different.
// 2. Increasing the total number of marbles in the jar does affect the results, since doing so will  make the difference between
//    x and x - 1 much less.

#include <iostream>
#include "marble.h"
using namespace std;

int main()
{
	int black, white;
	double different = 0, same = 0;
	string draw1, draw2;
	cout << "Enter number of black and white marbles: ";
	cin >> black >> white;
	MarbleJar jar(black,white);
	for(int x = 0; x < 1000; x++)
	{
		draw1 = jar.DrawMarble();
		draw2 = jar.DrawMarble();
		jar.AddMarble(draw1);
		jar.AddMarble(draw2);
		if(draw1 == draw2)
			same++;
		else
			different++;
	}
	same = same / 10;
	different = different / 10;
	cout << "They were the same " << same << "% of the time, different " << different << "% of the time.";
	return 0;
}