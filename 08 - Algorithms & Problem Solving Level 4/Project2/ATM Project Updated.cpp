// This ATM project updated with more features which are :1- Show personal information.2- Update the personal information.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ClientsFile.txt";

enum enClientMainMenu { ShowPersonalInfoScreen = 1, QuickWithdraw , NormalWithdraw ,Deposit, CheckBalance, UpdatePersonalInfo, LogOut};


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
stClientData CurrentClient;

stClientData ConvertLineToRecord(string Line, string Separator = "#//#");
string ConvertRecordToLine(stClientData& stClientData, string Separator);
void ShowMainMenu();
void GoBackToMainMenu();
void Login();

short ReadUserMenuChoice()
{
	short Choice = 0;
	cout << "Enter Your Choice: ";
	cin >> Choice;
	return Choice;
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


bool FindAccountByAccNumber(string AccountNumber, vector <stClientData>& vClients, stClientData& stClient)
{
	vClients = LoadClientInfoFromFile(ClientsFileName);
	for (stClientData& Cl : vClients)
	{
		if (Cl.AccountNumber == AccountNumber)
		{
			
			stClient = Cl;
			return true;
		}
	}
	cout << "Sorry,(" << AccountNumber << ")" << " Is NOT Found.\n";
	return false;
}


bool FindClientByUsernameAndPassword(string AccountNumber, string Pincode, stClientData& Client)
{
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	for (stClientData& Cl: vClients)
	{
		if (Cl.AccountNumber == AccountNumber && Cl.PinCode == Pincode)
		{
			Client = Cl;
			return true;
		}
	}
	return false;
}


bool LoadClientInfo(string Username, string Password)
{
	if (FindClientByUsernameAndPassword(Username, Password, CurrentClient))
		return true;
	else
		return false;
}


vector <stClientData> SaveClientDataToFile(string FileName, vector <stClientData>& vClientsData)
{
	string DataLine = "";
	fstream fClientsDataFile;

	fClientsDataFile.open(FileName, ios::out);
	if (fClientsDataFile.is_open())
	{
		for (stClientData& Cl : vClientsData)
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

string ReadAccountNumber(string Message)
{
	string AccountNum = "";
	cout << Message;
	cin >> AccountNum;
	return AccountNum;
}


int ReadIntNumber(string Message)
{
	int DoubleNum = 0;
	cout << Message;
	cin >> DoubleNum;
	return DoubleNum;
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

string ConvertRecordToLine(stClientData& stClientData, string Separator)
{
	string ClientDataLine = "";

	ClientDataLine += stClientData.AccountNumber + Separator + stClientData.PinCode + Separator + stClientData.ClientName + Separator + stClientData.PhoneNumber + Separator + stClientData.Nationality + Separator + to_string(stClientData.AccountBalance);

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


bool AddMoneyToAccount(double DepositAmount, string AccountNum, vector<stClientData>& vClients)
{
	char Validation = 'n';

	cout << "Are you sure you want to perfirm this transaction? Answer [Y/N]: ";
	cin >> Validation;

	if (toupper(Validation) == 'Y')
	{
		for (stClientData& Cl : vClients)
		{
			if (Cl.AccountNumber == AccountNum)
			{
				Cl.AccountBalance += DepositAmount;

				SaveClientDataToFile(ClientsFileName, vClients);

				cout << "Operation Done Successfully.\n";
				cout << "New Balance is: "
					<< Cl.AccountBalance << endl;

				return true;
			}
		}

	}

	return false;
}


void PrintClientsAccountBalances()
{
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t\t\t\t\tClient Acount Balance\n";
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	vector <stClientData> vClientsInfo = LoadClientInfoFromFile(ClientsFileName);
	
	

		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client's Name";
		cout << "| " << left << setw(12) << "Account Balance" << endl;
		cout << "________________________________________________________________________________________________________________________";

		for (stClientData& stClient : vClientsInfo)
		{
			if(stClient.AccountNumber == CurrentClient.AccountNumber)
			{
				cout << left << setw(18) << stClient.AccountNumber;
				cout << left << setw(45) << stClient.ClientName;
				cout << left << setw(12) << stClient.AccountBalance << endl;
			}
		}
		cout << "\n________________________________________________________________________________________________________________________\n";
	}



bool PerformDepositByAccountNum()
{
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient = CurrentClient;
	string Accountnum = ReadAccountNumber("Enter Account Number For Conformation: ");

	while (!FindAccountByAccNumber(Accountnum, vClient, stClient))
	{
		Accountnum = ReadAccountNumber("Enter Account Number For Conformation: ");
	}

	double NewBalance = 0;
	cout << "Enter Deposit Amount: ";
	cin >> NewBalance;
	AddMoneyToAccount(NewBalance, Accountnum, vClient);
	return true;

}

void ShowDepositScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Deposit Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	PerformDepositByAccountNum();
}

bool PerformNormalWithdrawMoneyFromAccount(string Accountnum)
{
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient = CurrentClient;

	int NewBalance = 0;
	cout << "\nEnter Withdraw Amount: ";
	cin >> NewBalance;
	while (NewBalance % 5 != 0)
	{
		cout << "Unavailable amount, Please enter a number from 5 multiplier: ";
		cin >> NewBalance;
	}
	while (NewBalance > stClient.AccountBalance)
	{
		cout << "\nNo enough balance in account.\nYou can withdraw up to " << stClient.AccountBalance << "\nEnter another amount: ";
		cin >> NewBalance;
	}
	AddMoneyToAccount(NewBalance * -1, Accountnum, vClient);
	return true;
}

int QuickWithdrawUserChoice(short ClientChoice = 0)
{
	int Amount = 0;
	if (ClientChoice == 1)
		Amount = 20;
	if (ClientChoice == 2)
		Amount = 50;
	if (ClientChoice == 3)
		Amount = 100;
	if (ClientChoice == 4)
		Amount = 200;
	if (ClientChoice == 5)
		Amount = 400;
	if (ClientChoice == 6)
		Amount = 600;
	if (ClientChoice == 7)
		Amount = 800;
	if (ClientChoice == 8)
		Amount = 1000;
	if (ClientChoice == 9)
		ShowMainMenu();

	return Amount;
}


bool PerforQuickmWithdrawMoneyFromAccount(string Accountnum)
{
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient = CurrentClient;
	int ClientChoice = QuickWithdrawUserChoice(ReadIntNumber("Enter a number between [1] and [9]: "));
	
	while (ClientChoice > stClient.AccountBalance)
	{
		cout << "\nNo enough balance in account.\nYou can withdraw up to " << stClient.AccountBalance << "\nEnter another amount: ";
		cin >> ClientChoice;
	}
	AddMoneyToAccount(ClientChoice * -1, Accountnum, vClient);
	return true;
}


void ShowNormalWitdrawScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Withdraw Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	PerformNormalWithdrawMoneyFromAccount(CurrentClient.AccountNumber);
}


void GoBackToMainMenu()
{
	cout << "Press Any Key To Go Back To The Main Screen...\n";
	system("pause>0");
	system("cls");
	ShowMainMenu();
}


void ShowQuickWithdrawScreen()
{
	cout << "====================================================\n\n";
	cout << "\t\t Quick Withdraw Screen" << endl;
	cout << "\n====================================================\n\n";

	cout << "\t[1] 20.\t\t\t [2] 50.\n";
	cout << "\t[3] 100.\t\t [4] 200.\n";
	cout << "\t[5] 400.\t\t [6] 600.\n";
	cout << "\t[7] 800.\t\t [8] 1000.\n";
	cout << "\t[9] Exit.\n";

	PerforQuickmWithdrawMoneyFromAccount(CurrentClient.AccountNumber);


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
	return ClientData;
}

void PrintaClientRecord(stClientData& ClientData)
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

bool UpdateClientDataByAccountNumber(string Accountnum, vector <stClientData>& vClient)
{
	stClientData stClient;
	char Answer = 'N';

	    PrintaClientRecord(CurrentClient);
		cout << endl << "\nAre you sure you want to update your personal information? Y/N?";
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
	return false;

}


void ShowUpdateClientDataScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Update Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	string AccountNumber = CurrentClient.AccountNumber;
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	UpdateClientDataByAccountNumber(AccountNumber, vClients);

}



void RunATMMenu(enClientMainMenu ClientChoice)
{
	switch (ClientChoice)
	{
	case enClientMainMenu::ShowPersonalInfoScreen:
	{
		system("cls");
		PrintaClientRecord(CurrentClient);
		GoBackToMainMenu();
		break;
	}
	case enClientMainMenu::QuickWithdraw:
	{
		system("cls");
		ShowQuickWithdrawScreen();
		GoBackToMainMenu();
		break;
	}

	case enClientMainMenu::NormalWithdraw:
	{
		system("cls");
		ShowNormalWitdrawScreen();
		GoBackToMainMenu();
		break;
	}

	case enClientMainMenu::Deposit:
	{

		system("cls");
		ShowDepositScreen();
		GoBackToMainMenu();
		break;
	}
	case enClientMainMenu::CheckBalance:
	{
		system("cls");
		PrintClientsAccountBalances();
		GoBackToMainMenu();
		break;
		
	}
	case enClientMainMenu::UpdatePersonalInfo:
	{
		system("cls");
		ShowUpdateClientDataScreen();
		GoBackToMainMenu();
		break;
	}
	case enClientMainMenu::LogOut:
	{
		system("cls");
		Login();
		break;
	}
	}

}

void ShowMainMenu()
{
	system("cls");
	cout << "\n=====================================================================" << endl << endl;
	cout << "------------------------{ ATM Menu }-------------------------" << endl << endl;
	cout << "\n=====================================================================" << endl << endl;

	cout << "\t\t [1] Show Personal Information." << endl;
	cout << "\t\t [2] Quick Withdraw." << endl;
	cout << "\t\t [3] Normal WithDraw." << endl;
	cout << "\t\t [4] Deposit Screen." << endl;
	cout << "\t\t [5] Check Balance." << endl;
	cout << "\t\t [6] Update personal information." << endl;
	cout << "\t\t [7] Log Oute." << endl << endl;

	RunATMMenu((enClientMainMenu)ReadUserMenuChoice());

}


void Login()
{
	bool LogainFaild = false;
	string Username, Password;

	do
	{
		system("cls");
		cout << "\n--------------------------------------------------------------------------------------\n";
		cout << "\n-----------------------               Log In Screen                 ------------------\n";
		cout << "\n--------------------------------------------------------------------------------------\n";
		if (LogainFaild)
		{
			cout << "Invalid Username/Password.\n";
		}

		cout << "Enter username: ";
		cin >> Username;
		cout << "Enter password: ";
		cin >> Password;
		LogainFaild = !LoadClientInfo(Username, Password);

	} while (LogainFaild);
	system("cls");
	ShowMainMenu();
}

int main()
{
	Login();
}
