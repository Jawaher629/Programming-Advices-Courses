#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ClientsDataFile2.txt";
struct stClientData
{
	string ClientAccountNum = "";
	string ClientPinCode = "";
	string ClientName = "";
	string ClientPhoneNumber = "";
	double AccBalance = 0;
	bool MarkForDelet = false;
};

string ReadClientAcciuntNumber()
{
	string AccountNum;
	cout << "Enter Account Number: ";
	cin >> AccountNum;
	return AccountNum;
}

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

string ConvertRecordToLine(stClientData ClientRecord, string delim)
{
	string ClientDataLine = "";

	ClientDataLine += ClientRecord.ClientAccountNum + delim;
	ClientDataLine += ClientRecord.ClientPinCode + delim;
	ClientDataLine += ClientRecord.ClientName + delim;
	ClientDataLine += ClientRecord.ClientPhoneNumber + delim;
	ClientDataLine += to_string(ClientRecord.AccBalance) + delim;

	return ClientDataLine;
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
			Client = ConvertLineDataToStruct(SingleLine, "///");
			vClients.push_back(Client);
		}
		ClientsDataFile.close();
	}

	return vClients;
}

void PrintClientCard(stClientData Client)
{
	cout << "- Account Number: " << Client.ClientAccountNum << endl;
	cout << "- Pin Code: " << Client.ClientPinCode << endl;
	cout << "- Name: " << Client.ClientName << endl;
	cout << "- Phone Number: " << Client.ClientPhoneNumber << endl;
	cout << "- Balance: " << Client.AccBalance << endl;
}

bool FindClientDataByAccNum(string AccountNumber, vector <stClientData> vClients ,stClientData& Client)
{
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

bool MarkClientForDeleteByAccNum(string AccountNumber, vector <stClientData> vClients)
{
	for (stClientData& Cl : vClients)
	{
		if (Cl.ClientAccountNum == AccountNumber)
		{
			Cl.MarkForDelet = true;
			return true;
		}
	}
	return false;
}

vector <stClientData> SaveDataLineToFile(string FileName, vector <stClientData> vClients)
{
	string DataLine;
	fstream ClientsDataFile;
	ClientsDataFile.open(FileName, ios::out);
	if (ClientsDataFile.is_open())
	{
		for (stClientData Cl : vClients)
		{
			if (Cl.MarkForDelet == false)
			{
				DataLine = ConvertRecordToLine(Cl,"///");
				ClientsDataFile << DataLine << endl;
			}
		}
		ClientsDataFile.close();
	}
	return vClients;
}

bool DeleteClientDataByAccountNum(string Accountnum, vector <stClientData> vClients)
{
	stClientData ClientData; char Confermation = 'N';
	
	if (FindClientDataByAccNum(Accountnum, vClients, ClientData))
	{
		PrintClientCard(ClientData);
		cout << "\n Are you sure to delete this client data? Y / N? ";
		cin >> Confermation;
		if (toupper(Confermation) == 'Y')
		{
			MarkClientForDeleteByAccNum(Accountnum, vClients);
			SaveDataLineToFile(ClientsFileName, vClients);

			vClients = LoadClientDataFromFile(ClientsFileName);
			cout << "\n\nClient data deleted Successfully!\n";
			return true;
		}
	}
	else
	{
		cout << "Client with (" << Accountnum << ") account number is NOT found!\n\n";
		return false;
	}
}

int main()
{
	vector <stClientData> vClients = LoadClientDataFromFile(ClientsFileName);
	string AccountNum = ReadClientAcciuntNumber();
	DeleteClientDataByAccountNum(AccountNum, vClients);
	system("pause>0");
	return 0;
}
