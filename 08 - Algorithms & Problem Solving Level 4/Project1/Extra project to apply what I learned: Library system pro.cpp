// This project is an application of what have been learned from Bank project. I add log in screen thet take admin username and pssword and allow she/him to control everthing in system.
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

struct stBookData
{
	string BookName = "";
	string ISBN = "";
	string Genre = ""; 
	string BookAuthorName = "";
	string BookLanguage = "";
	int PublishYear = 0;
	bool MarkForDeletion = false;
};

struct stUsersInfo
{
	string Username = "";
	string Password = "";
	int Permission = 0;
	bool MarkForDeletion = false;
};
stUsersInfo CurrentUser;

enum enMenuchoices{ViewBooksList = 1, AddNewBook = 2 , DeleteBook = 3, UpdateBookInfo = 4,FindBook = 5,UserManagement = 6,Authorsmanagement = 7, Logout = 8};
enum enUserManagement { ViewUsersList = 1, AddNewUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, BackToMenu = 6};
enum enPermissionManagement { All = -1, pViewBooksList = 1, pAddNewBook = 2, pDeleteBook = 4, pUpdateBookInfo = 8, pFindBook = 16, pManageUsers = 32};

const string BookFileName = "BookFile2.txt";
const string UserFileName = "UsersFile.txt";

void PrintMainMenu();
void RunLibrarySystem(enMenuchoices UserChoice);
bool IsISBNExisted(string ISBN);
int ReadUserPermissionToSet();
void PrintUserManagementMenu();
void PerformUserManagement(enUserManagement AdminChoise);
vector <stUsersInfo> LoadUserDataFromFile(string FileName);
bool IsUsernameExisted(string Username);

string ReadUserString(string Message)
{
	string BookName = "";
	cout << Message;
	cin >> BookName;
	return BookName;
}

int ReadUserInt(string Message)
{
	int Year = 0;
	cout << Message;
	cin >> Year;
	return Year;
}

void GoBackToMainScreen()
{

	cout << "\nPress any key to go back to main menu...\n";
	system("pause>0");
	system("cls");
	PrintMainMenu();
}

void GoBackToUserManagemenMenu()
{

	cout << "\nPress any key to go back to user management menu...\n";
	system("pause>0");
	system("cls");
	PrintUserManagementMenu();
}

int ReadUserPermissionToSet()
{
	int Permission = 0;
	char Decision = 'n';

	cout << "- Do you eant to give this user Full access? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		return -1;

	cout << "- Do you want this user to access Books List? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pViewBooksList;

	cout << "- Do you want this user to access Add New Books? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pAddNewBook;

	cout << "- Do you want this user to access Delete Books? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pDeleteBook;

	cout << "- Do you want this user to access Find Books? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pFindBook;

	cout << "- Do you want this user to access Update Books Information? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pUpdateBookInfo;

	cout << "- Do you want this user to access Manage Users? Y/N: ";
	cin >> Decision;
	if (toupper(Decision) == 'Y')
		Permission += enPermissionManagement::pManageUsers;

	return Permission;
}

bool CheckAccessPermission(enPermissionManagement Permission)
{
	if (CurrentUser.Permission == enPermissionManagement::All)
		return true;
	if ((CurrentUser.Permission & Permission) == Permission)
		return true;
	else
		return false;
}

bool FindUserByUserNameAndPassword(string Username, string Password, stUsersInfo &Currentuser)
{
	vector <stUsersInfo> vUsers = LoadUserDataFromFile(UserFileName);
	for (stUsersInfo& USER : vUsers)
	{
		if (USER.Username == Username && USER.Password == Password)
		{
			Currentuser = USER;
			return true;
		}
	}

	return false;
}

bool LoadUserInfoByUsernameAndPassword(string Username, string Password)
{
	if (FindUserByUserNameAndPassword(Username, Password, CurrentUser))
		return true;
	else
		return false;
}

void ShowAccessDeniedScreen()
{
	cout << "=======================================================================\n\n";
	cout << "ACCESS DENIED!!\nYou do NOT have permissin to access this option.\nConnect Your Admin.\n";
	cout << "\n=======================================================================\n\n";

}

