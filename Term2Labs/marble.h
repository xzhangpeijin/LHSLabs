// marbles.h  
//******************************************************************//
// marbles class implementation
//******************************************************************//
#include <iostream>

using namespace std;

class MarbleJar
{
public:
	MarbleJar(int black, int white);					// initializes jar contents
	string DrawMarble();											// draws and returns color
	void AddMarble (string color);						// adds marble to jar
	bool IsEmpty ();													// returns true(1) if empty
private:
	int myNumberBlack, myNumberWhite;				// marbles in the jar
	int myRandom (int num);									// returns random number
};


MarbleJar :: MarbleJar (int black, int white)
{
		myNumberBlack = black;
		myNumberWhite = white;
	  srand (time(0));						// randomizes sequence
}

string MarbleJar :: DrawMarble ()
{
	 string answer;
   if (! IsEmpty ())
	 {
		 if(myRandom(myNumberBlack+myNumberWhite)<myNumberBlack)
	     answer = "Black";
		 else 
			 answer = "White";
		 if (answer == "Black")
			 myNumberBlack = myNumberBlack - 1;
		 else if (answer == "White")
		   myNumberWhite = myNumberWhite - 1;
		 else 
			 answer = "An invalid color";
     return answer;
	 }
	 else
		 cout<<"The jar is empty\n";
	 return "no marble";
}

void MarbleJar :: AddMarble (string color)
{
	 if (color == "White")
		  myNumberWhite = myNumberWhite + 1;
	 else if (color == "Black")
			myNumberBlack = myNumberBlack + 1;
	 else 
		 cout << "Invalid color" << endl;
}

bool MarbleJar :: IsEmpty ()
{
    if (myNumberWhite == 0 && myNumberBlack == 0)
		  return true;
    else 
			return false;
}

int MarbleJar :: myRandom (int num)
{
    return (rand() % num);
}