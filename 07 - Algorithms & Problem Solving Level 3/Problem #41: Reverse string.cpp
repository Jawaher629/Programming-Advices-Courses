// My solution:
#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

string Reverse_Words(const string& str) 
{
	vector <string> words;
	string word = "";

	for (char character : str)
	{
		if (character != ' ')
			word += character;
		else
		{
			words.push_back(word);
			word = "";
		}
	}
	words.push_back(word);

	string result = "";
	for (int i = words.size() - 1; i >= 0; --i)
	{
		result += words.at(i);
		if (i != 0)
			result += " ";
	}
	return result;
}


int main()
{
	
	string sent1 = My_Input_Lib::ReadUsersString("Enter your sentence: ");
	cout << "the reveresd sentence is: " << Reverse_Words(sent1);

	system("pause>0");
	return 0;
}

//Dr.Abu Hadhoud solution:
