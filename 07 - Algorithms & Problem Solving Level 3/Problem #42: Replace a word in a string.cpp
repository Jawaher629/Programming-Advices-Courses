//My solution: 
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



void ReplaceWordInString(string Sent1 , string ToBeReplaced, string TheReplcement)
{
	vector <string> vSent2 = SplitString(Sent1, " ");
	for (string words : vSent2)
	{
		if (words == ToBeReplaced)
			words = TheReplcement;

		cout << words << " ";

	}
}

int main()
{
	
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	ReplaceWordInString(Sent1, "Jordan","USA");


	system("pause>0");
	return 0;
}


//Dr.Abu Hadhoud solution:
#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

string ReplaceWordInStringBuiltInFunction(string Sent1 , string ToBeReplaced, string TheReplcement)
{
	short Pos = Sent1.find(ToBeReplaced);
	while (Pos != std::string::npos)
	{
		Sent1 = Sent1.replace(Pos, ToBeReplaced.length(), TheReplcement);
		Pos = Sent1.find(ToBeReplaced);

	}
	return Sent1;
}

int main()
{
	
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << ReplaceWordInStringBuiltInFunction(Sent1, "Jordan","USA");

	system("pause>0");
	return 0;
}
