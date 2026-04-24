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

void PrintAllVowelsInString(string Sent1)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (IsVowel(Sent1[i]))
			cout << Sent1[i] << "   ";
	}
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	cout << "Vowels in string: ";
	PrintAllVowelsInString(Sent1);
	return 0;
}
