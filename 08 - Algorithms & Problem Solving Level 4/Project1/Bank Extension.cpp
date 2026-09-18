#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

const string ClientsFileName = "ClientsFile.txt";
const string UserFileName = "UsersFile.txt";


enum enUserChoices { ClientList = 1, AddNewClient = 2, DeleteAccount = 3, UpdateClient = 4, FindClient = 5, Transaction = 6, ManageUsers = 7, LogOut = 8};
enum enTransactionsMenu {Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4};
enum enUsersManageMenu { UsersList = 1, AddNewUsers = 2, DeleteUser = 3, UpdateUsers = 4, FindUsers = 5, uMainMenu = 6};
enum enMainMenuPermission {All = -1, pClientList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64};

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
struct stUser
{
	string UserName = "";
	string UserPassword = "";
	int Permission = 0;
	bool MarkForDeletion = false;
};
stUser CurrentUser;

void ShowMainMenu();
void ShowManageUsersMenu();
stClientData ConvertLineToRecord(string Line, string Separator);
bool CheckAccountExistsByAccNumber(string FileName, string AccountNumber);
bool FindAccountByAccNumber(string AccountNumber, vector <stClientData>& vClients, stClientData& stClient);
void ShowTransactionScreen();
bool CheckUserExistsByUsername(string UserFileName, string Username);
bool CheckAccessPermission(enMainMenuPermission Permission);
void ShowAccessDeniedScreen();
stUser ConvertUserLineToRecord(string Line, string Separator);
bool FindUserByUsername(string Username, vector <stUser>& vUsers, stUser& stUsers);

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

vector <stUser> LoadUserInfoFromFile(string UserFileName)
{
	vector <stUser> vUserInfo;
	fstream fUserFile;

	fUserFile.open(UserFileName, ios::in);
	if (fUserFile.is_open())
	{
		string line;
		stUser sUser;

		while (getline(fUserFile, line))
		{
			sUser = ConvertUserLineToRecord(line, "#//#");
			
			vUserInfo.push_back(sUser);
		}
		fUserFile.close();
	}

	return vUserInfo;
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

string ReadAccountNumber(string Message)
{
	string AccountNum = "";
	cout << Message;
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

int ReadPermissionToSet()
{
	int Permission = 0;
	char Decision = 'n';

	cout << "\n - Do you want to give this user FULL access? \n Enter Y or N: ";
	cin >> Decision;
	if (Decision == 'y' || Decision == 'Y')
	{
		return -1;
	}

	cout << "\n- Do you want to give this user Access to:\n";

	cout << "\n1- Show client list? Y/N:";
	cin >> Decision;
	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pClientList;
	}

	cout << "\n2- Add new client? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pAddNewClient;
	}

	cout << "\n3- Delete client? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pDeleteClient;
	}

	cout << "\n4- Update client? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pUpdateClient;
	}

	cout << "\n5- Find client? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pFindClient;
	}
	cout << "\n6- Transactions? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pTransaction;
	}
	cout << "\n7- Manage users? Y/N: ";
	cin >> Decision;

	if (Decision == 'y' || Decision == 'Y')
	{
		Permission += enMainMenuPermission::pManageUsers;
	}

	return Permission;
}

stUser ReadNewUserData()
{

	stUser UserData;
	cout << "- Enter Username: ";
	getline(cin >> ws, UserData.UserName);
	while (CheckUserExistsByUsername(UserFileName, UserData.UserName))
	{
		cout << "User With Username [" << UserData.UserName << "] Is Already Exists,Try Another One: \n";
		getline(cin >> ws, UserData.UserName);
	}

	cout << "- Enter password: ";
	getline(cin, UserData.UserPassword);

	UserData.Permission = ReadPermissionToSet();
	

	return UserData;
}

short ReadUserMenuChoice()
{
	short Choice = 0;
	cout << "Enter Your Choice: ";
	cin >> Choice;
	return Choice;
}

void GoBackToMainMenu()
{
	cout << "Press Any Key To Go Back To The Screen Menu...\n";
	system("pause>0");
	ShowMainMenu();
}

void GoBackToUsersManagementMenu()
{
	cout << "Press Any Key To Go Back To Users Management Menu...\n";
	system("pause>0");
	ShowManageUsersMenu();
}

