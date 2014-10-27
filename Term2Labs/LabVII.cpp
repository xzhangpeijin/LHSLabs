// *******************************
// * Lab VII		Peijin Zhang *
// * AreaFill					 *
// *******************************

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

string getfile();
void display(int width, int height, vector< vector<char> > &image);
void fill(int &cox, int &coy, int width, int height, vector< vector<char> > &image);

int main()
{
	int height = 0, width, cox, coy;
	char choice;
	vector< vector<char> > image;
	string filename, a;
	filename = getfile();
	ifstream infile(filename.c_str());
	while(getline(infile,a))
	{
		width = a.size();
		vector<char> vec;
		for(int x = 0; x < width; x++)
		{
			vec.push_back (a[x]);
		}
		image.push_back (vec);
		height++;
	}
	infile.close();
	display(width,height,image);
	do
	{
		cout << "Choose a fill point: ";
		cin >> cox >> coy;
		cox--;
		coy--;
		if(image[cox][coy] == 'X')
		{
			cout << "That point is black." << endl;
			choice = 'N';
		}
		else
		{	
			image[cox][coy] = '*';
			display(width,height,image);
			cout << "Use this point? (Y/N) ";
			cin >> choice;
			if(choice == 'N')
			{
				image[cox][coy] = '.';
			}
		}
	}while(choice == 'N');
	fill(cox,coy,width,height,image);
	display(width,height,image);
	return 0;
}

string getfile()
{
	string filename;
	cout << "Enter the name of the file: ";
	getline(cin,filename);
	return filename;
}

void display(int width, int height, vector< vector<char> > &image)
{
	for(int x = 0; x < height; x++)
	{
		for(int y = 0; y < width; y++)
		{
			cout << image[x][y];
		}
		cout << endl;
	}
}

void fill(int &cox, int &coy, int width, int height, vector< vector<char> > &image)
{
	int a = cox + 1;
	if(a == height)
		a = cox;
	int b = cox - 1;
	if(b == -1)
		b = cox;
	int c = coy + 1;
	if(c == width)
		c = coy;
	int d = coy - 1;
	if(d == -1)
		d = coy;
	image[cox][coy] = 'X';
	if(image[b][coy] == '.')
		fill(b,coy,width,height,image);
	if(image[a][coy] == '.')
		fill(a,coy,width,height,image);
	if(image[cox][c] == '.')
		fill(cox,c,width,height,image);
	if(image[cox][d] == '.')
		fill(cox,d,width,height,image);

}