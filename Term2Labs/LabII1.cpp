#include <fstream>
#include <iostream>
using namespace std;

string get(string &email);
void id(string email);
void type(string email);


int main()
{
	string email;
	email = get(email);
	id(email);
	type(email);
}
	
string get(string &email)
// pre: one string
// post: email address
{
	cout << "Enter your email address: ";
	getline(cin,email);
	return email;
}

void id(string email)
// pre: one string
// post: none
{	
	int at, valid, length;
	do
	{
		at = 0;
		valid = 1;
		length = 0;
		while (at != 1)
		{
			if(email[length] == '@')
			{
				at = 1;
			}
			else
			{
				length = length + 1;
			}
			if (length == email.size() && at != 1)
			{
				cout << "Invalid email" << endl;
				valid = 0;
				get(email);
			}
		}
	}while(valid = 0);
	cout << "Your ID is: ";
	for (int x = 0; x < length; x++)
	{
		cout << email[x];
	}
}

void type(string email)
// pre: one string
// post: none
{
	int dot, length, valid;
	do
	{
		dot = 0;
		length = email.size() - 1;
		valid = 1;
		while (dot != 1)
		{
			if(email[length] == '.')
			{
				dot = 1;
			}
			else
			{
			length = length - 1;
			}
			if (length == 0 && dot != 1)
			{	
				cout << "\nInvalid email" << endl;
				valid = 0;
				get(email);
				id(email);
			}
		}
	}while(valid == 0);
	int a = length + 1;
	int b = length + 2;
	int c = length + 3;
	cout << "\nYour site type is: ";
	if (email[a] == 'e' && email[b] == 'd' && email[c] == 'u')
	{
		cout << "edu    Educational institutions";
	}
	else if (email[a] == 'o' && email[b] == 'r' && email[c] == 'g')
	{
		cout << "org    Not-for-profit organizations";
	}
	else if (email[a] == 'g' && email[b] == 'o' && email[c] == 'v')
	{
		cout << "gov    Government entities";
	}
	else if (email[a] == 'm' && email[b] == 'i' && email[c] == 'l')
	{
		cout << "mil    Military installations";
	}
	else if (email[a] == 'n' && email[b] == 'e' && email[c] == 't')
	{
		cout << "net    Network service providers";
	}
	else if (email[a] == 'c' && email[b] == 'o' && email[c] == 'm')
	{
		cout << "com    Commercial ventures";
	}
	else
	{
		int d = email.size() - a;
		if (d == 3)
		{
			cout << email[a] << email[b] << email[c] << "    Country code";
		}
		else if (d == 2)
		{
			cout << email[a] << email[b] << "    Country code";
		}
		else
		{
			cout << "Invalid site type";
		}
	}
}


