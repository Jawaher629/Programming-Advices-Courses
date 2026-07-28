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

int main()
{
	string StringDate = ReadDateStringFromUer("Enter date in form dd/mm/yyyy: ");
	stDate Date = StringDateToNumber(StringDate);
	string NumDateToString = NumberDateToString(Date);
	cout << "\n- Date in numbers:\n" << "- Day: " << Date.Day << endl<< "- Month: " << Date.Month << endl << "- Year: " << Date.Year << endl << endl;
	cout << "- Date in string: " << NumDateToString;
	system("pause>0");
	return 0;
} 
