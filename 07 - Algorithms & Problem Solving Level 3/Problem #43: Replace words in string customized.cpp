// My Solution:
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

string ReplaceWordInString(string Sent1, string TheReplace, string TheReplacement)
{
	vector <string>vSentence = SplitString(Sent1, " ");
	string NewSent = "";
	for (string s : vSentence)
	{
		if (s == TheReplace)
			s = TheReplacement;
		NewSent += s + " ";
		
	}
	return NewSent;
}


int main()
{
	string Sentence1 = ReadStringFromUser("Enter your sentence : "),TheReplace,TheReplacement;
	cout << "Enter the word to replace: ";
	cin >> TheReplace;
	cout << "Enter the word the replacement: ";
	cin >> TheReplacement;
	cout << "New sentence is: " << ReplaceWordInString(Sentence1, TheReplace, TheReplacement);

	return 0; 
}

//Dr.Abu-Hadhoud solution:
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
					st = StringToRplace;
			}
	}
	return JoinString(vSentence, " ");
}

int main()
{
	string Sentence1 = ReadUserString("Enter your sentence: ");
	string StringToReplace = ReadUserString("Enter string to replace: ");
	string TheReplacement = ReadUserString("Enter the replacement string: ");

	cout << ReplaceAWordInASentence(Sentence1, StringToReplace, TheReplacement, false);
	
	system("pause>0");
	return 0;
}




