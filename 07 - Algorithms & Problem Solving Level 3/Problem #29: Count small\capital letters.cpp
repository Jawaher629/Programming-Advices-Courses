#include <iostream>
#include <string>
using namespace std;


string ReadStringFromUser(string Message)
{
	string Sent = "";
	cout << Message;
	getline(cin, Sent);
	return Sent;
}


short CountCapitalLetters(string Sent1)
{
	short CapitalL = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (isupper(Sent1[i]))
		    CapitalL++;
	}
	return CapitalL;
}

short CountSmallLetters(string Sent1)
{
	short SmallL = 0;
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (islower(Sent1[i]))
		SmallL++;
	}
	return SmallL;
}


int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	
	cout << "\nSentence length: " << Sent1.length();
	cout << "\nCapital letters count: " << CountCapitalLetters(Sent1);
	cout << "\nSmall letters count: " << CountSmallLetters(Sent1);

	return 0;
}


//Different way

#include <iostream>
#include <string>
using namespace std;

enum enWhatToCount { SmallLetters = 0, CaoitalLetters = 1, All = 2 };


string ReadStringFromUser(string Message)
{
	string Sent = "";
	cout << Message;
	getline(cin, Sent);
	return Sent;
}

short CountLetters(string Sent1, enWhatToCount WhatToCount = enWhatToCount::All)
{
	short Counter = 0;
	if (WhatToCount == enWhatToCount::All)
		return Sent1.length();

	for (short i = 0; i < Sent1.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CaoitalLetters && isupper(Sent1[i]))
			Counter++;
		if (WhatToCount == enWhatToCount::SmallLetters && islower(Sent1[i]))
			Counter++;
	}
	return Counter;
}


int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	
	cout << "\nSentence length: " << CountLetters(Sent1);
	cout << "\nCapital letters count: " << CountLetters(Sent1,enWhatToCount::CaoitalLetters);
	cout << "\nSmall letters count: " << CountLetters(Sent1,enWhatToCount::SmallLetters);

	return 0;
}
