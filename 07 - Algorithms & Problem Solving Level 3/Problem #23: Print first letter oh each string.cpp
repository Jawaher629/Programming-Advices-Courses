// My solution:

#include <iostream>
#include <string>
using namespace std;

string ReadUsersString()
{
	string Sent;
	cout << "Enter your sentence please: ";
	getline(cin, Sent);
	return Sent;
}


void PrintFirstLettOfEachWord()
{
	string Sent = ReadUsersString();
	cout << "First letter of each word: \n";

	if (Sent[0] != ' ');
	cout << Sent[0] << endl;

	for (int i = 0; i < Sent.length(); i++)
	{
		if (Sent.at(i) == ' ')
			cout << Sent.at(i + 1) << "\n";
	}
}



int main()
{
	PrintFirstLettOfEachWord();
	system("pause>0");
	return 0;
}


// Dr.Abo Hahoud Solution:

#include <iostream>
#include <string>
using namespace std;

string ReadUsersString()
{
	string Sent;
	cout << "Enter your sentence please: ";
	getline(cin, Sent);
	return Sent;
}


void PrintFirstLettOfEachWord(string Sent)
{
	cout << "First letter of each word: \n";

	bool IsFirstLetter = true;

	for (int i = 0; i < Sent.length(); i++)
	{
		if (Sent.at(i) != ' ' && IsFirstLetter)
			cout << Sent.at(i) << "\n";

		IsFirstLetter = (Sent[i] == ' ' ? true : false);
	}
}



int main()
{
	PrintFirstLettOfEachWord(ReadUsersString());
	system("pause>0");
	return 0;
}
