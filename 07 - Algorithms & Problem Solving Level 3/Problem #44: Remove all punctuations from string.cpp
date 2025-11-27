#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;


string RenameAllPuncuations(string Sent1)
{
	string Sent2 = "";
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (!ispunct(Sent1[i]))
			Sent2 += Sent1[i];
	}
	return Sent2;
}
int main()
{
	
	string Sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "Original String:\n" << Sent1;
	cout << "\n\nPauncuations Removed:\n" << RenameAllPuncuations(Sent1);

	system("pause>0");
	return 0;
}
