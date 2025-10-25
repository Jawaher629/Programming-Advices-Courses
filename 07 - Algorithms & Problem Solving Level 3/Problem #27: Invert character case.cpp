#include <iostream>
#include <string>
using namespace std;

char ReadUsersChar(string Message)
{
	char Sent;
	cout << Message;
	cin >> Sent;
	return Sent;
}


char InvertChar(char Char1)
{
	return isupper(Char1) ? tolower(Char1): toupper(Char1);
}




int main()
{
	char Char1 = ReadUsersChar("Enter your character to invert: ");

	cout << "Character inverted to upper / lower case: \n";
	Char1 = InvertChar(Char1);
  
	cout << Char1 << endl << endl;


	system("pause>0");
	return 0;
}
