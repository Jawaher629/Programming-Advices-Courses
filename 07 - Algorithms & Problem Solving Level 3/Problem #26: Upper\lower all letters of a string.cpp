#include <iostream>
#include <string>
using namespace std;

string ReadUsersString(string Message)
{
	string Sent;
	cout << Message;
	getline(cin, Sent);
	return Sent;
}


string ConvertFirstLetterToUpperCase(string Sent)
{


	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ')
		{
			Sent[i] = toupper(Sent[i]);
		}
		

	}


	return Sent;
}


string ConvertFirstLetterToLowerCase(string Sent)
{


	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ')
		{
			Sent[i] = tolower(Sent[i]);
		}

	}

	
	return Sent;
}



int main()
{
	string S1 = ReadUsersString("Enter your sentence to convert: ");

	cout << "Sentence converted to upper case: \n";
	S1 = ConvertFirstLetterToUpperCase(S1);
	cout << S1 << endl << endl;

	cout << "Sentence converted to lower case: \n";
	S1 = ConvertFirstLetterToLowerCase(S1);
	cout << S1 << endl<< endl;



	system("pause>0");
	return 0;
}
