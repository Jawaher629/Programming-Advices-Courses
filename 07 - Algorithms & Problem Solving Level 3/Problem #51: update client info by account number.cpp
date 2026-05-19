#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
const string ClientsFileName = "ClientsFile.txt";

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string PhoneNumber = "";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
};

vector <string> SplitString(string Sent1, string delim)
{
	vector <string> vWords;
	short pos = 0;
	string sWord;
	while ((pos = Sent1.find(delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
			vWords.push_back(sWord);
		Sent1.erase(0, pos + delim.length());
	}
	if (Sent1 != "")
		vWords.push_back(Sent1);
	return vWords;
}

stClientData ConvertLineToRecord(string Line, string Separator)
{
	stClientData strClientData;
	vector <string> vClientData = SplitString(Line, Separator);

	strClientData.AccountNumber = vClientData[0];
	strClientData.PinCode = vClientData[1];
	strClientData.ClientName = vClientData[2];
	strClientData.PhoneNumber = vClientData[3];
	strClientData.AccountBalance = stod(vClientData[4]);

	return strClientData;
}

string ConvertRecordToLine(stClientData stClientData, string Separator)
{
	string ClientDataLine = "";

	ClientDataLine += stClientData.AccountNumber + Separator + stClientData.PinCode + Separator + stClientData.ClientName + Separator + stClientData.PhoneNumber + Separator + to_string(stClientData.AccountBalance);

	return ClientDataLine;
}

vector <stClientData> LoadClientInfoFromFile(string FileName)
{
	vector <stClientData> vClientInfo;
	fstream fClientsFile;

	fClientsFile.open(FileName, ios::in);
	if (fClientsFile.is_open())
	{
		string line;
		stClientData stClient;

		while (getline(fClientsFile, line))
		{
			stClient = ConvertLineToRecord(line, "#//#");
			vClientInfo.push_back(stClient);
		}
		fClientsFile.close();
	}

	return vClientInfo;
}

void PrintClientRecord(stClientData ClientData)
{
	cout << "\nClient's Name  : " << ClientData.ClientName;
	cout << "\nAccount Number : " << ClientData.AccountNumber;
	cout << "\nPin Code       : " << ClientData.PinCode;
	cout << "\nPhone Number   : " << ClientData.PhoneNumber;
	cout << "\nAccount Balance: " << ClientData.AccountBalance;

}

string ReadAccountNumber()
{
	string AccountNum = "";
	cout << "Enter Account Number: ";
	cin >> AccountNum;
	return AccountNum;
}

bool IsAccountNumberFound(string Accountnum, stClientData& stClient, vector <stClientData>& vClients)
{
	for (stClientData& Cl : vClients)
	{
		if (Cl.AccountNumber == Accountnum)
		{
			stClient = Cl;
			return true;
		}
	}

	return false;

}

stClientData UpdateClientData(string AccountNumber)
{
	stClientData ClientData;
	ClientData.AccountNumber = AccountNumber;;
	cout << "Enter Pin code: ";
	getline(cin >> ws , ClientData.PinCode);
	cout << "Enter Client's Name: ";
	getline(cin, ClientData.ClientName);
	cout << "Enter Phone Number: ";
	getline(cin, ClientData.PhoneNumber);
	cout << "Enter Account Balance: ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}


vector <stClientData> SaveClientDataToFile(string FileName, vector <stClientData> vClientsData)
{
	string DataLine = "";
	fstream fClientsDataFile;

	fClientsDataFile.open(FileName, ios::out);
	if (fClientsDataFile.is_open())
	{
		for (stClientData Cl : vClientsData)
		{
			if (Cl.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(Cl, "#//#");
				fClientsDataFile << DataLine << endl;
			}
		}

		fClientsDataFile.close();
	}
	return vClientsData;
}

bool UpdateClientDataByAccountNumber(string Accountnum, vector <stClientData>& vClient)
{
	stClientData stClient;
	char Answer = 'N';

	if(IsAccountNumberFound(Accountnum, stClient, vClient))
	{
		PrintClientRecord(stClient);
		cout << endl << "\nAre you sure you want to update this account information? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			for (stClientData& Cl : vClient)
			{
				if (Cl.AccountNumber == Accountnum)
				{
					Cl = UpdateClientData(Accountnum);
					break;
				}
			}

			SaveClientDataToFile(ClientsFileName, vClient);
			cout << "Account Updated Successfully.\n";
			return true;
		}
	}
	else 
	{
		cout << "\nClient with Account Number (" << Accountnum << ") Was Not Found!";
		return false;
	}
}

int main()
{
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	UpdateClientDataByAccountNumber(AccountNumber, vClients);


	system("pause>0");
	return 0;
}
