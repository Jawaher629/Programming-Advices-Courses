#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadUserString(string Messege)
{
	string Sentence = "";
	cout << Messege;
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

string UpperCaseAllString(string Sentence1)
{
	for (short i = 0; i < Sentence1.length(); i++)
	{
		Sentence1[i] = toupper(Sentence1[i]);
	}
	return Sentence1;
}

string LowerCaseAllString(string Sentence1)
{
	for (short i = 0; i < Sentence1.length(); i++)
	{
		Sentence1[i] = tolower(Sentence1[i]);
	}
	return Sentence1;
}

string JoinString(vector <string> vWords, string Delim)
{
	string Sent1 = "";
	for (string& s : vWords)
	{
		Sent1 += s + Delim;
	}
	return Sent1.substr(0, Sent1.length() - Delim.length());
	
}

string ReplaceAWordInASentence(string Sent1, string StringToRplace, string TheReplacement, bool Matchcase = true)
{
	vector <string> vSentence = SplitString(Sent1, " ");
	for (string& st : vSentence)
	{
		if (st == StringToRplace)
			if (Matchcase)
			{
				st = TheReplacement;

			}
			else
			{
				if (LowerCaseAllString(st) == LowerCaseAllString(StringToRplace))
					st == StringToRplace;
			}
	}
	return JoinString(vSentence, " ");
}




int main()
{
	string Sentence1 = ReadUserString("Enter your sentence: ");
	string StringToReplace = ReadUserString("Enter string to replace: ");
	string TheReplacement = ReadUserString("Enter the replacement string: ");

	cout << ReplaceAWordInASentence(Sentence1, StringToReplace, TheReplacement);
	
	system("pause>0");
	return 0;
}




