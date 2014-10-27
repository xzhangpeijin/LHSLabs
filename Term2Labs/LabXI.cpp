// *****************************************
// * Peijin Zhang		Lab XI ( Lab 15? ) *
// * Going the Distance					   *
// *****************************************

#include <iostream>
using namespace std;

class Distance
{
	public:
		Distance(); 
		Distance(int f, int i); 
		void get(); 
		void show(); 
		Distance operator + (const Distance &d); 
		Distance operator * (const Distance &d); 
	private:
		int feet, inches;
};

Distance :: Distance()
{
	feet = 0;
	inches = 0;
}

Distance :: Distance(int f, int i)
{
	feet = f;
	inches = i;
}

void Distance :: get()
{
	cout << "Enter feet: ";
	cin >> feet;
	cout << "Enter inches: ";
	cin >> inches;
}

void Distance :: show()
{
	cout << feet << " feet, " << inches << " inches.";
}

Distance Distance :: operator + (const Distance &d)
{
	Distance perimeter;
	perimeter.inches = inches + d.inches;
	perimeter.feet = feet + d.feet;
	if(perimeter.inches >= 12)
	{
		do
		{
			perimeter.inches = perimeter.inches - 12;
			perimeter.feet++;
		}while(perimeter.inches >= 12);
	}
	return perimeter;
}	

Distance Distance :: operator * (const Distance &d)
{
	Distance area;
	area.inches = ( feet * 12 + inches ) * ( d.feet * 12 + d.inches );
	if(area.inches >= 144)
	{
		do
		{
			area.inches = area.inches - 144;
			area.feet++;
		}while(area.inches >= 144);
	}
	return area;
}

int main()
{
	Distance d1, d2, perimeter, area;
	cout << endl << "Length of Room" << endl;
	d1.get();
	cout << endl << "Width of Room" << endl;
	d2.get();
	perimeter = d1 + d1 + d2 + d2;
	cout << endl << "Perimeter of Room: ";
	perimeter.show();
	area = d1 *d2;
	cout << endl << "Square footage of Room: ";
	area.show();
	return 0;
}