stBookData ReadBookInfo()
{
	stBookData stBookInfo;
	string ReadISBN = ReadUserString("\nEnter ISBN Number: ");
	while(IsISBNExisted(ReadISBN))
	{
		cout << "\nThis ISBN is already existed.";
		cout << "\nTry another one.\n";
		ReadISBN = ReadUserString("\nEnter ISBN Number: ");
	}
	stBookInfo.ISBN = ReadISBN;
	cout << "Enter Book's Name: ";
	getline(cin >> ws, stBookInfo.BookName);
	cout << "Enter Author's Name: ";
	getline(cin, stBookInfo.BookAuthorName);
	cout << "Enter The Genre: ";
	getline(cin, stBookInfo.Genre);
	cout << "Enter Book Language: ";
	getline(cin, stBookInfo.BookLanguage);
	cout << "Enter Book's Publish Year: ";
	cin >> stBookInfo.PublishYear;
	return stBookInfo;

}

stUsersInfo ReadNewUserInfo()
{
	stUsersInfo stNewUser;
	string ReadUsername = ReadUserString("\nEnter username: ");
	while (IsUsernameExisted(ReadUsername))
	{
		cout << "\nThis User is already existed.";
		cout << "\nTry another one.\n";
		ReadUsername = ReadUserString("\nEnter Username: ");
	}
	stNewUser.Username = ReadUsername;
	cout << "Enter Password: ";
	getline(cin >> ws, stNewUser.Password);
	stNewUser.Permission = ReadUserPermissionToSet();
	return stNewUser;

}

stBookData UpdateBookInfoByISBN(string ISBN)
{
	stBookData stBookInfo;
	stBookInfo.ISBN = ISBN;
	cout << "Enter Book's Name; ";
	getline(cin >> ws, stBookInfo.BookName);
	cout << "Enter Author's Name: ";
	getline(cin, stBookInfo.BookAuthorName);
	cout << "Enter The Genre: ";
	getline(cin, stBookInfo.Genre);
	cout << "Enter Book Language: ";
	getline(cin, stBookInfo.BookLanguage);
	cout << "Enter Book's Publish Year: ";
	cin >> stBookInfo.PublishYear;
	return stBookInfo;

}

stUsersInfo UpdateUserInfoByUsername(string Username)
{
	stUsersInfo stUserInfo;
	stUserInfo.Username = Username;
	stUserInfo.Password = ReadUserString("Enter new password: ");
	stUserInfo.Permission = ReadUserPermissionToSet();
	return stUserInfo;

}

void PrintUserManagementMenu()
{
	if (!CheckAccessPermission(enPermissionManagement::pManageUsers))
		ShowAccessDeniedScreen();
	else
	{
		cout << "\n ===================================================================================================\n";
		cout << "\t\t\t\t\t User Management Screen";
		cout << "\n ===================================================================================================\n";

		cout << "\t[1] View Users List.\n";
		cout << "\t[2] Add New User.\n";
		cout << "\t[3] Delete User.\n";
		cout << "\t[4] Update User Information.\n";
		cout << "\t[5] Find User.\n";
		cout << "\t[6] Go Backe To Main Menu.\n";
		PerformUserManagement(enUserManagement(ReadUserInt("Enter your choise: ")));
	}

}

void PrintMainMenu()
{
	system("cls");
	cout << "\n ===================================================================================================\n";
	cout << "\t\t\t\t\t Library System Management ";
	cout << "\n ===================================================================================================\n";

	cout << "\t[1] View Books List.\n";
	cout << "\t[2] Add New Book.\n";
	cout << "\t[3] Delete Book.\n";
	cout << "\t[4] Update Book Information.\n";
	cout << "\t[5] Find Book.\n";
	cout << "\t[6] Users Management.\n";
	cout << "\t[7] Logout.\n";
	RunLibrarySystem((enMenuchoices)ReadUserInt("Enter Choice: "));
}

void PrintBookInfo(stBookData &stBookInfo)
{
	cout << "\n................Book Card.....................\n";
	cout << "Book Name     : " << stBookInfo.BookName << endl;
	cout << "Author        : " << stBookInfo.BookAuthorName << endl;
	cout << "Genre         : " << stBookInfo.Genre << endl;
	cout << "Language      : " << stBookInfo.BookLanguage << endl;
	cout << "Year Published: " << stBookInfo.PublishYear << endl;
	cout << "ISBN          : " << stBookInfo.ISBN << endl;
	cout << "................................................\n";
}

void PrintUserInfo(stUsersInfo& stUserInfo)
{
	cout << "\n................User Information Card.....................\n";
	cout << "Username  : " << stUserInfo.Username << endl;
	cout << "Password  : " << stUserInfo.Password << endl;
	cout << "Permission: " << stUserInfo.Permission << endl;
	cout << "\n..........................................................\n";

}

