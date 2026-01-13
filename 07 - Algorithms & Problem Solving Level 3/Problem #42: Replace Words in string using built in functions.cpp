#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadUserString()
{
	string Sentence = "";
	cout << "Enter Your Sentence: ";
	getline(cin, Sentence);

	return Sentence;
}


string ReplaceWordsInAString(string Sent1, string ToReplace, string TheReplacement)
{
	short pos = Sent1.find(ToReplace);

	while(pos != std::string::npos)
	{
		Sent1 = Sent1.replace(pos, ToReplace.length(), TheReplacement);

		pos = Sent1.find(ToReplace);
	}

	return Sent1;
}

int main()
{
	
	string Sentence1 = ReadUserString();

	cout << "Enter word to be replaced: ";
	string ToReplace = "";
	cin >> ToReplace;

	cout << "Enter the replacement word: ";
	string TheReplacement = "";
	cin >> TheReplacement;

	cout << ReplaceWordsInAString(Sentence1, ToReplace, TheReplacement);
	

	system("pause>0");
	return 0;
}



