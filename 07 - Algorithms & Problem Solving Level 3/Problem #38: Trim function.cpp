#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

string TrimLeft(string Sent1)
{
	for (short i = 0; i < Sent1.length(); i++)
	{
		if (Sent1[i] != ' ')
			return Sent1.substr(i, Sent1.length() - i);
	}
	return "";
}


string TrimRight(string S1) 
{ for (short i = S1.length() - 1; i >= 0; i--)
   { 
	if (S1[i] != ' ')
   { 
	return S1.substr(0, i + 1);
   } 
  }
return""; 
}


string TrimFunc(string sent1)
{
	return TrimLeft(TrimRight(sent1));
}


int main()
{
	string sent1 = "        Jawaher Alshaikh The best Programmer Ever         .";

	cout << "Original sentence: " << sent1 << endl;
	cout << "Trim left: " << TrimLeft(sent1) << endl ;
	cout << "Trim right: " << TrimRight(sent1) << endl;
	cout << "Trim: " << TrimFunc(sent1);

	system("pause>0");
	return 0;
}
