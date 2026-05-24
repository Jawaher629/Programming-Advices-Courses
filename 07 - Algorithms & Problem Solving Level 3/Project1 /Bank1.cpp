//The Solution added nationality to it
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ClientsFile.txt";
enum enUserChoices { ClientList = 1, AddNewClient = 2, DeleteAccount = 3, UpdateClient = 4, FindClient = 5, Exit = 6 };
struct stClientData
{
	string AccountNumber = "";
	string PinCode = "";
	string ClientName = "";
	string PhoneNumber = "";
	string Nationality = "";
	double AccountBalance = 0.0;
	bool MarkForDelete = false;
};

void ShowMainMenu();
stClientData ConvertLineToRecord(string Line, string Separator);
bool CheckAccountExistsByAccNumber(string FileName, string AccountNumber);
bool FindAccountByAccNumber(string AccountNumber, vector <stClientData>& vClients, stClientData& stClient);



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

bool IsAccountNumberFound(string Accountnum)
{
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient;
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

string ReadAccountNumber()
{
	string AccountNum = "";
	cout << "Enter Account Number: ";
	cin >> AccountNum;
	return AccountNum;
}

stClientData ReadNewClientData()
{

	stClientData ClientData;
		cout << "Enter Account Number: ";
		getline(cin >> ws, ClientData.AccountNumber);
		while (CheckAccountExistsByAccNumber(ClientsFileName,ClientData.AccountNumber))
		{
			cout << "Client With Account Number [" << ClientData.AccountNumber << "] Is Already Exists,Try Another One: \n";
			getline(cin >> ws, ClientData.AccountNumber);
		}
		cout << "Enter Pin code: ";
		getline(cin, ClientData.PinCode);
		cout << "Enter Client's Name: ";
		getline(cin, ClientData.ClientName);
		cout << "Enter Phone Number: ";
		getline(cin, ClientData.PhoneNumber);
		cout << "Enter Nationality: ";
		getline(cin, ClientData.Nationality);
		cout << "Enter Account Balance: ";
		cin >> ClientData.AccountBalance;
	

	return ClientData;
}

short ReadUserMenuChoise()
{
	short Choise = 0;
	cout << "Enter Your Choise: ";
	cin >> Choise;
	return Choise;
}

void GoBackToMainMenu()
{
	cout << "Press Any Key To Go Back To The Screen Menu...\n";
	system("pause>0");
	ShowMainMenu();
}



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
	strClientData.Nationality = vClientData[4];
	strClientData.AccountBalance = stod(vClientData[5]);

	return strClientData;
}

string ConvertRecordToLine(stClientData &stClientData, string Separator)
{
	string ClientDataLine = "";

	ClientDataLine += stClientData.AccountNumber + Separator + stClientData.PinCode + Separator + stClientData.ClientName + Separator + stClientData.PhoneNumber + Separator +stClientData.Nationality + Separator  + to_string(stClientData.AccountBalance);

	return ClientDataLine;
}

void SaveRecordToFile(string FileName, string ClientInfoLine)
{
	fstream fClientsInfoFile;
	fClientsInfoFile.open(FileName, ios::out | ios::app);
	if (fClientsInfoFile.is_open())
	{
		fClientsInfoFile << ClientInfoLine << endl;

		fClientsInfoFile.close();
	}

}

bool CheckAccountExistsByAccNumber(string FileName, string AccountNumber)
{
	vector <stClientData> vClients;
	fstream fClientsFils;

	fClientsFils.open(FileName, ios::in);
	if (fClientsFils.is_open())
	{
		string Line;
		stClientData stClient;

		while (getline(fClientsFils, Line))
		{
			stClient = ConvertLineToRecord(Line, "#//#");
			if (stClient.AccountNumber == AccountNumber)
			{
				fClientsFils.close();
				return true;
			}
			vClients.push_back(stClient);
		}
	}

	return false;
}


void AddNewClientToFile()
{
	stClientData stClient = ReadNewClientData();
	SaveRecordToFile(ClientsFileName, ConvertRecordToLine(stClient, "#//#"));
}


void AddNewClientsToFile()
{
	char AddNew = 'Y';
	do
	{
		cout << "\nAdding New Client...\n\n";
		AddNewClientToFile();
		cout << "Client Added Successfully.\nDo You Want To Add More Clients? Answer Y/N: ";
		cin >> AddNew;

	} while (toupper(AddNew) == 'Y');
}

void ShowAddNewClientsScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Add New Client Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	AddNewClientsToFile();
}

void PrintaClientRecord(stClientData &ClientData)
{
	cout << "\n\n...................................................";
	cout << "\nClient's Name  : " << ClientData.ClientName;
	cout << "\nAccount Number : " << ClientData.AccountNumber;
	cout << "\nPin Code       : " << ClientData.PinCode;
	cout << "\nPhone Number   : " << ClientData.PhoneNumber;
	cout << "\nNationality    : " << ClientData.Nationality;
	cout << "\nAccount Balance: " << ClientData.AccountBalance;
	cout << "\n...................................................\n\n";


}



bool MarkAccountForDeletion(vector <stClientData>& vClient, string& AccountNumber)
{
	for (stClientData& Cl : vClient)
	{
		if (Cl.AccountNumber == AccountNumber)
		{
			Cl.MarkForDelete = true;
			return true;
		}
	}

	return false;
}

vector <stClientData> SaveClientDataToFile(string FileName, vector <stClientData> &vClientsData)
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

