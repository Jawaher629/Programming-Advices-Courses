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



int main()
{
	string Sent1 = ReadUsersString("Enter your sentense to invert: ");
	char Letter ;
	cout << "Enter a letter to count: ";
	cin >> Letter;

	cout << "Letter Count: " << LetterCount(Sent1, Letter);
	

	system("pause>0");
	return 0;
}
