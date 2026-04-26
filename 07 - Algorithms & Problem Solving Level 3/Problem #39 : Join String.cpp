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

void PrintWordsFromVec(vector <string> vWords)
{
	cout << "\nTolkens: " << vWords.size() << endl;
	for (string i : vWords)
		cout << "- " << i << endl;
}

string JoinFunc(vector<string> vWords)
{
	string Sent1 = "";
	for (string s : vWords)
		Sent1 += s + " ";

	return Sent1;
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	vector <string > vWords = SplitString(Sent1, " ");
	cout << "Spilit sentence: "; PrintWordsFromVec(vWords);
	cout << "Join sentence: " << JoinFunc(vWords);

	return 0;
}
