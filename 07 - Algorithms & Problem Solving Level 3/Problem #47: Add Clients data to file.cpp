//My Solution:
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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

stClientData ReadClientData()
{
	stClientData ClientData;
	cout << "Enter Account Number: ";
	getline(cin >> ws, ClientData.AccountNumber);
	cout << "Enter Pin code: ";
	getline(cin, ClientData.PinCode);
	cout << "Enter Client's Name: ";
	getline(cin, ClientData.ClientName);
	cout << "Enter Phone Nimber: ";
	getline(cin, ClientData.PhoneNumber);
	cout << "Enter Account Balance: ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

string ConvertRecordToLine(stClientData stClientData, string Separator)
{
	string ClientDataLine = "";

	ClientDataLine += stClientData.AccountNumber + Separator + stClientData.PinCode + Separator + stClientData.ClientName + Separator + stClientData.PhoneNumber + Separator + to_string(stClientData.AccountBalance);

	return ClientDataLine;
}

void SaveRecordToFile(string FileName,string ClientInfoLine)
{
	fstream fClientsInfoFile;
	fClientsInfoFile.open(FileName, ios::out | ios::app);
	if (fClientsInfoFile.is_open())
	{
		fClientsInfoFile << ClientInfoLine << endl;

		fClientsInfoFile.close();
	}

}

void AddNewClientToFile()
{
	char AddNew = 'Y';
	do
	{
		system("cls");
		cout << "\nAdding New Client...\n\n";
		SaveRecordToFile(ClientsFileName, ConvertRecordToLine(ReadClientData(), "#//#"));
		cout << "Client Added Successfully.\nDo You Want To Add More Clients? Answer Y/N: ";
		cin >> AddNew;

	} while (toupper(AddNew) == 'Y');
}

int main()
{
	AddNewClientToFile();
	system("pause>0");
	return 0; 
}
