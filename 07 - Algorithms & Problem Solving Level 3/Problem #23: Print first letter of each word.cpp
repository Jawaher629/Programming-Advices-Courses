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

void PrintFirstLetterOfEachWord(string Sent)
{
	bool isFirstLetter = true;
	cout << "\nFirst letters of this string: \n";
	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ' && isFirstLetter)
		{
			cout << Sent[i] << ", ";
		}
		isFirstLetter = (Sent[i] == ' ' ? true : false);
	}
}

int main()
{
	PrintFirstLetterOfEachWord(ReadStringFromUser("Enter your sentense: \n"));
	
	return 0;
}
