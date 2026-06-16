// My solution:
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


 int DiffInDays(stDate Date1, stDate Date2, bool IncludeLastDate = false)
 {
	 
	 int Counter = 0;
	 if (!IsDay1BeforDay2(Date1,Date2))
	 {
		return (DiffInDays(Date2, Date1, false) * -1);
	 }
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }

	
	 return (IncludeLastDate ? ++Counter : Counter);
 }
  


int main()
{
	cout << "Enter the date 1: \n";
	stDate Date1 = ReadFullDate();
  cout << endl;
	cout << "Enter the date 2: \n";
	stDate Date2 = ReadFullDate();
	

	cout << "-The difference between two dates: " << DiffInDays(Date1,Date2 ) << " Days." << endl;
	
	system("pause>0");
	return 0;
} 
// -----------------------------------------------------------------------------------------------------------
// Dr. Abo Hadhoud solution:
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

 void SwapDates(stDate& Date1, stDate& Date2)
 {
	 stDate TempDate;
	 TempDate = Date1;

	 Date1 = Date2;

	 Date2 = TempDate;
 }

 int DiffInDays(stDate Date1, stDate Date2, bool IncludeLastDate = false)
 {
	 
	 int Counter = 0;
	 int SapFlagValue = 1;
	 if (!IsDay1BeforDay2(Date1,Date2))
	 {
		SwapDates(Date1,Date2);
		SapFlagValue = - 1;
		
	 }
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }

	
	 return (IncludeLastDate ? ++Counter * SapFlagValue : Counter * SapFlagValue);
 }
  


int main()
{
	cout << "Enter the date 1: \n";
	stDate Date1 = ReadFullDate();
	cout << endl;
	cout << "Enter the date 2: \n";
	stDate Date2 = ReadFullDate();


	cout << "-The difference between two dates: " << DiffInDays(Date1, Date2) << " Days." << endl;

	system("pause>0");
	return 0;
} 
