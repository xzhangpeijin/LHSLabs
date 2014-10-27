#include <fstream>
#include <iostream>
using namespace std;

void songs(string song[], int tracks);

int main()
{
	string name;
	string song[10]; //maximum of 10 songs, change if more
	int tracks = 0;
	ifstream infile("playlist.txt");
	if (infile.fail())
	{
		cout << "File not found.";
		exit(1);
	}
	else
	{
		getline(infile,name);
		for (int x = 0; x < 10; x++)
		{
			if (getline(infile,song[x]))
			{
				tracks = tracks + 1;
			}
		}
		infile.close();
	}
	cout << name << endl;
	cout << "--------------------------------------------------" << endl;
	songs(song, tracks);
	return 0;
}

void songs(string song[], int tracks)
{
	int size, minutes, seconds, hours = 0, name, colon, totalminutes = 0, totalseconds = 0;
	string artist, songnames;
	for (int x = 0; x < tracks; x++)
	{
		size = song[x].size();
		name = song[x].find_last_of('"');
		songnames = song[x].substr(1, name - 1);
		colon = song[x].find(':');
		string a = song[x].substr(colon - 1, 1);
		string b = song[x].substr(colon + 1, 2);
		minutes = atoi(a.c_str());
		seconds = atoi(b.c_str());
		artist = song[x].substr(colon + 4, size - colon - 4);
		totalminutes = totalminutes + minutes;
		totalseconds = totalseconds + seconds;
		if (totalseconds > 59)
		{
			totalseconds = totalseconds - 60;
			totalminutes = totalminutes + 1;
		}
		if (totalminutes > 59)
		{
			totalminutes = totalminutes - 60;
			hours = hours + 1;
		}
		if (x != 9)
		{
			cout << " ";
		}
		cout << x + 1 << ". " << a << ":" << b << " " << songnames << " by " << artist << endl;
	}
	cout << "--------------------------------------------------" << endl;
	cout << "Total Playing Time: ";
	if ( hours > 0)
	{
		cout << hours << ":";
	}
	cout << totalminutes << ":" << totalseconds;
}