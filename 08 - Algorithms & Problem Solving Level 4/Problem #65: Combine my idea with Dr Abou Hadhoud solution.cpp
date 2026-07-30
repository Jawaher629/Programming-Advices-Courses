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

enum enDateFormat { FormatOne = 1, FormatTwo = 2, FormatThree = 3, FormatFour = 4, FormatFive = 5 , FormatSix = 6, FormatSeven = 7};

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
	if (UserChoise == 6)
		return enDateFormat::FormatSix;
	if (UserChoise == 7)
		return enDateFormat::FormatSeven;

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

 string ReplaceWordsInAString(string Sent1, string ToReplace, string TheReplacement)
 {
	 short pos = Sent1.find(ToReplace);

	 while (pos != std::string::npos)
	 {
		 Sent1 = Sent1.replace(pos, ToReplace.length(), TheReplacement);

		 pos = Sent1.find(ToReplace);
	 }

	 return Sent1;
 }

 string DateFormat(stDate Date, string DateFormat = "dd/mm/yyyy")
 {
	 string FormattedDate = "";

	 FormattedDate = ReplaceWordsInAString(DateFormat,"dd", to_string(Date.Day));
	 FormattedDate = ReplaceWordsInAString(FormattedDate,"mm", to_string(Date.Month));
	 FormattedDate = ReplaceWordsInAString(FormattedDate,"yyyy", to_string(Date.Year));

	 return FormattedDate;
 }

 short ReadIntFromUser(string Message)
 {
	 short Num = 0;
	 cout << Message << endl;
	 cin >> Num;
	 return Num;
 }

 string DateFormatByUserChoice(enDateFormat enUserChois, stDate Date)
 {
	 string DateFormatted = "";

	 if (enUserChois == enDateFormat::FormatOne)
		 DateFormatted = DateFormat(Date, "yyyy/mm/dd");
	 if (enUserChois == enDateFormat::FormatTwo)
		 DateFormatted = DateFormat(Date, "mm/dd/yyyy");
	 if (enUserChois == enDateFormat::FormatThree)
		 DateFormatted = DateFormat(Date, "dd-mm-yyyy");
	 if (enUserChois == enDateFormat::FormatFour)
		 DateFormatted = DateFormat(Date, "mm-dd-yyyy");
	 if (enUserChois == enDateFormat::FormatFive)
		 DateFormatted = DateFormat(Date, "yyyy-dd-mm");
	 if (enUserChois == enDateFormat::FormatSix)
		 DateFormatted = DateFormat(Date, "yyyy-mm-dd");
	 if (enUserChois == enDateFormat::FormatSeven)
		 DateFormatted = DateFormat(Date, "\nDay: dd\nMonth: mm\nYear: yyyy");
	 return DateFormatted;
 }

int main()
{
	string StringDate = ReadDateStringFromUer("Enter date in form dd/mm/yyyy: ");
	stDate Date = StringDateToNumber(StringDate);
	enDateFormat UserCoise = TakeUserFormatChoise(ReadIntFromUser("Enter your choise for date format you want:\n1)yyyy/mm/dd\n2)mm/dd/yyyy\n3)dd-mm-yyyy\n4)mm-dd-yyyy\n5)yyyy-dd-mm\n6)yyyy-mm-dd\n7)Day: dd\nMonth: mm\nYear: yyyy\n"));

	cout << "\nPrint date in format you choose: " << DateFormatByUserChoice(UserCoise, Date);

	system("pause>0");
	return 0;
} 
