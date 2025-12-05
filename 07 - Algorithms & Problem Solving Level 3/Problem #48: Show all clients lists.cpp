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

stClientData ConvertLineDataToStruct(string Line, string delim)
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
			Client = ConvertLineDataToStruct(SingleLine,"#//#");
			vClients.push_back(Client);
		}
		ClientsDataFile.close();
	}

	return vClients;
}

void PrintOneClientData(stClientData Client)
{
	cout << "|" << setw(40) << left << Client.ClientName;
	cout << "|" << setw(15) << left << Client.ClientAccountNum;
	cout << "|" << setw(10) << left << Client.ClientPinCode;
	cout << "|" << setw(12) << left << Client.ClientPhoneNumber;
	cout << "|" << setw(12) << left << Client.AccBalance;
}

void PrintAllClients(vector <stClientData> Client)
{
	cout << "\n\t\t\t\t\t\t List of (" << Client.size() << ") Clients(s)\n";

	cout << "--------------------------------------------------------------------------------------------------\n";

	cout << "|" << setw(40) << left << "Client Name";
	cout << "|" << setw(15) << left << "Account Number";
	cout << "|" << setw(10) << left << "Pin Code";
	cout << "|" << setw(12) << left << "Phone Number";
	cout << "|" << setw(12) << left <<"Account Balance";

	cout << "\n--------------------------------------------------------------------------------------------------\n";

	for (stClientData Clients : Client)
	{
		PrintOneClientData(Clients);
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------------------------------\n";

}


int main()
{
	vector <stClientData> vClients = LoadClientDataFromFile(ClientsFileName);
	PrintAllClients(vClients);

	system("pause>0");
	return 0;
}
