// My solution:
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
};

bool IsLeapYear(int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);
}

 short ReadUserNumber(string Message)
{
	 short num = 0;
	cout << Message;
	cin >> num;
	return num;
}
 
 stDate ReadFullDate(string Message)
 {
	 cout << Message;
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }

 int DaysInMonth(int Year, int Month)
 {
	 if (Month < 1 || Month > 12)
		 return 0;

	 if (Month == 2)
		 return (IsLeapYear(Year) ? 29 : 28);


	 return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

 }
 
 bool IsValidDate(stDate Date)
 {
	 return ((Date.Month >= 1 && Date.Month <= 12) && (Date.Day >= 1 && Date.Day <= DaysInMonth(Date.Year,Date.Month)));
 }

int main()
{
	stDate Date = ReadFullDate("Enter the date:-\n\n");

	if (IsValidDate(Date))
		cout << "Yes, it's a VALID date.\n";
	else
		cout << "No, Date is NOT valid.\n";

	system("pause>0");
	return 0;
} 
//---------------------------------------------------------------------------------------------------------
//Dr. Abu Hadhoud Solution:
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
};

bool IsLeapYear(int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);
}

 short ReadUserNumber(string Message)
{
	 short num = 0;
	cout << Message;
	cin >> num;
	return num;
}
 
 stDate ReadFullDate(string Message)
 {
	 cout << Message;
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }

 int DaysInMonth(int Year, int Month)
 {
	 if (Month < 1 || Month > 12)
		 return 0;

	 if (Month == 2)
		 return (IsLeapYear(Year) ? 29 : 28);


	 return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

 }
 
 bool IsValidDate(stDate Date)
 {
	 if (Date.Day < 1 || Date.Day >31)
		 return false;
	 if (Date.Month < 1 || Date.Month >12)
		 return false;
	 if (Date.Month == 2)
	 {
		 if (IsLeapYear(Date.Year))
		 {
			 if (Date.Day > 29)
				 return false;
		 }
		 else
		 {
			 if (Date.Day > 28)
				 return false;
		 }
	 }
	 short DaysinMonth = DaysInMonth(Date.Year, Date.Month);
	 if (Date.Day > DaysinMonth)
		 return false;

	 return true;
 }

int main()
{
	stDate Date = ReadFullDate("Enter the date:-\n\n");

	if (IsValidDate(Date))
		cout << "Yes, it's a VALID date.\n";
	else
		cout << "No, Date is NOT valid.\n";

	system("pause>0");
	return 0;
} 
