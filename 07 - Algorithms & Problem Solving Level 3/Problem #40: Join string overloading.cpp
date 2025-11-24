#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector <string> vWords, string delim)
{
	
	string sent = "";
	for (short i = 0 ; i < vWords.size();i++)
	      sent = sent + vWords[i] + delim;


	return (sent.substr(0,sent.length()-delim.length()));
}


string JoinString(string arrWords[],short Length ,string delim)
{

	string sent = "";
	for (short i = 0; i < Length; i++)
		sent = sent + arrWords[i] + delim;


	return (sent.substr(0, sent.length() - delim.length()));
}


int main()
{
	string arrWords[] = {"Jawaher","math","Physics","Space"};
	cout << JoinString(arrWords, 4,"\n");

	system("pause>0");
	return 0;
}