string ConvertBookRecordToLine(stBookData &stBookInfo , string Separator)
{
	string InfoLine = "";
	
	InfoLine += stBookInfo.BookName + Separator + stBookInfo.BookAuthorName + Separator + stBookInfo.Genre + Separator + stBookInfo.BookLanguage + Separator + to_string(stBookInfo.PublishYear) + Separator + stBookInfo.ISBN;
	return InfoLine;

}

string ConvertUserRecordToLine(stUsersInfo& stUserInfo, string Separator)
{
	string InfoLine = "";

	InfoLine += stUserInfo.Username + Separator + stUserInfo.Password + Separator + to_string(stUserInfo.Permission);
	return InfoLine;

}

void SaveBookInfoToFile(string FileName, stBookData stBookInfo)
{
	
	string InfoLine = ConvertBookRecordToLine(stBookInfo,"#///#");
	fstream fBooksFile;

	fBooksFile.open(FileName, ios::out |ios::app);
	if (fBooksFile.is_open())
	{
		
		fBooksFile << InfoLine << endl;
	}

	fBooksFile.close();
}

void SaveUserInfoToFile(string FileName, stUsersInfo stUserInfo)
{

	string InfoLine = ConvertUserRecordToLine(stUserInfo, "#///#");
	fstream fUserFile;

	fUserFile.open(FileName, ios::out | ios::app);
	if (fUserFile.is_open())
	{

		fUserFile << InfoLine << endl;
	}

	fUserFile.close();
}

vector <stBookData> SaveNewFileContent(string FileName, vector <stBookData>& vBookInfo)
{
	string DataLine = "";
	fstream fBookDataFile;

	fBookDataFile.open(FileName, ios::out);
	if (fBookDataFile.is_open())
	{
		for (stBookData& Cl : vBookInfo)
		{
			if (Cl.MarkForDeletion == false)
			{
				DataLine = ConvertBookRecordToLine(Cl, "#///#");
				fBookDataFile << DataLine << endl;
			}
		}

		fBookDataFile.close();
	}
	return vBookInfo;
}

vector <stUsersInfo> SaveNewUserFileContent(string FileName, vector <stUsersInfo>& vUserInfo)
{
	string DataLine = "";
	fstream fUserDataFile;

	fUserDataFile.open(FileName, ios::out);
	if (fUserDataFile.is_open())
	{
		for (stUsersInfo& user : vUserInfo)
		{
			if (user.MarkForDeletion == false)
			{
				DataLine = ConvertUserRecordToLine(user, "#///#");
				fUserDataFile << DataLine << endl;
			}
		}

		fUserDataFile.close();
	}
	return vUserInfo;
}

vector <string> SplitString(string Sent1,string Separator)
{
	vector <string> vWords;
	short pos = 0;
	string sWord;
	while ((pos = Sent1.find(Separator)) != std::string::npos)
	{
		sWord = Sent1.substr(0, pos);
		if (sWord != "")
			vWords.push_back(sWord);
		Sent1.erase(0, pos + Separator.length());
	}
	if (Sent1 != "")
		vWords.push_back(Sent1);
	return vWords;
}

stBookData ConvertBookLineToRecord(string Line, string Separator)
{
	vector <string> vBookInfo = SplitString(Line, Separator);
	stBookData stBookInfo;

	stBookInfo.BookName = vBookInfo[0];
	stBookInfo.BookAuthorName = vBookInfo[1];
	stBookInfo.Genre = vBookInfo[2];
	stBookInfo.BookLanguage = vBookInfo[3];
	stBookInfo.PublishYear = stoi(vBookInfo[4]);
	stBookInfo.ISBN = vBookInfo[5];


	return stBookInfo;

}

stUsersInfo ConvertUserLineToRecord(string Line, string Separator)
{
	vector <string> vUsers = SplitString(Line, Separator);
	stUsersInfo stUser;

	stUser.Username = vUsers[0];
	stUser.Password = vUsers[1];
	stUser.Permission = stoi(vUsers[2]);

	return stUser;

}

