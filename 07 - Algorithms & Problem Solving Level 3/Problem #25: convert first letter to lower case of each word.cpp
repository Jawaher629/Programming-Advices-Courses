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

string ConvertFirstLetterToLowerCase(string Sent)
{

	bool IsFirstLetter = true;

	for (short i = 0; i < Sent.length(); i++)
	{
		if (Sent[i] != ' ' && IsFirstLetter)
		{
			Sent[i] = tolower(Sent[i]);
		}
		IsFirstLetter = (Sent[i] == ' ' ? true : false);

	}

	
	return Sent;
}



int main()
{
	string S1 = ReadUsersString("Enter your sentence to convert: ");

	cout << "Sentence after conversion: \n";
	S1 = ConvertFirstLetterToLowerCase(S1);
	cout << S1 << endl;



	system("pause>0");
	return 0;
}