double ReadDoubleNumber(string Message)
{
	double DoubleNum = 0;
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

stClientData ConvertLineToRecord(string Line, string Separator = "#//#")
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

stUser ConvertUserLineToRecord(string Line, string Separator = "#//#")
{
	stUser strUser;
	vector <string> vUserData = SplitString(Line, Separator);

	strUser.UserName = vUserData[0];
	strUser.UserPassword = vUserData[1];
	strUser.Permission = stoi(vUserData[2]);
	return strUser;
}

string ConvertRecordToLine(stClientData &stClientData, string Separator)
{
	string ClientDataLine = "";

	ClientDataLine += stClientData.AccountNumber + Separator + stClientData.PinCode + Separator + stClientData.ClientName + Separator + stClientData.PhoneNumber + Separator +stClientData.Nationality + Separator  + to_string(stClientData.AccountBalance);

	return ClientDataLine;
}

string ConvertUserRecordToLine(stUser& User, string Separator)
{
	string UsertDataLine = "";

	UsertDataLine += User.UserName + Separator + User.UserPassword + Separator + to_string(User.Permission);

	return UsertDataLine;
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

bool CheckUserExistsByUsername(string UserFileName, string Username)
{
	vector <stUser> vUsers;
	fstream fUsersFils;

	fUsersFils.open(UserFileName, ios::in);
	if (fUsersFils.is_open())
	{
		string Line;
		stUser strUser;

		while (getline(fUsersFils, Line))
		{
			strUser = ConvertUserLineToRecord(Line, "#//#");
			if (strUser.UserName == Username)
			{
				fUsersFils.close();
				return true;
			}
			vUsers.push_back(strUser);
		}
	}

	return false;
}



void AddNewClientToFile()
{
	stClientData stClient = ReadNewClientData();
	SaveRecordToFile(ClientsFileName, ConvertRecordToLine(stClient, "#//#"));
}

void AddNewUserToFile()
{
	stUser UserData = ReadNewUserData();
	SaveRecordToFile(UserFileName, ConvertUserRecordToLine(UserData, "#//#"));
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

void AddNewUsersToFile()
{
	char AddNew = 'Y';
	do
	{
		system("cls");
		cout << "\nAdding New User...\n\n";
		AddNewUserToFile();
		cout << "User Added Successfully.\nDo You Want To Add More Users? Answer Y/N: ";
		cin >> AddNew;

	} while (toupper(AddNew) == 'Y');
}

void ShowAddNewClientsScreen()
{
	if (!CheckAccessPermission(enMainMenuPermission::pAddNewClient))
	{
		ShowAccessDeniedScreen();
		return;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Add New Client Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	AddNewClientsToFile();
}

void ShowAddNewUsersScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Add New Users Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	AddNewUsersToFile();
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

void PrintaUserRecord(stUser& UserData)
{
	cout << "\n\n...................................................";
	cout << "\nUsername  : " << UserData.UserName;
	cout << "\nPassword  : " << UserData.UserPassword;
	cout << "\nPermission: " << UserData.Permission;
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

bool MarkUserForDeletion(vector <stUser>& vUser, string& Username)
{
	for (stUser& USER : vUser)
	{
		if (USER.UserName == Username)
		{
			USER.MarkForDeletion = true;
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

vector <stUser> SaveUserDataToFile(string UserFileName, vector <stUser>& vUsers)
{
	string DataLine = "";
	fstream fUserDataFile;

	fUserDataFile.open(UserFileName, ios::out);
	if (fUserDataFile.is_open())
	{
		for (stUser& USER : vUsers)
		{
			if (USER.MarkForDeletion == false)
			{
				DataLine = ConvertUserRecordToLine(USER, "#//#");
				fUserDataFile << DataLine << endl;
			}
		}

		fUserDataFile.close();
	}
	return vUsers;
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

bool DeleteUserBUsername(string Username, vector <stUser>& vUser)
{
	if (Username == "Admin")
	{
		cout << "You CAN NOT delete this user.\n";
		return false;
	}
	stUser UserData;
	char Answer = 'N';

	if (FindUserByUsername(Username, vUser, UserData))
	{
		PrintaUserRecord(UserData);
		cout << endl << "Are you sure you want to delete this user? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkUserForDeletion(vUser, Username);
			SaveUserDataToFile(UserFileName, vUser);
			vUser = LoadUserInfoFromFile(UserFileName);
			cout << "User Deleted Successfully.\n";

			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << Username << ") Was Not Found!";
		return false;
	}
	return false;
}

void ShowDeleteClientScreen()
{
	if (!CheckAccessPermission(enMainMenuPermission::pDeleteClient))
	{
		ShowAccessDeniedScreen();
		return;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Delete Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber("Enter Account Number: ");
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void ShowDeleteUserScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Delete User Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	vector <stUser> vUsers = LoadUserInfoFromFile(UserFileName);
	string Username = ReadAccountNumber("Enter Username: ");
	DeleteUserBUsername(Username, vUsers);

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

stUser UpdateUserData(string Username)
{
	stUser UserData;
	UserData.UserName = Username;
	cout << "Enter new Password: ";
	getline(cin >> ws, UserData.UserPassword);
	cout << "Update Permission: ";
	UserData.Permission = ReadPermissionToSet();

	return UserData;
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

bool UpdateUserDataByUsername(string Username, vector <stUser>& vUser)
{
	stUser stUsers;
	char Answer = 'N';

	if (FindUserByUsername(Username, vUser, stUsers))
	{
		PrintaUserRecord(stUsers);
		cout << endl << "\nAre you sure you want to update this user information? Y/N?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			for (stUser& USER : vUser)
			{
				if (USER.UserName == Username)
				{
					USER = UpdateUserData(Username);
					break;
				}
			}

			SaveUserDataToFile(UserFileName, vUser);
			cout << "User Updated Successfully.\n";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << Username << ") Was Not Found!";
		return false;
	}
	return false;

}

void ShowUpdateClientDataScreen()
{
	if (!CheckAccessPermission(enMainMenuPermission::pUpdateClient))
	{
		ShowAccessDeniedScreen();
		return;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Update Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	string AccountNumber = ReadAccountNumber("Enter Account Number: ");
	vector <stClientData> vClients = LoadClientInfoFromFile(ClientsFileName);
	UpdateClientDataByAccountNumber(AccountNumber, vClients);

}

void ShowUpdateUsertDataScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Update User Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	string Username = ReadAccountNumber("Enter Username: ");
	vector <stUser> vUser = LoadUserInfoFromFile(UserFileName);
	UpdateUserDataByUsername(Username, vUser);

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

void PrintClientRecord2(stUser& stusers)
{
	cout << "| " << setw(15) << stusers.UserName;
	cout << "| " << setw(10) << stusers.UserPassword;
	cout << "| " << setw(40) << stusers.Permission;
}

void PrintAllClientsInfo()
{
	vector <stClientData> vClientsInfo = LoadClientInfoFromFile(ClientsFileName);
	if (vClientsInfo.size() == 0)
		cout << "There are NO Available clients in the system.\n";
	else
	{
		cout << "\n\t\t\t\t\t Clients List (" << vClientsInfo.size() << ") Client(s).\n" << endl;
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client's Name";
		cout << "| " << left << setw(12) << "Phone Number";
		cout << "| " << left << setw(15) << "Nationality";
		cout << "| " << left << setw(12) << "Account Balance" << endl;
		cout << "\n________________________________________________________________________________________________________________________\n";

		for (stClientData& stClient : vClientsInfo)
		{
			PrintClientRecord2(stClient);
			cout << endl;
		}
		cout << "\n________________________________________________________________________________________________________________________\n";
	}
}

void PrintAllUsersInSystemInfo()
{
	vector <stUser> vUserInfo = LoadUserInfoFromFile(UserFileName);
	if (vUserInfo.size() == 0)
		cout << "There are NO Available users in the system.\n";
	else
	{
		cout << "\n\t\t\t\t\t Users List (" << vUserInfo.size() << ") User(s).\n" << endl;
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(40) << "Permission";
		cout << "\n________________________________________________________________________________________________________________________\n";

		for (stUser& stUsers : vUserInfo)
		{
			PrintClientRecord2(stUsers);
			cout << endl;
		}
		cout << "\n________________________________________________________________________________________________________________________\n";
	}
}


void ShowEndProgramScreen()
{
	system("cls");
	cout << "+++++++++++++++++++++++++++++++++++++\n\n";
	cout << "Log Out Screen\n\n";
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

bool FindUserByUsername(string Username, vector <stUser>& vUsers, stUser& stUsers)
{
	vUsers = LoadUserInfoFromFile(UserFileName);
	for (stUser& USER : vUsers)
	{
		if (USER.UserName == Username)
		{
			cout << "(" << Username << ")" << " Information: " << endl;
			stUsers = USER;
			return true;
		}
	}
	cout << "Sorry,(" << Username << ")" << " Is NOT Found.\n";
	return false;
}

bool FindUserByUsernameAndPassword(string Username, string Password, stUser& User)
{
	vector <stUser> vUsers = LoadUserInfoFromFile(UserFileName);
	for (stUser& U : vUsers)
	{
		if (U.UserName == Username && U.UserPassword == Password)
		{
			User = U;
			return true;
		}
	}
	return false;
}

void ShowFindClientInSystemScreen()
{
	if (!CheckAccessPermission(enMainMenuPermission::pFindClient))
	{
		ShowAccessDeniedScreen();
		return;
	}
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Find Account Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient;
	if (FindAccountByAccNumber(ReadAccountNumber("Enter Account Number"), vClient, stClient))
	      PrintaClientRecord(stClient);

}

void ShowFindUserInSystemScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "               Find User Screen           \n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	vector <stUser> vUsers = LoadUserInfoFromFile(UserFileName);
	stUser sUser;
	if (FindUserByUsername(ReadAccountNumber("Enter Username: "), vUsers, sUser))
		PrintaUserRecord(sUser);

}

bool AddMoneyToAccount(double DepositAmount, string AccountNum, vector<stClientData> &vClients)
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

double SumBalances()
{
	double BalancesSum = 0.0;

	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	for (stClientData& Cl : vClient)
	{
		BalancesSum += Cl.AccountBalance;
	}
	return BalancesSum;
}

void PrintClientsAccountBalances()
{
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t\t\t\t\tClients Acount Balances\n";
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	vector <stClientData> vClientsInfo = LoadClientInfoFromFile(ClientsFileName);
	if (vClientsInfo.size() == 0)
		cout << "There are No clients in the system.\n";
	else
	{

		cout << "\n\t\t\t\t\t\tClients List (" << vClientsInfo.size() << ") Client(s).\n" << endl;
		cout << "\n________________________________________________________________________________________________________________________\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client's Name";
		cout << "| " << left << setw(12) << "Account Balance" << endl;
		cout << "________________________________________________________________________________________________________________________";

		for (stClientData& stClient : vClientsInfo)
		{
			cout << left << setw(18) << stClient.AccountNumber;
			cout << left << setw(45) << stClient.ClientName;
			cout << left << setw(12) << stClient.AccountBalance << endl;
		}
		cout << "\n________________________________________________________________________________________________________________________\n";

		cout << "\t\t\t\t\t" << "[ " << "Total Balances = " << SumBalances() << "] " << endl << endl;
	}
}

bool PerformDepositByAccountNum()
{
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient;
	string Accountnum = ReadAccountNumber("Enter Account Number: ");

	while (!FindAccountByAccNumber(Accountnum, vClient, stClient))
	{
		Accountnum = ReadAccountNumber("Enter Account Number: ");
	}

	PrintaClientRecord(stClient);
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

bool PerformWithdrawMoneyFromAccount()
{
	vector <stClientData> vClient = LoadClientInfoFromFile(ClientsFileName);
	stClientData stClient;
	string Accountnum = ReadAccountNumber("Enter Account Number: ");

	while (!FindAccountByAccNumber(Accountnum, vClient, stClient))
	{
		Accountnum = ReadAccountNumber("Enter Account Number: ");
	}

	PrintaClientRecord(stClient);
	double NewBalance = 0;
	cout << "\nEnter Withdraw Amount: ";
	cin >> NewBalance;

	while (NewBalance > stClient.AccountBalance)
	{
		cout << "\nNo enough balance in account.\nYou can withdraw up to " << stClient.AccountBalance << "\nEnter another amount: ";
		cin >> NewBalance;
	}
	AddMoneyToAccount(NewBalance*-1, Accountnum, vClient);
	return true;
}

void ShowWitdrawScreen()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout << "\t\t Withdraw Screen" << endl;
	cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

	PerformWithdrawMoneyFromAccount();
}

void GoBackToTransactionMenu()
{
	cout << "Press Any Key To Go Back To The Transaction Screen...\n";
	system("pause>0");
	system("cls");
	ShowTransactionScreen();
}

bool CheckAccessPermission(enMainMenuPermission Permission)
{
	if (CurrentUser.Permission == enMainMenuPermission::All)
		return true;
	if ((Permission & CurrentUser.Permission) == Permission)
		return true;
	else
		return false;
}
void ShowAccessDeniedScreen()
{
	cout << "\n...........................................................\n";
	cout << "\n ACCESS DENIED! You dont have permission to do this operation.\n Connect your Admin.\n";
	cout << "\n...........................................................\n";

}

void RunTranactionMenu(enTransactionsMenu UserChoice)
{
	switch (UserChoice)
	{
	case enTransactionsMenu::Deposit:
	{
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionMenu();
		break;
	}

	case enTransactionsMenu::Withdraw:
	{
		system("cls");
		ShowWitdrawScreen();
		GoBackToTransactionMenu();
		break;
	}

	case enTransactionsMenu::TotalBalance:
	{
		
			system("cls");
			PrintClientsAccountBalances();
			GoBackToTransactionMenu();
			break;
	}
	case enTransactionsMenu::MainMenu:
	{
		ShowMainMenu();
		break;
	}

	}

}

void ShowTransactionScreen()
{
	if (!CheckAccessPermission(enMainMenuPermission::pTransaction))
	{
		ShowAccessDeniedScreen();
		return;
	}
	cout << "\n=====================================================================" << endl << endl;
	cout << "------------------------{ Transaction Menu }-------------------------" << endl << endl;
	cout << "\n=====================================================================" << endl << endl;


	cout << "\t\t [1] Deposit." << endl;
	cout << "\t\t [2] WithDraw." << endl;
	cout << "\t\t [3] Balances Screen." << endl;
	cout << "\t\t [4] Main Menu." << endl << endl;

	RunTranactionMenu((enTransactionsMenu)ReadUserMenuChoice());

}

void PerformUsersMenuManagement(enUsersManageMenu ManageUserOption)
{
	switch (ManageUserOption)
	{
	case enUsersManageMenu::UsersList:
		system("cls");
		PrintAllUsersInSystemInfo();
		GoBackToUsersManagementMenu();
		break;

	case enUsersManageMenu::AddNewUsers:
	{
		system("cls");
		ShowAddNewUsersScreen();
		GoBackToUsersManagementMenu();
		break;
	}

	case enUsersManageMenu::DeleteUser:
	{
		system("cls");
		ShowDeleteUserScreen();
		GoBackToUsersManagementMenu();
		break;
	}

	case enUsersManageMenu::UpdateUsers:
	{
		system("cls");
		ShowUpdateUsertDataScreen();
		GoBackToUsersManagementMenu();
		break;
	}

	case enUsersManageMenu::FindUsers:
	{
		system("cls");
		ShowFindUserInSystemScreen();
		GoBackToUsersManagementMenu();
		break;
	}
	case enUsersManageMenu::uMainMenu:
	{
		ShowMainMenu();
		break;
	}
	}
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
	case enUserChoices::Transaction:
	{
		system("cls");
		ShowTransactionScreen();
		break;

	}
	case enUserChoices::ManageUsers:
	{

		system("cls");
		ShowManageUsersMenu();
		break;

	}
	case enUserChoices::LogOut:
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
	cout << "\t\t[6] Transactions." << endl;
	cout << "\t\t[7] ManageUsers." << endl;
	cout << "\t\t[8] Logout." << endl;
	cout << "\n =====================================================================================================\n\n";
	RunBankSystem((enUserChoices)ReadUserMenuChoice());

}

void ShowManageUsersMenu()
{
	if (!CheckAccessPermission(enMainMenuPermission::pManageUsers))
	{
		ShowAccessDeniedScreen();
		return;
	}
	system("cls");
	cout << "\n =====================================================================================================\n\n";
	cout << "\t                                         Manage Users Screen                                           \n";
	cout << "\n =====================================================================================================\n\n";

	cout << "\t\t[1] Show Users List. " << endl;
	cout << "\t\t[2] Add A New User. " << endl;
	cout << "\t\t[3] Delete User. " << endl;
	cout << "\t\t[4] Update User's Data. " << endl;
	cout << "\t\t[5] Find User." << endl;
	cout << "\t\t[6] Go Back to Main menu." << endl;
	cout << "\n =====================================================================================================\n\n";
	PerformUsersMenuManagement(enUsersManageMenu (ReadUserMenuChoice()));

}

bool LoadUserInfo(string Username, string Password)
{
	if (FindUserByUsernameAndPassword(Username, Password, CurrentUser))
		return true;
	else
		return false;
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
		LogainFaild = !LoadUserInfo(Username, Password);

	} while (LogainFaild);
	ShowMainMenu();
}

int main()
{
	Login();
	return 0;
}
