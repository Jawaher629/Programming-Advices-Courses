#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;




bool IsVowelLetter(char Letter)
{
	Letter = tolower(Letter);
	return Letter == 'a' || Letter == 'i' || Letter == 'o' || Letter == 'u' || Letter == 'e';
}


short CountVowelsInAstring(string Sent1)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (IsVowelLetter(Sent1.at(i)))
			Counter++;
	}
	return Counter;
}




int main()
{

	cout << "Sentence has " << CountVowelsInAstring(My_Input_Lib::ReadUsersString("Enter your sentence: ")) << " vowels.";
	

	system("pause>0");
	return 0;
}
