#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ClientsDataFile.txt";
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

stClientData ConvertLineDataToStruct(string Line, string delim )
{
	stClientData ClientData;
	vector <string> vGetGataLine = SplitString(Line, delim);

	ClientData.ClientAccountNum = vGetGataLine[0];
	ClientData.ClientPinCode = vGetGataLine[1];
	ClientData.ClientName = vGetGataLine[2];
	ClientData.ClientPhoneNumber = vGetGataLine[3];
	ClientData.AccBalance = stod(vGetGataLine[4]);

	return ClientData;
}

vector <stClientData> LoadClientDataFromFile(string FileName)
{
	vector <stClientData> vClients;
	fstream ClientsDataFile;

	ClientsDataFile.open(FileName, ios::in);
	if (ClientsDataFile.is_open())
	{
		string SingleLine = "";
		stClientData Client;
		while (getline(ClientsDataFile, SingleLine))
		{
			Client = ConvertLineDataToStruct(SingleLine, "#//#");
			vClients.push_back(Client);
		}
		ClientsDataFile.close();
	}

	return vClients;
}

string ReadClientAcciuntNumber()
{
	string AccountNum;
	cout << "Enter Account Number: ";
	cin >> AccountNum;
	return AccountNum;
}

bool FindClientDataByAccNum(string AccountNumber, stClientData& Client)
{
	vector <stClientData> vClients = LoadClientDataFromFile(ClientsFileName);
	for (stClientData Cl : vClients)
	{
		if (Cl.ClientAccountNum == AccountNumber)
		{
			Client = Cl;
			return true;
		}
	} 
	return false;

}

void PrintClientCard(stClientData Client)
{
	cout << "- Account Number: " << Client.ClientAccountNum << endl;
	cout << "- Pin Code: " << Client.ClientPinCode << endl;
	cout << "- Name: " << Client.ClientName << endl;
	cout << "- Phone Number: " << Client.ClientPhoneNumber << endl;
	cout << "- Balance: " << Client.AccBalance << endl;
}

int main()
{
	string AccountNum = ReadClientAcciuntNumber();
	stClientData Client;

	if (FindClientDataByAccNum(AccountNum, Client))
	{
		PrintClientCard(Client);
	}
	else
		cout << "\nClient with Account Number(" << AccountNum << ") is Not Found!";
	system("pause>0");
	return 0;
}
