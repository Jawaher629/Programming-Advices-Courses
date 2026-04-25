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

void PrintEachWordInStringAndCount(string Sent1, string delim)
{
	short counter = 0;
	short pos = 0;
	string sWord;
	cout << "Your string words: \n";
	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
			cout << "- " << sWord << endl;
		Sent1.erase(0, pos + delim.length());
		counter++;
	}
	if (Sent1 != "")
		cout << "- " << Sent1 << endl;
	cout << "\nWords count: " << counter << "words.";
}


void CountEachWordInString(string Sent1, string delim)
{
	short counter = 0;
	short pos = 0;
	string sWord;
	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
		Sent1.erase(0, pos + delim.length());
		counter++;
	}
	if (Sent1 != "")
	cout << "Words count: " << counter << " words";
	counter++;
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	PrintEachWordInString(Sent1, " ");
	
	return 0;
}
