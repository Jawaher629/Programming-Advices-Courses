// My solution:
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

char InvertCase(char& Char)
{
	if (isupper(Char))
		return tolower(Char);
	if (islower(Char))
		return toupper(Char);
}


int main()
{
	char C = ReadCharFromUser("Enter a letter to invert: ");
	cout << "\nLetter you entered: " << C;
	cout << "\nLetter inverted: " << InvertCase(C) << endl;
	
	
	return 0;
}

//Dr. Abu Hsdhoud solution:

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

char InvertCase(char Char)
{
	return isupper(Char) ? tolower(Char) : toupper(Char);
}


int main()
{
	char C = ReadCharFromUser("Enter a letter to invert: ");
	cout << "\nLetter you entered: " << C;
	C = InvertCase(C);
	cout << "\nLetter inverted: " << C << endl;

	
	return 0;
}
