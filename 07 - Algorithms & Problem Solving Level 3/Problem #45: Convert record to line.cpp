// My solution:
#include <iostream>
#include <string>
#include <vector>
#include "My_Input_Lib.h"
using namespace std;

struct stClientData
{
	string ClientAccountNum = "";
	string ClientPinCode = "";
	string ClientName = "";
	string ClientPhoneNumber = "";
	long double AccBalance = 0;



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

void PrintClientInfo(stClientData ClientInfo)
{
	cout << "Client Record for saving is : \n";

	cout << ClientInfo.ClientAccountNum << "#// ";
	cout << ClientInfo.ClientPinCode << "#// ";
	cout <<"#" << ClientInfo.ClientName << "#// ";
	cout << ClientInfo.ClientPhoneNumber << "#// ";
	cout << ClientInfo.AccBalance << "#// ";
}


int main()
{
	PrintClientInfo(GetClientData());

	
	system("pause>0");
	return 0;
}

//Dr. Abu Hadhoud solution:
