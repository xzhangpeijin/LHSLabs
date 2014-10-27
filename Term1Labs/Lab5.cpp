#include <iostream> 
using namespace std;

int main()
{
	double x1, y1, x2, y2;
	
	for ( int x = 0; x < 4 ; x++)
	{ 
		cout << "Enter the cordinates of point 1 (x, y): "; 
		cin >> x1 >> y1;
		cout << "Enter the coordinates of point 2 (x, y): ";
		cin >> x2 >> y2;
	
		if ( x1 == x2 && y1 == y2 )  
		{
			cout << "Alert! These points do not form a line." << endl;
			cout << endl;
		}
		else if ( x1 == x2 )
		{ 
			cout << "Alert! The line is horizontal" << endl;
			cout << endl;
		}
		else if ( y1 == y2 )
		{ 
			cout << "Alert! The line is vertical" << endl;
			cout << endl;
		}
		else 
		{
			cout << "The equation of the line is y = " << ( y2 - y1 ) / ( x2 - x1 ) << "x + " << y1-(x1*(( y2 - y1 ) / ( x2 - x1 ))) << endl; 
		}
	}
	
	return 0;
	
}