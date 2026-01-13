//My Solution

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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
	string Sent = ReadUserString();
	cout << RemovePuncuations(Sent);



	system("pause>0");
	return 0;
}



