#include <iostream>
#include <string>
using namespace std;


char InvertChar(char Char1)
{
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}


string ReadUsersString(string Message)
{
	string Sent;
	cout << Message;
	getline(cin,Sent);
	return Sent;
}


string InvertAlltLetterOfString(string Sent)
{


	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ')
		{
			Sent[i] = InvertChar(Sent[i]);
		}
		
	}
	return Sent;
}






int main()
{
	string Sent1 = ReadUsersString("Enter your sentense to invert: ");

	cout << "String after Inverting All Letters Case: \n";
	Sent1 = InvertAlltLetterOfString(Sent1);
	cout << Sent1 << endl << endl;


	system("pause>0");
	return 0;
}
