#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadUserString()
{
	string Sentence = "";
	cout << "Enter Your Sentence: ";
	getline(cin, Sentence);

	return Sentence;
}


vector <string> SplitString(string Sent1, string Delim)
{
	vector <string> vSentence;

	string sWord = "";
	short Pos = 0;

	while ((Pos = Sent1.find(Delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, Pos);
		if (sWord != "")
		{
			vSentence.push_back(sWord);
		}
		Sent1.erase(0,Pos + Delim.length());
	}

	if (Sent1 != "")
	{
		vSentence.push_back(Sent1);
	}

	return vSentence;
}


string ReverseWordsInAString(string Sent1)
{
	vector<string> vString ;
	vString = SplitString(Sent1, " ");
	string Sent2 = "";

	vector<string>::iterator iter = vString.end();
	while (iter != vString.begin())
	{
		--iter;
		Sent2 += *iter + " ";
	}
	Sent2 = Sent2.substr(0, Sent2.length() - 1);

	return Sent2;
}

int main()
{
	string Sentence1 = ReadUserString();
	cout << "\nYour string after reverse:\n";
	cout << ReverseWordsInAString(Sentence1);

	system("pause>0");
	return 0;
}
