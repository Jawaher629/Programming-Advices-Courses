//My solution:
#include <iostream>
#include <string>
using namespace std;
struct stDate {
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
 int DaysInMonth(int Year, int Month)
 {
	 if (Month < 1 || Month > 12)
		 return 0;

	 if (Month == 2)
		 return (IsLeapYear(Year) ? 29 : 28);


	 return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

 }

 bool IsLastDayInMonth(stDate Date)
 {
	 int DaysIMonth = DaysInMonth(Date.Year, Date.Month);
	 return (Date.Day == DaysIMonth);
}

 bool IsLastMonthInYear(stDate Date)
 {
	 return (Date.Month == 12);
 }

 stDate IncreaseDateByOneDay(stDate Date)
 {
	 if (IsLastDayInMonth(Date) &&  IsLastMonthInYear(Date))
	 {
		 Date.Day = 1;
		 Date.Month = 1;
		 Date.Year++;
	 }
	 else if (IsLastDayInMonth(Date))
	 {
		 Date.Day = 1;
		 Date.Month++;
	 }
	 else
		 Date.Day++;
	 return Date;
 }

 stDate ReadFullDate()
 {
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }

int main()
{
	stDate Date1 = ReadFullDate();

	Date1 = IncreaseDateByOneDay(Date1);

	cout << "- Date after increase it by one day is: ";
	cout << "[" << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "]\n";

	system("pause>0");
	return 0;
} 
//-----------------------------------------------------------------------------------------------------------------------
// Dr. Abu Hadhoud solution:
#include <iostream>
#include <string>
using namespace std;
struct stDate {
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
 int DaysInMonth(int Year, int Month)
 {
	 if (Month < 1 || Month > 12)
		 return 0;

	 if (Month == 2)
		 return (IsLeapYear(Year) ? 29 : 28);


	 return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

 }

 bool IsLastDayInMonth(stDate Date)
 {
	 int DaysIMonth = DaysInMonth(Date.Year, Date.Month);
	 return (Date.Day == DaysIMonth);
}

 bool IsLastMonthInYear(stDate Date)
 {
	 return (Date.Month == 12);
 }

 stDate IncreaseDateByOneDay(stDate Date)
 {
	 if (IsLastDayInMonth(Date))
	 {
		 if(IsLastMonthInYear(Date))
		 {
			 Date.Day = 1;
			 Date.Month = 1;
			 Date.Year++;
		 }
		 else
		 {
			 Date.Day = 1;
			 Date.Month++;
		 }
	 }
	 else
		 Date.Day++;
	 return Date;
 }

 stDate ReadFullDate()
 {
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }
  
int main()
{
	stDate Date1 = ReadFullDate();

	Date1 = IncreaseDateByOneDay(Date1);

	cout << "- Date after increase it by one day is: \n";
	cout << "[" << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "]\n";

	system("pause>0");
	return 0;
} 
