#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadStringFromUser(string Message)
{
	cout << Message;
	string Sent = "";
	getline(cin, Sent);
	return Sent;
}

static string TrimLeft(string Sent1)
{
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (Sent1[i] != ' ')
		{
			return Sent1.substr(i, Sent1.length() - i);
		}
	}
	return "";
}

static string TrimRight(string Sent1)
{
	for (int i = Sent1.length() - 1; i >= 0; i--)
	{
		if (Sent1[i] != ' ')
		{
			return Sent1.substr(0, i + 1);
		}
	}
	return "";

}

string TrimFiunc(string Sent1)
{
	return TrimRight(TrimLeft(Sent1));
}

int main()
{
	string Sent1 = ReadStringFromUser("Enter your sentence: ");
	cout << "\nTrim Left: "<< TrimLeft(Sent1);
	cout << "\nTrim Right: "<< TrimRight(Sent1);
	cout << "\nTrim Function:" << TrimFiunc(Sent1);

	return 0;
}
