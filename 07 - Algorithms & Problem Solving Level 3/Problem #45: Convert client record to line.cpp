#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string PhoneNumber = "";
	double AccountBalance = 0.00;

};

stClientData GetClientInformation()
{
	stClientData ClientData;
	cout << "Enter Account Number: ";
	getline(cin, ClientData.AccountNumber);

	cout << "Enter Pincode: ";
	getline(cin, ClientData.PinCode);

	cout << "Enter Name: ";
	getline(cin, ClientData.ClientName);

	cout << "Enter phone number: ";
	getline(cin, ClientData.PhoneNumber);

	cout << "Enter Account balance: ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

string ConvertClientDataToLine(stClientData ClientsDatam, string Delim)
{
	string Line = "";

	Line += ClientsDatam.AccountNumber + Delim;
	Line += ClientsDatam.PinCode + Delim;
	Line += ClientsDatam.ClientName + Delim;
	Line += ClientsDatam.PhoneNumber + Delim;
	Line += to_string(ClientsDatam.AccountBalance) + Delim;


	return Line;
}


int main()
{
  cout << "\n Please Enter Client's Data: \n\n";
  
	stClientData ClientData = GetClientInformation();

  cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertClientDataToLine(ClientData, "#//#");


	system("pause>0");
	return 0;
}



