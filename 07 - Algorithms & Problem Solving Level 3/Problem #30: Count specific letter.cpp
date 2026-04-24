#include <iostream>
#include <string>
using namespace std;


char ReadCharFromUser(string Message)
{
	cout << Message;
	char Char;
	cin >> Char;
	return Char;
}
string ReadStringFromUser(string Message)
{
	cout << Message;
	string Sent = "";
	getline(cin, Sent);
	return Sent;
}

short CountSpecificLetter(string Sent1, char Letter)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (Sent1[i] == Letter)
			Counter++;
	}
	return Counter;
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	char Letter = ReadCharFromUser("Enter a letter tp count: ");

	cout << "\nLetter [ " << Letter << " ] found: " << CountSpecificLetter(Sent1, Letter) << " times.\n";
	return 0;
}
