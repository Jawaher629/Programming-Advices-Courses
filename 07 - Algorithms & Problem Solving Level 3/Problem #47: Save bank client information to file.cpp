#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct stClientData
{
	string ClientAccountNum = "";
	string ClientPinCode = "";
	string ClientName = "";
	string ClientPhoneNumber = "";
	double AccBalance = 0;

};

stClientData GetNewClientData()
{
	cout << "\n\n\nAdding New Client Data.\n\n\n";
	stClientData ClientInfo;
	cout << "Enter account number: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientAccountNum);

	cout << "Enter pin code: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientPinCode);

	cout << "Enter name: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientName);

	cout << "Enter Phone Number: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientPhoneNumber);

	cout << "Enter account balance: ";
	cin >> ClientInfo.AccBalance;

	return ClientInfo;
}





string ClientDataLine(stClientData ClientInfo, string delim)
{
	string stClientRecord = "";

	stClientRecord += ClientInfo.ClientAccountNum + delim;
	stClientRecord += ClientInfo.ClientPinCode + delim;
	stClientRecord += ClientInfo.ClientName + delim;
	stClientRecord += ClientInfo.ClientPhoneNumber + delim;
	stClientRecord += to_string(ClientInfo.AccBalance) + delim;

	return stClientRecord;
}


void SaveClientDataToFile(string Line)
{
	fstream ClientDataFile;
	ClientDataFile.open("ClientDataFile.txt", ios::out | ios::app);
	if (ClientDataFile.is_open())
	{
		if (Line != "")
			ClientDataFile << Line << endl;

	}
	ClientDataFile.close();
}




int main()
{
	char Again = 'Y';
	while (Again == 'y' || Again == 'Y')
	{
		SaveClientDataToFile(ClientDataLine(GetNewClientData(), "#//#"));
		cout << "Client information saved successfully. Do you want to add more clients? ";
		cin >> Again;
	}
	
	
	system("pause>0");
	return 0;
}

//Dr.Abu Hadhoud's solution

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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

stClientData GetNewClientData()
{
	stClientData ClientInfo;
	cout << "Enter account number: ";
	getline(cin >> ws, ClientInfo.ClientAccountNum);

	cout << "Enter pin code: ";
	getline(cin, ClientInfo.ClientPinCode);

	cout << "Enter name: ";
	getline(cin, ClientInfo.ClientName);

	cout << "Enter Phone Number: ";
	getline(cin, ClientInfo.ClientPhoneNumber);

	cout << "Enter account balance: ";
	cin >> ClientInfo.AccBalance;

	return ClientInfo;
}





string ClientDataToLine(stClientData ClientInfo, string delim)
{
	string stClientRecord = "";

	stClientRecord += ClientInfo.ClientAccountNum + delim;
	stClientRecord += ClientInfo.ClientPinCode + delim;
	stClientRecord += ClientInfo.ClientName + delim;
	stClientRecord += ClientInfo.ClientPhoneNumber + delim;
	stClientRecord += to_string(ClientInfo.AccBalance) + delim;

	return stClientRecord;
}


void SaveClientDataToFile(string ClientsFileName , string Line)
{
	fstream ClientDataFile;
	ClientDataFile.open(ClientsFileName, ios::out | ios::app);
	if (ClientDataFile.is_open())
	{
		if (Line != "")
			ClientDataFile << Line << endl;

	}
	ClientDataFile.close();
}

void AddNewClient()
{
	stClientData stClientData = GetNewClientData();
	SaveClientDataToFile(ClientsFileName,ClientDataToLine(stClientData, "#//#"));
}

void AddNewClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "\n\n\nAdding New Client Data.\n\n\n";

		AddNewClient();
		cout << "Client information saved successfully. Do you want to add more clients? Y/N?";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddNewClients();
	
	system("pause>0");
	return 0;
}