bool DeleteClientByAccountNumber(string Accountnum, vector <stClientData>& vClient)
{
	stClientData stClient;
	char Answer = 'N';

	if (FindAccountByAccNumber(Accountnum, vClient, stClient))
	{
		PrintaClientRecord(stClient);
		cout << endl << "Are you sure you want to delete this account? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkAccountForDeletion(vClient, Accountnum);
			SaveClientDataToFile(ClientsFileName, vClient);
			vClient = LoadClientInfoFromFile(ClientsFileName);
			cout << "Account Deleted Successfully.\n";

			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << Accountnum << ") Was Not Found!";
		return false;
	}
	return false;
}

void ShowDeleteClientScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Delete Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

stClientData UpdateClientData(string AccountNumber)
{
	stClientData ClientData;
	ClientData.AccountNumber = AccountNumber;;
	cout << "Enter Pin code: ";
	getline(cin >> ws, ClientData.PinCode);
	cout << "Enter Client's Name: ";
	getline(cin, ClientData.ClientName);
	cout << "Enter Phone Number: ";
	getline(cin, ClientData.PhoneNumber);
	cout << "Enter Nationality: ";
	getline(cin, ClientData.Nationality);
	cout << "Enter Account Balance: ";
	cin >> ClientData.AccountBalance;

	return ClientData;
}

bool UpdateClientDataByAccountNumber(string Accountnum, vector <stClientData>& vClient)
{
	stClientData stClient;
	char Answer = 'N';

	if (FindAccountByAccNumber(Accountnum, vClient, stClient))
	{
		PrintaClientRecord(stClient);
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
	return false;

}

void ShowUpdateClientDataScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Update Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	string AccountNumber = ReadAccountNumber();
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	UpdateClientDataByAccountNumber(AccountNumber, vClients);

}

void PrintClientRecord2(stClientData &stClient)
{
	cout << "| " << setw(15) << stClient.AccountNumber;
	cout << "| " << setw(10) << stClient.PinCode;
	cout << "| " << setw(40) << stClient.ClientName;
	cout << "| " << setw(12) << stClient.PhoneNumber;
	cout << "| " << setw(15) << stClient.Nationality;
	cout << "| " << setw(12) << stClient.AccountBalance;
}

void PrintAllClientsInfo()
{
	vector <stClientData> vClientsInfo = LoadClientInfoFromFile(ClientsFileName);
	cout << "\n\t\t\t\t\t Clients List (" << vClientsInfo.size() << ") Client(s).\n" << endl;
	cout << "\n________________________________________________________________________________________________________________________\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client's Name";
	cout << "| " << left << setw(12) << "Phone Number";
	cout << "| " << left << setw(15) << "Nationality";
	cout << "| " << left << setw(12) << "Account Balance" << endl;
	cout << "\n________________________________________________________________________________________________________________________\n";

	for (stClientData &stClient : vClientsInfo)
	{
		PrintClientRecord2(stClient);
		cout << endl;
	}
	cout << "\n________________________________________________________________________________________________________________________\n";
}


void ShowEndProgramScreen()
{
	system("cls");
	cout << "+++++++++++++++++++++++++++++++++++++\n\n";
	cout << "End Of Program Screen\n\n";
	cout << "+++++++++++++++++++++++++++++++++++++\n\n";

}

bool FindAccountByAccNumber(string AccountNumber , vector <stClientData> &vClients , stClientData& stClient)
{
	vClients = LoadClientInfoFromFile(ClientsFileName);
	for (stClientData &Cl : vClients)
	{
		if (Cl.AccountNumber == AccountNumber)
		{
			cout << "(" << AccountNumber << ")" << " Information: " << endl;
			stClient = Cl;
			return true;
		}
	}
	cout << "Sorry,(" << AccountNumber << ")" << " Is NOT Found.\n";
	return false;
}

void ShowFindClientInSystemScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Find Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient;
	if (FindAccountByAccNumber(ReadAccountNumber(), vClient, stClient))
	      PrintaClientRecord(stClient);

}

void RunBankSystem(enUserChoices UserChoice)
{


	switch (UserChoice)
	{
		case enUserChoices::ClientList:
		{
			system("cls");
			PrintAllClientsInfo();
			GoBackToMainMenu();
			break;
		}
	
	    case enUserChoices::AddNewClient:
	    {
		    system("cls");
		    ShowAddNewClientsScreen();
		    GoBackToMainMenu();
		break;
	    }
	case enUserChoices::DeleteAccount:
	{
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;
	}
	case enUserChoices::UpdateClient:
	{
		system("cls");
		ShowUpdateClientDataScreen();
		GoBackToMainMenu();
		break;
	}
	case enUserChoices::FindClient:
	{
		system("cls");
		ShowFindClientInSystemScreen();
		GoBackToMainMenu();
		break;
	}
	case enUserChoices::Exit:
	{
		system("cls");
		ShowEndProgramScreen();
		break;
	}
	}

}

void ShowMainMenu()
{
	system("cls");
	cout << "\n =====================================================================================================\n\n";
	cout << "\t                                          Main Menu Screen                                           \n";
	cout << "\n =====================================================================================================\n\n";

	cout << "\t\t[1] Show Clients List. " << endl;
	cout << "\t\t[2] Add A New Client. " << endl;
	cout << "\t\t[3] Delete Account. " << endl;
	cout << "\t\t[4] Update Client's Data. " << endl;
	cout << "\t\t[5] Find Client Data." << endl;
	cout << "\t\t[6] Exit." << endl;
	cout << "\n =====================================================================================================\n\n";
	RunBankSystem((enUserChoices)ReadUserMenuChoise());

}


int main()
{
	ShowMainMenu();
	system("pause>0");
	return 0;
}
