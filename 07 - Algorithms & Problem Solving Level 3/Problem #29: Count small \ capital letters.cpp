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


short CountCapitalLetter(string Sent)
{
	short Counter = 0;
	for (short i = 0; i < Sent.length(); i++)
	{
		if (isupper(Sent[i]))
		{
			Counter++;
		}
	}
	return Counter;
}


short CountSmalllLetter(string Sent)
{
	short Counter = 0;
	for (short i = 0; i < Sent.length(); i++)
	{
		if (islower(Sent[i]))
		{
			Counter++;
		}
	}
	return Counter;
}



int main()
{
	string Sent1 = ReadUsersString("Enter your sentense to invert: ");
	cout << "Sentence's letters count: " << Sent1.length() << endl;
	cout << "Capital letters count: " << CountCapitalLetter(Sent1) << endl;
	cout << "Small letters count: " << CountSmalllLetter(Sent1) << endl;


	system("pause>0");
	return 0;
}