vector <stBookData> LoadDataFromFile(string FileName)
{
	vector <stBookData> vBookInfo;
	fstream fBookFile;

	fBookFile.open(FileName, ios::in);
	if (fBookFile.is_open())
	{
		string line;
		stBookData stBookInfo;

		while (getline(fBookFile, line))
		{
			stBookInfo = ConvertBookLineToRecord(line, "#///#");
			vBookInfo.push_back(stBookInfo);
		}
		fBookFile.close();
	}

	return vBookInfo;
}

vector <stUsersInfo> LoadUserDataFromFile(string FileName)
{
	vector <stUsersInfo> vUserInfo;
	fstream fUserFile;

	fUserFile.open(FileName, ios::in);
	if (fUserFile.is_open())
	{
		string line;
		stUsersInfo stUserInfo;

		while (getline(fUserFile, line))
		{
			stUserInfo = ConvertUserLineToRecord(line, "#///#");
			vUserInfo.push_back(stUserInfo);
		}
		fUserFile.close();
	}

	return vUserInfo;
}

bool FindBookByISBN(string ISBN, vector <stBookData>& vClients, stBookData& stClient)
{
	vClients = LoadDataFromFile(BookFileName);
	for (stBookData& book : vClients)
	{
		if (book.ISBN == ISBN)
		{
			stClient = book;
			return true;
		}
	}

	return false;
}

bool FindUserByUsername(string Username, vector <stUsersInfo>& vUsers, stUsersInfo& stUser)
{
	vUsers = LoadUserDataFromFile(UserFileName);
	for (stUsersInfo& user : vUsers)
	{
		if (user.Username == Username)
		{
			stUser = user;
			return true;
		}
	}

	return false;
}

void PrintUsersList()
{
	vector <stUsersInfo> vUsers = LoadUserDataFromFile(UserFileName);
	cout << "\n\n_______________________________________________________________________________________________________\n";
	cout << "\t\t                                   Users List                     " << endl;
	cout << "_______________________________________________________________________________________________________\n";

	if (vUsers.size() == 0)
	
		cout << "\n\t\t\t\t\t [NO Users in System.]\n";

	else
	{
		cout << left << setw(20) << "Username";
		cout << left << setw(20) << "Password";
		cout << left << setw(20) << "Permission";
		cout << "\n______________________________________________________________________________________________________\n";

		for (stUsersInfo& user : vUsers)
		{
			cout << left << setw(22) << user.Username;
			cout << left << setw(22) << user.Password;
			cout << left << setw(22) << user.Permission << endl;
		
		}
	}
	cout << "\n\n_______________________________________________________________________________________________________\n";
	cout << "\n*There are [" << vUsers.size() << "] user(s) in the system.\n";

}

void PrintBooksList()
{
	if (!CheckAccessPermission(enPermissionManagement::pViewBooksList))
		ShowAccessDeniedScreen();
	vector <stBookData> vBook = LoadDataFromFile(BookFileName);
	cout << "\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\t\t\t\t\t\tBooks List" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

	if (vBook.size() == 0)

		cout << "\n\t\t\t\t\t [NO Books Available in System.]\n";

	else
	{
		cout << left << setw(40) << "Book Name";
		cout << left << setw(20) << "Author";
		cout << left << setw(15) << "Genre";
		cout << left << setw(15) << "Language";
		cout << left << setw(15) << "Publish Year";
		cout << left << setw(15) << "ISBN" << endl;
		cout << "_______________________________________________________________________________________________________________________\n";

		for (stBookData& Book : vBook)
		{
			cout << left << setw(40) << Book.BookName;
			cout << left << setw(20) << Book.BookAuthorName;
			cout << left << setw(15) << Book.Genre;
			cout << left << setw(15) << Book.BookLanguage;
			cout << left << setw(15) << Book.PublishYear;
			cout << left << setw(15) << Book.ISBN << endl;
		}
	}
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "\n*There are [" << vBook.size() << "] books in the system.\n";

}


bool IsISBNExisted(string ISBN)
{
	vector <stBookData> vBookInfo = LoadDataFromFile(BookFileName);
	for (stBookData& Book : vBookInfo)
	{
		if (Book.ISBN == ISBN)
		{
			
			return true;
		}
		
	}
	return false;
}
bool IsUsernameExisted(string Username)
{
	vector <stUsersInfo> vUsers = LoadUserDataFromFile(UserFileName);
	for (stUsersInfo& Us : vUsers)
	{
		if (Us.Username == Username)
		{

			return true;
		}

	}
	return false;
}

