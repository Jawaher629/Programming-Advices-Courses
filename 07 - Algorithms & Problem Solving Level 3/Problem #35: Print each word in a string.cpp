#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;




void  PrintEachWordInAstring(string Sent1)
{
	string Word, delim = " "; short pos = 0;

	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		Word = Sent1.substr(0, pos);
		if (Word != "")
		{
			cout << Word << endl;
		}
		Sent1.erase(0, pos + delim.length());
	}


	if (Sent1 != " ")
		cout << Sent1 << endl;
}




int main()
{
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "- Your sentence words are: \n" ;
	PrintEachWordInAstring(Sent1);
	

	system("pause>0");
	return 0;
}
