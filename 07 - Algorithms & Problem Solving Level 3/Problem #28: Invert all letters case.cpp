#include <iostream>
#include <string>
using namespace std;


string ReadStringFromUser(string Message)
{
	string Sent = "";
	cout << Message;
	getline(cin, Sent);
	return Sent;
}


char InvertCase(char Char)
{
	return isupper(Char) ? tolower(Char) : toupper(Char);
}


string InvertAllLetters(string Sent1)
{
	for (int i = 0; i < Sent1.length(); i++)
	{
		Sent1[i] = InvertCase(Sent1[i]);
	 }
	return Sent1;
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	cout << "Sentence after inverted: " << InvertAllLetters(Sent1);
	
	return 0;
}
