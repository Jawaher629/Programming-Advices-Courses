// I Made this project to aply what I have learned from course 7.
// It is a library system that add,save,delete, update, and show books in library.
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

enum enMenuchoices{ViewBooksList = 1, AddNewBook = 2 , DeleteBook = 3, UpdateBookInfo = 4,FindBook = 5, Exit = 6};
const string BookFileName = "BookFile2.txt";

void PrintMainMenu();
void RunLibrarySystem(enMenuchoices UserChoice);
bool IsISBNExisted(string ISBN);

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

void PrintMainMenu()
{
	cout << "\n ===================================================================================================\n";
	cout << "\t\t\t\t\t Library System Management ";
	cout << "\n ===================================================================================================\n";

	cout << "\t[1] View Books List.\n";
	cout << "\t[2] Add New Book.\n";
	cout << "\t[3] Delete Book.\n";
	cout << "\t[4] Update Book Information.\n";
	cout << "\t[5] Find Book.\n";
	cout << "\t[6] Exit.\n";
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
string ConvertBookRecordToLine(stBookData &stBookInfo , string Separator)
{
	string InfoLine = "";
	
	InfoLine += stBookInfo.BookName + Separator + stBookInfo.BookAuthorName + Separator + stBookInfo.Genre + Separator + stBookInfo.BookLanguage + Separator + to_string(stBookInfo.PublishYear) + Separator + stBookInfo.ISBN;
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

void PrintBooksList()
{
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
	cout << "\n---------------------------------------------------------------------------\n";
	cout << "\n--------------------------[Add New Book Screen]----------------------------\n";
	cout << "\n---------------------------------------------------------------------------\n";

	char AddMore = 'N';

	
		do
		{
			AddNewBookToSystem();
			cout << "\nDo Want To Add More Books ? y / n : ";
			cin >> AddMore;
	    }while (toupper(AddMore) == 'Y');
}

void ShowEndOfProgScreen()
{
	system("cls");
	cout << "=====================================\n\n";
	cout << "End Of Program Screen\n\n";
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


void ShowFindBookInSysScreen()
{
	cout << "=====================================\n\n";
	cout << "-----------{Find Book Screen}--------\n\n";
	cout << "=====================================\n\n";

	string ISBN = ReadUserString("Enter ISBN to find book: ");
	if (!FindBookInSystem(ISBN))
	{
		cout << "Book with ISBN [" << ISBN << "] is NOT found.\n";
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

void ShowDeleteBookFromSysScreen()
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

void ShowUpdateBookFromSysScreen()
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

void RunLibrarySystem(enMenuchoices UserChouce)
{
	switch (UserChouce)
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
		ShowUpdateBookFromSysScreen();
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
	case enMenuchoices::Exit:
	{
		system("cls");
		ShowEndOfProgScreen();
		break;

	}

	}
}

int main()
{
	PrintMainMenu();
	
	system("pause>0");
	return 0;
}

