//My solution : use enums to take user's format choise
#include <iostream>
#include <string>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
};

enum enDateFormat {FormatOne = 1 , FormatTwo = 2 , FormatThree = 3 , FormatFour = 4, FormatFive = 5};
 
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

 string ReadDateStringFromUer(string Message)
 {
	 cout << Message;
	 string DateString = "";
	 getline(cin >> ws, DateString);

	 return DateString;
 }

 stDate StringDateToNumber(string StringDate)
 {
	 stDate Date;
	 vector <string> vecDate = SplitString(StringDate, "/");

	 Date.Day = stoi(vecDate[0]);
	 Date.Month = stoi(vecDate[1]);
	 Date.Year = stoi(vecDate[2]);

	 return Date;
 }

 string NumberDateToString(stDate Date)
 {
	 return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
 }

 enDateFormat TakeUserFormatChoise(short UserChoise = 0)
 {
	 if (UserChoise == 1)
		 return enDateFormat::FormatOne;
	 if (UserChoise == 2)
		 return enDateFormat::FormatTwo;
	 if (UserChoise == 3)
		 return enDateFormat::FormatThree;
	 if (UserChoise == 4)
		 return enDateFormat::FormatFour;
	 if (UserChoise == 5)
		 return enDateFormat::FormatFive;

 }

 string DateFormat(enDateFormat enUserChois, stDate Date)
 {
	 string DateFormat = "";

	 if (enUserChois == enDateFormat::FormatOne)
		  DateFormat += to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	 if (enUserChois == enDateFormat::FormatTwo)
		  DateFormat += to_string(Date.Month) + "/" + to_string(Date.Day) + "/" + to_string(Date.Year);
	 if (enUserChois == enDateFormat::FormatThree)
		  DateFormat += to_string(Date.Year) + "/" + to_string(Date.Month) + "/" + to_string(Date.Day);
	 if (enUserChois == enDateFormat::FormatFour)
		  DateFormat += to_string(Date.Day) + "-" + to_string(Date.Month) + "-" + to_string(Date.Year);
	 if (enUserChois == enDateFormat::FormatFive)
		  DateFormat += to_string(Date.Month) + "-" + to_string(Date.Day) + "-" + to_string(Date.Year);
	 return DateFormat;
 }

 short ReadIntFromUser(string Message)
 {
	 short Num = 0;
	 cout << Message << endl;
	 cin >> Num;
	 return Num;
 }

int main()
{
	string StringDate = ReadDateStringFromUer("Enter date in form dd/mm/yyyy: ");
	enDateFormat UserCoise = TakeUserFormatChoise(ReadIntFromUser("Enter your choise for date format you want:\n1)dd/mm/yyyy\n2)mm/dd/yyyy\n3)yyyy/mm/dd\n4)dd-mm-yyyy\n5)mm-dd-yyyy\n"));
	
	stDate Date = StringDateToNumber(StringDate);
	cout << "- Format you choose: " << DateFormat(UserCoise, Date);
	
	system("pause>0");
	return 0;
} 

//--------------------------------------------------------------------------------------------------------
//Dr Abo Hadhoud solution
