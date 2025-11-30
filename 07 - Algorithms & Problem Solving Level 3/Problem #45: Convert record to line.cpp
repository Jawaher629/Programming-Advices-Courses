// My solution:
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


stClientData GetClientData()
{
	stClientData ClientInfo;
	cout << "Enter your account number: ";
	cin >> ClientInfo.ClientAccountNum;

	cout << "Enter the pin code: ";
	cin >> ClientInfo.ClientPinCode;

	cout << "Enter your name: ";
	cin.ignore(1, '\n');
	getline(cin,ClientInfo.ClientName);

	cout << "Enter your Phone Number: ";
	cin >> ClientInfo.ClientPhoneNumber;

	cout << "Enter account balance: ";
	cin >> ClientInfo.AccBalance;

	return ClientInfo;
}


void PrintClientInfo(stClientData  ClientInfo , string delim)
{
	cout << "Client Record for saving is : \n";
	cout << delim << ClientInfo.ClientAccountNum << delim << ClientInfo.ClientPinCode << delim << ClientInfo.ClientName << delim << ClientInfo.ClientPhoneNumber << delim << ClientInfo.AccBalance << delim;
}


int main()
{
	PrintClientInfo(GetClientData(), " #//# ");

	system("pause>0");
	return 0;
}
//Dr. Abu Hadhoud solution:

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

stClientData GetNewClientData()
{
	stClientData ClientInfo;
	cout << "Enter account number: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientAccountNum);

	cout << "Enter the pin code: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientPinCode);

	cout << "Enter name: ";
	cin.ignore(1, '\n');
	getline(cin,ClientInfo.ClientName);

	cout << "Enter Phone Number: ";
	cin.ignore(1, '\n');
	getline(cin, ClientInfo.ClientPhoneNumber);

	cout << "Enter account balance: ";
	cin.ignore(1, '\n');
	cin >> ClientInfo.AccBalance;

	return ClientInfo;
}





string PrintClientInfo(stClientData ClientInfo , string delim)
{
	string stClientRecord = "";
	
	stClientRecord += ClientInfo.ClientAccountNum + delim;
	stClientRecord += ClientInfo.ClientPinCode + delim;
	stClientRecord += ClientInfo.ClientName + delim;
	stClientRecord += ClientInfo.ClientPhoneNumber + delim;
	stClientRecord += to_string(ClientInfo.AccBalance) + delim;

	return stClientRecord;
}


int main()
{
	stClientData Client = GetNewClientData();
	cout << "Client record for saving is: \n" << PrintClientInfo(Client, " #//# ");

	
	system("pause>0");
	return 0;
}
