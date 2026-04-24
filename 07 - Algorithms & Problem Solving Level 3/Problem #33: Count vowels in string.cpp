#include <iostream>
#include <string>
using namespace std;

string ReadStringFromUser(string Message)
{
	cout << Message;
	string Sent = "";
	getline(cin, Sent);
	return Sent;
}

char ReadCharFromUser(string Message)
{
	cout << Message;
	char Char;
	cin >> Char;
	return Char;
}

bool IsVowel(char LetterV)
{
	if (tolower(LetterV) == tolower('a') || tolower(LetterV) == tolower('e') || tolower(LetterV) == tolower('i') || tolower(LetterV) == tolower('o') || tolower(LetterV) == tolower('u'))
		return true;
	else return false;
}

short CountVowelsInString(string Sent1)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (IsVowel(Sent1[i]))
			Counter++;
	}
	return Counter;
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	cout << "\nThere are (" << CountVowelsInString(Sent1) << ") vowel/s in the sentence.";
	return 0;
}
