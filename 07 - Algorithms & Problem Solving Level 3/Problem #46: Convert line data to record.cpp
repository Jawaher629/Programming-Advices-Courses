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

vector <string> SplitString(string Sent1, string Delim)
{
	vector <string> vSentence;

	string sWord = "";
	short Pos = 0;

	while ((Pos = Sent1.find(Delim)) != std::string::npos)
	{
		sWord = Sent1.substr(0, Pos);
		if (sWord != "")
		{
			vSentence.push_back(sWord);
		}
		Sent1.erase(0, Pos + Delim.length());
	}
	return vSentence;
}

stClientData ConvertLineToData(string Sent1)
{
	vector <string> vClintsData = SplitString(Sent1, "#//#");
	stClientData ClientsInfo;
	
	
		ClientsInfo.AccountNumber = vClintsData[0];
		ClientsInfo.PinCode = vClintsData[1];
		ClientsInfo.ClientName = vClintsData[2];
		ClientsInfo.PhoneNumber = vClintsData[3];
		ClientsInfo.AccountBalance = stod(vClintsData[4]);
	
	return ClientsInfo;
}

void PrintClientRecord(stClientData ClientData)
{
	cout << "\nClient's Name: " << ClientData.ClientName;
	cout << "\nAccount Number: " << ClientData.AccountNumber;
	cout << "\nPin Code: " << ClientData.PinCode;
	cout << "\nPhone Number: " << ClientData.PhoneNumber;
	cout << "\nAccount Balance: " << ClientData.AccountBalance;

}

int main()
{


	string Sent1 = "#//#A120#//#77778888#//#Noor#//#0987654321#//#5000000#//#";
	stClientData ClientsData = ConvertLineToData(Sent1);
	PrintClientRecord(ClientsData);


	system("pause>0");
	return 0;
}




