// My solution: 
#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;

string IsVowelLetter(char Letter)
{
	return Letter == 'a' || Letter == 'i' || Letter == 'o' || Letter == 'u' || Letter == 'e' || Letter == 'A' || Letter == 'I' || Letter == 'O' || Letter == 'E' || Letter == 'U' ? "It is a vowel letter" : "It is Not vowel letter";
}


int main()
{

	char char1 = My_Input_Lib::ReadChar(); 

	cout << IsVowelLetter(char1);

	system("pause>0");
	return 0;
}

// Mr.Abo Hadhoud solution:
#include <iostream>
#include <string>
#include "My_Input_Lib.h"
using namespace std;


bool IsVowelLetter(char Letter)
{
	Letter = tolower(Letter);
	return Letter == 'a' || Letter == 'i' || Letter == 'o' || Letter == 'u' || Letter == 'e';
}


int main()
{

	char char1 = My_Input_Lib::ReadChar(); 

	if(IsVowelLetter(char1))
	{
		cout << "Letter '" << char1 << "' is a vowel!\n";
	}
	else
	{
		cout << "Letter '" << char1 << "' is NOT a vowel!\n";
	}

	system("pause>0");
	return 0;
}
