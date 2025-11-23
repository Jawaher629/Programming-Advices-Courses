// My Solution:
#include <iostream>
#include <string>
#include <vector>

string JoinString(vector <string> vWords, string delim)
{
	
	string sent = "";
	for (short i = 0 ; i < vWords.size();i++)
	      sent = sent + vWords[i] + delim;


	return (sent.substr(0,sent.length()-delim.length()));
}


int main()
{
	vector <string> vWords = {"Jawaher","math","Physics"};
	cout << JoinString(vWords, "\n");

	system("pause>0");
	return 0;
}
