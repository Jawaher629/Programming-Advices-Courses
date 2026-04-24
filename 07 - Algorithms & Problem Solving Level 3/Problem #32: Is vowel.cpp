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

bool IsVowel(char LetterV)
{
	if (tolower(LetterV) == 'a' || tolower(LetterV) == 'e' || tolower(LetterV) == 'i' || tolower(LetterV) == 'o' || tolower(LetterV) == 'u')
		return true;
	else return false;
}


int main()
{
	char Letter = ReadCharFromUser("Enter a letter to check: ");
	if (IsVowel(Letter))
		cout << "\nYes,(" << Letter << ") is a vowel.\n";
	else
		cout << "\nNo,(" << Letter << ") is NOT a vowel.\n";
	return 0;
}
