#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;




bool IsVowelLetter(char Letter)
{
	Letter = tolower(Letter);
	return Letter == 'a' || Letter == 'i' || Letter == 'o' || Letter == 'u' || Letter == 'e';
}


string  PrintVowelsInAstring(string Sent1)
{
	string Vowels = "";
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (IsVowelLetter(Sent1.at(i)))
			Vowels = Vowels + Sent1[i] + " ";
	}
	return Vowels;
}




int main()
{

	cout << "- Vowels in the sentence: " << PrintVowelsInAstring(My_Input_Lib::ReadUsersString("Enter your sentence: "));
	

	system("pause>0");
	return 0;
}
