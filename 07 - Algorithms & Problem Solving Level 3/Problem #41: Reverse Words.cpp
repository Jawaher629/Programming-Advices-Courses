#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadStringFromUser(string Message)
{
	cout << Message;
	string Sent = "";
	getline(cin, Sent);
	return Sent;
}

vector <string> SplitString(string Sent1, string delim)
{
	vector <string> vWords;
	short pos = 0;
	string sWord;
	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
			vWords.push_back(sWord);
		Sent1.erase(0, pos + delim.length());
	}
	if (Sent1 != "")
		vWords.push_back(Sent1);
	return vWords;
}


string ReverseWordsInString(string Sent1)
{
	string RevSent = "";
	vector <string> vWords = SplitString(Sent1," ");

	vector <string>::iterator iterSent = vWords.end();
	while (iterSent != vWords.begin())
	{
		iterSent--;
		RevSent += *iterSent + " ";
	}


	return RevSent.substr(0, RevSent.length() - 1);

}

int main()
{
	string Sentence1 = ReadStringFromUser("Enter your sentence to reverse: ");

	cout << "Sentence after revers: " << ReverseWordsInString(Sentence1);


	return 0;
}
