#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;




short  CountEachWordInAstring(string Sent1)
{
	string Word, delim = " "; short pos = 0 ,Counter = 0;

	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		Word = Sent1.substr(0, pos);
		if (Word != "")
		{
			Counter++;
		}
		Sent1.erase(0, pos + delim.length());
	}


	if (Sent1 != " ")
		Counter++;

	return Counter;
}




int main()
{
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "-The number of words in your sentence is: " << CountEachWordInAstring(Sent1) ;
	

	system("pause>0");
	return 0;
}