void AddNewBookToSystem()
{
	stBookData stBookIfo;
	char Answer2 = 'N';
	
	    stBookIfo = ReadBookInfo();
		cout << "\nAre You Sure You Want To Save This Book In The System? y/n: ";
		cin >> Answer2;
		if (toupper(Answer2) == 'Y')
		{
			
			SaveBookInfoToFile(BookFileName, stBookIfo);
			cout << "\nBook Saved Successfully.";
			
		}
}

void ShowAddNewBookscreen()
{
	if (!CheckAccessPermission(enPermissionManagement::pAddNewBook))
		ShowAccessDeniedScreen();
	else
	{
		cout << "\n---------------------------------------------------------------------------\n";
		cout << "\n--------------------------[Add New Book Screen]----------------------------\n";
		cout << "\n---------------------------------------------------------------------------\n";

		char AddMore = 'N';


		do
		{
			AddNewBookToSystem();
			cout << "\nDo Want To Add More Books ? y / n : ";
			cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}
}

void AddNewUserToSystem()
{
	stUsersInfo stUserInfo;
	char Answer2 = 'N';

	stUserInfo = ReadNewUserInfo();
	cout << "\nAre You Sure You Want To Add This User To The System? y/n: ";
	cin >> Answer2;
	if (toupper(Answer2) == 'Y')
	{

		SaveUserInfoToFile(UserFileName, stUserInfo);
		cout << "\User Added Successfully.";

	}
}

void ShowAddNewUserscreen()
{
	cout << "\n---------------------------------------------------------------------------\n";
	cout << "\n--------------------------[Add New User Screen]----------------------------\n";
	cout << "\n---------------------------------------------------------------------------\n";

	char AddMore = 'N';


	do
	{
		AddNewUserToSystem();
		cout << "\nDo Want To Add More Users? y / n : ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

void ShowEndOfProgScreen()
{
	system("cls");
	cout << "=====================================\n\n";
	cout << "Log out Screen\n\n";
	cout << "=====================================\n\n";
}

bool FindBookInSystem(string ISBN)
{
	 
	vector <stBookData> vBookInfo = LoadDataFromFile(BookFileName);

	for (stBookData& Book : vBookInfo)
	{
		if (Book.ISBN == ISBN)
		{
			PrintBookInfo(Book);
			return true;
		}
	}
	return false;
}

bool FindUsersInSystem(string Username)
{

	vector <stUsersInfo> vUserInfo = LoadUserDataFromFile(UserFileName);

	for (stUsersInfo& user : vUserInfo)
	{
		if (user.Username == Username)
		{
			PrintUserInfo(user);
			return true;
		}
	}
	return false;
}

void ShowFindUserInSysScreen()
{
	cout << "=====================================\n\n";
	cout << "-----------{Find User Screen}--------\n\n";
	cout << "=====================================\n\n";

	string Username = ReadUserString("Enter Username to find user in system: ");
	if (!FindUsersInSystem(Username))
	{
		cout << "User with Username [" << Username << "] is NOT found.\n";
	}
}

void ShowFindBookInSysScreen()
{
	if (!CheckAccessPermission(enPermissionManagement::pFindBook))
		ShowAccessDeniedScreen();
	else
	{
		cout << "=====================================\n\n";
		cout << "-----------{Find Book Screen}--------\n\n";
		cout << "=====================================\n\n";

		string ISBN = ReadUserString("Enter ISBN to find book: ");
		if (!FindUsersInSystem(ISBN))
		{
			cout << "Book with ISBN [" << ISBN << "] is NOT found.\n";
		}
	}
}

bool FlagBookToDelete(string ISBN, vector <stBookData> &vBookInfo)
{
	for (stBookData& Book : vBookInfo)
	{
		if (Book.ISBN == ISBN)
		{
			Book.MarkForDeletion = true;
			return true;
		}
	}
	return false;
}

bool FlagUserToDelete(string Username, vector <stUsersInfo>& vUsersInfo)
{
	for (stUsersInfo& user : vUsersInfo)
	{
		if (user.Username == Username)
		{
			user.MarkForDeletion = true;
			return true;
		}
	}
	return false;
}

bool DeleteBookFromSystem(string ISBN)
{
	
	vector <stBookData> vBookInfo = LoadDataFromFile(BookFileName);
	char Answer = 'N';
	
	while (!IsISBNExisted(ISBN))
	{
		cout << "\n\nThere is NO book with ISBN [" << ISBN << "] in the system.\n";
		cout << "Try another one: ";
		cin >> ISBN;
	}
	
		for (stBookData& book : vBookInfo)
		{
			
			if (book.ISBN == ISBN)
			{
				PrintBookInfo(book);
				cout << "Are You Sure You Want To Delete This Book? Answer [y/n]:  ";
				cin >> Answer;
				if (toupper(Answer) == 'Y')
				{
					FlagBookToDelete(ISBN, vBookInfo);
					SaveNewFileContent(BookFileName, vBookInfo);
					vBookInfo = LoadDataFromFile(BookFileName);
					cout << "The Book With [" << ISBN << "] Deleted Successfully";
					return true;
				}

			}
		}
	return false;
}

bool DeleteUserFromSystem(string Username)
{

	vector <stUsersInfo> vUsersInfo = LoadUserDataFromFile(UserFileName);
	char Answer = 'N';

	while (!IsUsernameExisted(Username))
	{
		cout << "\n\nThere is NO user with Username [" << Username << "] in the system.\n";
		cout << "Try another one: ";
		cin >> Username;
	}

	for (stUsersInfo& user : vUsersInfo)
	{

		if (user.Username == Username)
		{
			PrintUserInfo(user);
			cout << "Are You Sure You Want To Delete This User? Answer [y/n]:  ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				FlagUserToDelete(Username, vUsersInfo);
				SaveNewUserFileContent(UserFileName, vUsersInfo);
				vUsersInfo = LoadUserDataFromFile(UserFileName);
				cout << "User With [" << Username << "] Deleted Successfully";
				return true;
			}

		}
	}
	return false;
}


void ShowDeleteBookFromSysScreen()
{
	if (!CheckAccessPermission(enPermissionManagement::pDeleteBook))
		ShowAccessDeniedScreen();
	else
	{
		cout << "\n---------------------------------------------------------------------------\n";
		cout << "\n--------------------------[Delete Book Screen]----------------------------\n";
		cout << "\n---------------------------------------------------------------------------\n";

		char AddMore = 'N';


		do
		{
			DeleteBookFromSystem(ReadUserString("Enter ISBN: "));
			cout << "\n\nDo you want to delete more books? y/n: ";
			cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}
}

void ShowDeleteUserFromSysScreen()
{
	cout << "\n---------------------------------------------------------------------------\n";
	cout << "\n--------------------------[Delete User Screen]----------------------------\n";
	cout << "\n---------------------------------------------------------------------------\n";

	char AddMore = 'N';


	do
	{
		DeleteUserFromSystem(ReadUserString("Enter Username: "));
		cout << "\n\nDo you want to delete more users? y/n: ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

bool UpdateBookInfoInFile(string ISBN, vector <stBookData>& vBookInfo)
{
	char Answer = 'N';
	stBookData stBookInfo;
	if (FindBookByISBN(ISBN, vBookInfo, stBookInfo))
	{
		PrintBookInfo(stBookInfo);
		cout << "\nAre yoyu sure you want to update this book's information? y/n: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{

			for (stBookData& book : vBookInfo)
			{
				if (book.ISBN == ISBN)
				{
					book = UpdateBookInfoByISBN(ISBN);
					break;
				}
			}
		}
		SaveNewFileContent(BookFileName, vBookInfo);
		cout << "\nBook Updated Successfully.\n";
		return true;
	}
	else
	{
		cout << "\nBook with ISBN [" << ISBN << "] in NOT found in system.\n";
		cout << "Try another one: ";
		cin >> ISBN;
		UpdateBookInfoInFile(ISBN, vBookInfo);
	}
	return false;
}

bool UpdateUserInfoInFile(string Username, vector <stUsersInfo>& vUserInfo)
{
	char Answer = 'N';
	stUsersInfo stUserInfo;
	if (FindUserByUsername(Username, vUserInfo, stUserInfo))
	{
		PrintUserInfo(stUserInfo);
		cout << "\nAre yoyu sure you want to update this user information? y/n: ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{

			for (stUsersInfo& user : vUserInfo)
			{
				if (user.Username == Username)
				{
					user = UpdateUserInfoByUsername(Username);
					break;
				}
			}
		}
		SaveNewUserFileContent(UserFileName, vUserInfo);
		cout << "\nUser Updated Successfully.\n";
		return true;
	}
	else
	{
		cout << "\nBook with ISBN [" << Username << "] in NOT found in system.\n";
		cout << "Try another one: ";
		cin >> Username;
		UpdateUserInfoInFile(Username, vUserInfo);
	}
	return false;
}

void ShowUpdateuserkInSysScreen()
{

	cout << "\n---------------------------------------------------------------------------\n";
	cout << "\n------------------------[Update User Infomation Screen]--------------------\n";
	cout << "\n---------------------------------------------------------------------------\n";

	char AddMore = 'N';

	vector <stUsersInfo> vUsers = LoadUserDataFromFile(UserFileName);
	do
	{
		UpdateUserInfoInFile(ReadUserString("Enter Username: "), vUsers);
		cout << "\n\nDo you want to update more users informayion? y/n: ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}


void ShowUpdateBookInSysScreen()
{
	if (!CheckAccessPermission(enPermissionManagement::pUpdateBookInfo))
		ShowAccessDeniedScreen();
	else
	{
		cout << "\n---------------------------------------------------------------------------\n";
		cout << "\n--------------------------[Update Book Screen]----------------------------\n";
		cout << "\n---------------------------------------------------------------------------\n";

		char AddMore = 'N';

		vector <stBookData>vBook = LoadDataFromFile(BookFileName);
		do
		{
			UpdateBookInfoInFile(ReadUserString("Enter ISBN: "), vBook);
			cout << "\n\nDo you want to update more books? y/n: ";
			cin >> AddMore;
		} while (toupper(AddMore) == 'Y');
	}
}

void PerformUserManagement(enUserManagement AdminChoise)
{
	switch (AdminChoise)
	{
	case enUserManagement::ViewUsersList:
	{
		system("cls");
		PrintUsersList();
		GoBackToUserManagemenMenu();
		break;
	}
	case enUserManagement::AddNewUser:
	{
		system("cls");
		ShowAddNewUserscreen();
		GoBackToUserManagemenMenu();
		break;
	}

	case enUserManagement::DeleteUser:
	{
		system("cls");
		ShowDeleteUserFromSysScreen();
		GoBackToUserManagemenMenu();
		break;
	}

	case enUserManagement::UpdateUser:
	{
		system("cls");
		ShowUpdateuserkInSysScreen();
		GoBackToUserManagemenMenu();
		break;
	}

	case enUserManagement::FindUser:
	{
		system("cls");
		ShowFindUserInSysScreen();
		GoBackToUserManagemenMenu();
		break;
	}

	case enUserManagement::BackToMenu:
	{
		PrintMainMenu();
		break;
	}

	}
}

void RunLibrarySystem(enMenuchoices UserChoice)
{
	switch (UserChoice)
	{
	case enMenuchoices::ViewBooksList:
	{
		system("cls");
		PrintBooksList();
		GoBackToMainScreen();
		break;
	}
	case enMenuchoices::AddNewBook:
	{
		system("cls");
		ShowAddNewBookscreen();
		GoBackToMainScreen();
		break;
	}
	case enMenuchoices::DeleteBook:
	{
		system("cls");
		ShowDeleteBookFromSysScreen();
		GoBackToMainScreen();
		break;
	}
	case enMenuchoices::UpdateBookInfo:
	{
		system("cls");
		ShowUpdateBookInSysScreen();
		GoBackToMainScreen();
		break;

	}
	case enMenuchoices::FindBook:
	{
		system("cls");
		ShowFindBookInSysScreen();
		system("pause>0");
		GoBackToMainScreen();
		break;
	}

	case enMenuchoices::UserManagement:
	{
		system("cls");
		PrintUserManagementMenu();
		system("pause>0");
		GoBackToMainScreen();
		break;
	}

	case enMenuchoices::Logout:
	{
		system("cls");
		ShowEndOfProgScreen();
		break;

	}

	}
}

void Login()
{
	bool LoginFaild = false;
	string Password, Username;
	do
	{
		system("cls");
		cout << "\n--------------------------------------------------------------------------------------\n";
		cout << "\n-----------------------               Log In Screen                 ------------------\n";
		cout << "\n--------------------------------------------------------------------------------------\n";

		if (LoginFaild)
			cout << "Invalid Passord/Username.\nTry Again...\n";

		cout << "Enter Username: ";
		cin >> Username;
		cout << "Enter Password: ";
		cin >> Password;

		LoginFaild = !LoadUserInfoByUsernameAndPassword(Username, Password);
	} while (LoginFaild);
	PrintMainMenu();
}

int main()
{
	Login();
	
	return 0;
}


