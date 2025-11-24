// My solution:
#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

string Reverse_Words(const string& str) 
{
	vector <string> words;
	string word = "";

	for (char character : str)
	{
		if (character != ' ')
			word += character;
		else
		{
			words.push_back(word);
			word = "";
		}
	}
	words.push_back(word);

	string result = "";
	for (int i = words.size() - 1; i >= 0; --i)
	{
		result += words.at(i);
		if (i != 0)
			result += " ";
	}
	return result;
}


int main()
{
	
	string sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "the reveresd sentence is: " << Reverse_Words(sent1);

	system("pause>0");
	return 0;
}

//Dr.Abu Hadhoud solution:
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

string ReverseWords(string sent1)
{
	vector <string> vString = SplitString(sent1, " ");
	string sent2 = "";

	vector <string> ::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;
		sent2 += *iter + " ";
	}

	sent2 = sent2.substr(0,sent2.length() - 1);

	return sent2;
}


int main()
{
	
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "Sentence after reversing: " << ReverseWords(Sent1);

	system("pause>0");
	return 0;
}
