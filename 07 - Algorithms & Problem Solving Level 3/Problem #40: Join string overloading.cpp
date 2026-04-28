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


string JoinFunc(vector<string> vWords,string Separator)
{
	string Sent1 = "";
	for (string s : vWords)
		Sent1 += s + Separator;

	return  Sent1.substr(0, Sent1.length() - Separator.length());
}
string JoinFunc(string arr1[],int Length, string Separator)
{
	string Sent1 = "";
	for(int i = 0 ; i < Length ; i++)
		Sent1 += arr1[i] + Separator;

	return  Sent1.substr(0, Sent1.length() - Separator.length());
}

int main()
{
	string arr1[] = {"Layla","Omer","Maha","Ahmed"};
	vector <string > vWords = { "Math","Physics","Science","Programming" };;
	cout << "Join sentence by vector: " << JoinFunc(vWords,"##")<<endl;
	cout << "\nJoin sentence by array: " << JoinFunc(arr1,4, "##")<<endl;


	return 0;
}
