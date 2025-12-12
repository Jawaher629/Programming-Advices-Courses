//Solution1:
#include <iostream>
#include <string>
using namespace std;

string ReadUserString()
{
	string Sentence = "";
	cout << "Enter Your Sentence: ";
	cin >> Sentence;

	return Sentence;
}

bool IsPunc(char Ch)
{
	return ((Ch == '.') || (Ch == ',') || (Ch == ';') || (Ch == ':') || (Ch == '!') || (Ch == '?'));
}

string RemovePuncuations(string Sent1)
{
	string Sent2 = "";
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (!IsPunc(Sent1[i]))
		{
			Sent2 += Sent1[i];

		}
	}
	return Sent2;
}

int main()
{
	string Sent = "Here is the fucking SA, It's such a shitty countre. ma god help us to get out of here!!!";
	cout << RemovePuncuations(Sent);

	system("pause>0");
	return 0;
}





// Solution2:
string RemoveAllPuncuations(string Sent1)
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
	cout << "\n\nPauncuations Removed:\n" << RemoveAllPuncuations(Sent1);

	
	system("pause>0");
	return 0;
}
