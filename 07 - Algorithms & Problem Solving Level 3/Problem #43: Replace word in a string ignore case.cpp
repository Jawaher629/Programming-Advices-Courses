#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

vector <string> SplitString(string Sent1, string delim)
{
	vector <string> vWords;
	string Word; short pos = 0;

	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		Word = Sent1.substr(0, pos);
		if (Word != "")
		{
			vWords.push_back(Word);
		}
		Sent1.erase(0, pos + delim.length());
	}


	if (Sent1 != " ")
		vWords.push_back(Sent1);

	return vWords;
}


string JoinString(vector <string> vWords, string delim)
{

	string sent = "";
	for (short i = 0; i < vWords.size(); i++)
		sent = sent + vWords[i] + delim;


	return (sent.substr(0, sent.length() - delim.length()));
}

string LowerAllString(string Sent)
{
	for (short i = 0; i < Sent.length(); i++)
	{
		Sent = tolower(Sent[i]);
	}
	return Sent;
}


string ReplaceWordInStringIgnoreCase(string Sent1, string ToBeReplaced, string TheReplcement, bool MatchCase = true)
{

	vector <string>vSentence1 = SplitString(Sent1, " ");
	for (string& str : vSentence1)
	{
		if (MatchCase)
		{
			if (str == ToBeReplaced)
				str = TheReplcement;
		}
		else
			if (LowerAllString(str) == LowerAllString(ToBeReplaced))
				str = TheReplcement;
	}
		
	return JoinString(vSentence1, " ");

}
int main()
{
	
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << ReplaceWordInStringIgnoreCase(Sent1, "Jordan","USA",false);
	
	system("pause>0");
	return 0;
}
