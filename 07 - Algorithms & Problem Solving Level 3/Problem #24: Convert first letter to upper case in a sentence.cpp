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

string ConvertFirstLetterToUpper(string Sent)
{
	bool isFirstLetter = true;
	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ' && isFirstLetter)
		{
			Sent[i] = towupper(Sent[i]);
		}
		isFirstLetter = (Sent[i] == ' ' ? true : false);
	}
	return Sent;
}

int main()
{
	string Sent = ReadStringFromUser("Enter your sentence: \n");
	cout << "\n\nConverting first letter of each word to upper case: \n" << ConvertFirstLetterToUpper(Sent);

	
	return 0;
}
