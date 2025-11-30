#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClientData
{
	string ClientAccountNum = "";
	string ClientPinCode = "";
	string ClientName = "";
	string ClientPhoneNumber = "";
	double AccBalance = 0;

};

vector <string> SplitString(string Sent1, string delim)
{
	vector <string> vWords;
	string Word; short pos = 0;

	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		Word = Sent1.substr(0, pos);
		if (Word != "")
		{
			vWords.push_back(Word);
		}
		Sent1.erase(0, pos + delim.length());
	}


	if (Sent1 != " ")
		vWords.push_back(Sent1);

	return vWords;
}


stClientData ConvertLineDataToStruct(string Line, string delim)
{
	stClientData ClientData;
	vector <string> vGetGataLine = SplitString(Line,delim);

	ClientData.ClientAccountNum = vGetGataLine[0];
	ClientData.ClientPinCode = vGetGataLine[1];
	ClientData.ClientName = vGetGataLine[2];
	ClientData.ClientPhoneNumber = vGetGataLine[3];
	ClientData.AccBalance = stod(vGetGataLine[4]);

	return ClientData;
}

void PrintRecordData(stClientData Client)
{
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "Account number :" << Client.ClientAccountNum << "\n";
	cout << "Client name    :" << Client.ClientName << "\n";
	cout << "Pin code       :" << Client.ClientPinCode << "\n";
	cout << "Phone number   :" << Client.ClientPhoneNumber << "\n";
	cout << "Account balance:" << Client.AccBalance << "\n";
}


int main()
{
	string Line = "A150#//#1234#//#Jawaher Alshaikh#//#077776#//#5270.000000";
	stClientData Client = ConvertLineDataToStruct(Line, "#//#");
	PrintRecordData(Client);

	
	system("pause>0");
	return 0;
}
