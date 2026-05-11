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

	strClientData.AccountNumber += vClientData[0];
	strClientData.PinCode += vClientData[1];
	strClientData.ClientName += vClientData[2];
	strClientData.PhoneNumber += vClientData[3];
	strClientData.AccountBalance += stod(vClientData[4]);

	return strClientData;
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

void PrintClientRecord(stClientData stClient)
{
	cout << "| " << setw(15) << stClient.AccountNumber;
	cout << "| " << setw(10) << stClient.PinCode;
	cout << "| " << setw(40) << stClient.ClientName;
	cout << "| " << setw(12) << stClient.PhoneNumber;
	cout << "| " << setw(12) << stClient.AccountBalance;
}

void PrintAllClientsInfo(vector <stClientData> vClientsInfo)
{
	cout << "\n\t\t\t\t\t Clients List (" << vClientsInfo.size() << ") Client(s).\n" << endl;
	cout << "\n_________________________________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client's Name";
	cout << "| " << left << setw(12) << "Phone Number";
	cout << "| " << left << setw(12) << "Account Balance" << endl;
	cout << "\n_________________________________________________________________________________________________________________\n";

	for (stClientData stClient : vClientsInfo)
	{
		PrintClientRecord(stClient);
		cout << endl;
	}
	cout << "\n_________________________________________________________________________________________________________________\n";
}

int main()
{
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	PrintAllClientsInfo(vClients);

	system("pause>0");
	return 0; 
}
