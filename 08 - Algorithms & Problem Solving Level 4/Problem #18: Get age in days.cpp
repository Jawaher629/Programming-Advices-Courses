#pragma warning(disable : 4996)
#include <iostream>

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

 
 stDate ReadFullDate()
 {
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }
 bool IsDay1BeforDay2(stDate Date1, stDate Date2)
 {
	 return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false);
 }
 stDate IncreaseDateByOneDay(stDate Date)
 {
	 if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date))
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

 int DiffInDays(stDate &Date1, stDate &Date2, bool IncludeLastDate = false)
 {
	 int Counter = 0;
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }
	
	 return (IncludeLastDate ? ++Counter : Counter);
 }
  
 stDate GetSystemDate()
 {
	 stDate Date;
	 time_t Time = time(0);
	 tm* Now = localtime(&Time);

	 Date.Year = Now->tm_year + 1900;
	 Date.Month = Now->tm_mon + 1;
	 Date.Day = Now->tm_wday;

	 return Date;
 }
int main()
{
	cout << "Enter your birthday date: \n";
	stDate Date1 = ReadFullDate();
	stDate Date2 = GetSystemDate();
	

	cout << "- your age in days is: " << DiffInDays(Date1,Date2 ) << " Days." << endl;
	
	system("pause>0");
	return 0;
} 
