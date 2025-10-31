#include <iostream>
#include <string>
using namespace std;




string ReadUsersString(string Message)
{
	string Sent;
	cout << Message;
	getline(cin,Sent);
	return Sent;
}

char InvertLetterCase(char Letter)
{
	return isupper(Letter) ? tolower(Letter) : toupper(Letter);
}

short LetterCount(string Sent1 , char Letter)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (Sent1[i] == Letter)
			Counter++;
	}


	return Counter;
}

short LetterCountIgnoreCase(string Sent1, char Letter , bool MatchCase = true)
{
	short Counter = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (MatchCase)
		{
			if (Sent1[i] == Letter)
				Counter++;
		}

		else
		{
			if (tolower(Sent1[i]) == tolower(Letter))
				Counter++;
		}
	}


	return Counter;
}


int main()
{
	string Sent1 = ReadUsersString("Enter your sentense: ");
	char Letter ;
	cout << "Enter a letter to count: ";
	cin >> Letter;
	
	cout << "\n\nLetter \' " << Letter << "\' Count = " << LetterCount(Sent1, Letter);
	cout << "\nCount " << Letter << " or " << InvertLetterCase(Letter) << " : " << LetterCountIgnoreCase(Sent1, Letter, false);
	


	system("pause>0");
	return 0;
}
