/*	Quiz D				Your Name Here		*/

#include <iostream>
#include <iomanip>
using namespace std;

void convert(string message, string& converted);
void display(string message, string converted);
string morse(char letter);
string Uppercase(string &S);

int main()
{
	string message;
	cout<<"Please enter a message:";
	getline(cin, message);
	int a = message.size();
	string converted[a];
	message = Uppercase(message);
	string convert(message, converted);
	display(message,converted);
	return 0;
	
}


void convert(string message, string &converted)
/*	Message is parsed and array loaded with the proper morse code characters                         
Post: message unchanged and converted full of morse code                              */
{
	for(int x=0; x < message.size(); x++)
	{
		converted[x] = morse(message[x]);
	}
}

string morse(char& letter)
/*	Returns the morse code representation of the uppercase character letter                         
Post: a string is returned                              */
{
	switch(letter)
	{
		case 'A': return ".-"; break;
		case 'B': return "-..."; break;
		case 'C': return "-.-."; break;
		case 'D': return "-.."; break;
		case 'E': return "."; break;
		case 'F': return "..-."; break;
		case 'G': return "--."; break;
		case 'H': return "...."; break;
		case 'I': return ".."; break;
		case 'J': return ".---"; break;
		case 'K': return "-.-"; break;
		case 'L': return ".-.."; break;
		case 'M': return "--"; break;
		case 'N': return "-."; break;
		case 'O': return "---"; break;
		case 'P': return ".--."; break;
		case 'Q': return "--.-"; break;
		case 'R': return ".-."; break;
		case 'S': return "..."; break;
		case 'T': return "-"; break;
		case 'U': return "..-"; break;
		case 'V': return "...-"; break;
		case 'W': return ".--"; break;
		case 'X': return "-..-"; break;
		case 'Y': return "-.--"; break;
		case 'Z': return "--.."; break;
		case '0': return "-----"; break;
		case '1': return ".----"; break;
		case '2': return "..---"; break;
		case '3': return "...--"; break;
		case '4': return "....-"; break;
		case '5': return "....."; break;
		case '6': return "-...."; break;
		case '7': return "--..."; break;
		case '8': return "---.."; break;
		case '9': return "----."; break;
		case '.': return ".-.-.-"; break;
		case ',': return "--..--"; break;
		case '?': return "..--.."; break;
		default: return " ";		
	}
}

string Uppercase(string &S)
/*	Returns a copy of S with all lowercase characters converted to 
 uppercase characters                         
 Post: String in all uppercase letters returned                              */
{
	for (int Letter=0; Letter < S.size(); Letter++)
	{
		switch(S[Letter])
		{
			case 'a': S[Letter] = 'A'; break;
			case 'b': S[Letter] = 'B'; break;
			case 'c': S[Letter] = 'C'; break;
			case 'd': S[Letter] = 'D'; break;
			case 'e': S[Letter] = 'E'; break;
			case 'f': S[Letter] = 'F'; break;
			case 'g': S[Letter] = 'G'; break;
			case 'h': S[Letter] = 'H'; break;
			case 'i': S[Letter] = 'I'; break;
			case 'j': S[Letter] = 'J'; break;
			case 'k': S[Letter] = 'K'; break;
			case 'l': S[Letter] = 'L'; break;
			case 'm': S[Letter] = 'M'; break;
			case 'n': S[Letter] = 'N'; break;
			case 'o': S[Letter] = 'O'; break;
			case 'p': S[Letter] = 'P'; break;
			case 'q': S[Letter] = 'Q'; break;
			case 'r': S[Letter] = 'R'; break;
			case 's': S[Letter] = 'S'; break;
			case 't': S[Letter] = 'T'; break;
			case 'u': S[Letter] = 'Y'; break;
			case 'v': S[Letter] = 'V'; break;
			case 'w': S[Letter] = 'W'; break;
			case 'x': S[Letter] = 'X'; break;
			case 'y': S[Letter] = 'Y'; break;
			case 'z': S[Letter] = 'Z'; break;
			default: S[Letter] = S[Letter];
		}
	}
	return S ;
}

void display(string message, string converted)
/*	Displays the original message in all Uppercase followed by the Morse Code version                         
Post: Message and converted unchanged                             */

{
	cout << "Here is your original message:"<<message<<endl;
	cout << "Here is the Morse Code conversion:"<<endl;
	for(int x=0; x< message.size(); x++)
	{
		cout << " ";
	}
}