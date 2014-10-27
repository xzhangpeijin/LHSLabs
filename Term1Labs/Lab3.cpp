#include <iostream> 
using namespace std;

int main()
{
	int w, h, p, a;
	cout << "Enter width and height separated by a space: ";
	cin >> w >> h;
	p = w + w + h + h;
	a = w * h;
	cout << "Perimeter is: " << p << endl
		 << "Area is: " << a << endl;
		 
	return 0;
	
}