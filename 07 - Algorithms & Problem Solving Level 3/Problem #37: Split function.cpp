#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;


vector <string> SplitString(string Sent1 ,string delim )
{
	vector <string> vWords;
	string Word; short pos = 0 ;

	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		Word = Sent1.substr(0, pos);
		if (Word != "")
		{
				vWords.push_back(Word) ;
		}
		Sent1.erase(0, pos + delim.length());
	}


	if (Sent1 != " ")
		vWords.push_back(Sent1);

	return vWords;
}


int main()
{
	vector <string> vWords;
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	vWords = SplitString(Sent1, " ");
	cout << "- Token: " << vWords.size() << "\n";
	cout << "- Words: \n";
	for (string &word : vWords)
	{
		cout << word << endl;
	}
	system("pause>0");
	return 0;
}
