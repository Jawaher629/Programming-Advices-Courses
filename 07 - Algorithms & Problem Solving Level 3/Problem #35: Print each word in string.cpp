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

void PrintEachWordInString(string Sent1, string delim)
{
	short pos = 0;
	string sWord;
	cout << "Your string words: \n";
	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
			cout << "- " << sWord << endl;
		Sent1.erase(0, pos + delim.length());
	}
	if (Sent1 != "")
		cout << "- " << Sent1 << endl;
}
int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	PrintEachWordInString(Sent1, " ");
	
	return 0;
}
