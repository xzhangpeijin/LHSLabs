/*	Quiz D				Your Name Here		*/

#include <iostream>
#include <iomanip>

using namespace std;

void convert(string message, string converted[]);
void display(string message, string converted[]);
string morse(char &letter);
string Uppercase(string message);

int main()
{
	string message;
	cout<<"Please enter a message: ";
	getline(cin, message);
	const int len = message.size();
	string converted[len];
	message = Uppercase(message);
	convert(message,converted);
	display(message,converted);
	return 0;
	
}


void convert(string message, string converted[])
/*	Message is parsed and array loaded with the proper morse code characters                         
Post: message unchanged and converted full of morse code                              */

{
	for(int x=0; x< message.size(); x++)
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

string Uppercase(string message)
/*	Returns a copy of S with all lowercase characters converted to 
 uppercase characters                         
 Post: String in all uppercase letters returned                              */
{
	for (int Letter=0; Letter<message.size(); Letter++)
	{
		if ((message[Letter] >='a') && (message[Letter] <= 'z'))
			message[Letter]=message[Letter]-'a'+'A';
	}
	return message;
}

void display(string message, string converted[])
/*	Displays the original message in all Uppercase followed by the Morse Code version                         
Post: Message and converted unchanged                             */

{
	cout << "Here is your original message: "<<endl<<message<<endl;
	cout << "Here is the Morse Code conversion: "<<endl;
	for(int x=0; x< message.size(); x++)
	{
		cout << converted[x];
	}
}