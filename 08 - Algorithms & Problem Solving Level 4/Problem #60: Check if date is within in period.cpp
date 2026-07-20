//My solution:
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
};

struct stPeriod
{
	stDate PeriodStarts;
	stDate PeriodEnds;
};

enum enCompareDates { Equal = 0, After = 1, Before = -1 };

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

 bool IsDay1BeforDay2(stDate Date1, stDate Date2)
 {
	 return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false);
 }

 bool IsDay1EqualToDay2(stDate Date1, stDate Date2)
 {
	 return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
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

 bool IsDate1AfterDate2(stDate Date1, stDate Date2)
 {
	 return (!IsDay1BeforDay2(Date1, Date2)) && !IsDay1EqualToDay2(Date1,Date2);
 }

 enCompareDates CompareDatesFunc(stDate Date1, stDate Date2)
 {
	 if (IsDay1EqualToDay2(Date1, Date2))
		return enCompareDates::Equal;
	 else if(IsDate1AfterDate2 (Date1,Date2))
		return enCompareDates::After;
	 else
		return enCompareDates::Before;
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


 stPeriod TakePeriodFromUser()
 {
	 stPeriod Period;

	 Period.PeriodStarts = ReadFullDate("Enter Period's start date/\n");
	 Period.PeriodEnds = ReadFullDate("Enter Period's end date/\n");

	 return Period;
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

 short DiffInDays(stDate& Date1, stDate& Date2, bool IncludeLastDate = false)
 {
	 short Counter = 0;
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }

	 return (IncludeLastDate ? ++Counter : Counter);
 }


 bool IsDateWithinPeriod(stPeriod Period, stDate Date)
 {
	 return ((CompareDatesFunc(Date, Period.PeriodStarts) == enCompareDates::After) && (CompareDatesFunc(Date, Period.PeriodEnds) == enCompareDates::Before));
 }

int main()
{
	stPeriod Period = TakePeriodFromUser();
	stDate Date = ReadFullDate("Enter the date: \n");

	if (IsDateWithinPeriod(Period, Date))
		cout << "Yes, Date is wition the period.\n";
	else
		cout << "No, Date is NOT within the period.\n";

	system("pause>0");
	return 0;
} 
//--------------------------------------------------------------------------------------------
//Dr.Abu Hadhoud solution:
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

struct stDate
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
};

struct stPeriod
{
	stDate PeriodStarts;
	stDate PeriodEnds;
};

enum enCompareDates { Equal = 0, After = 1, Before = -1 };

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

 bool IsDay1BeforDay2(stDate Date1, stDate Date2)
 {
	 return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false);
 }

 bool IsDay1EqualToDay2(stDate Date1, stDate Date2)
 {
	 return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
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

 bool IsDate1AfterDate2(stDate Date1, stDate Date2)
 {
	 return (!IsDay1BeforDay2(Date1, Date2)) && !IsDay1EqualToDay2(Date1,Date2);
 }

 enCompareDates CompareDatesFunc(stDate Date1, stDate Date2)
 {
	 if (IsDay1EqualToDay2(Date1, Date2))
		return enCompareDates::Equal;
	 else if(IsDate1AfterDate2 (Date1,Date2))
		return enCompareDates::After;
	 else
		return enCompareDates::Before;
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


 stPeriod TakePeriodFromUser()
 {
	 stPeriod Period;

	 Period.PeriodStarts = ReadFullDate("Enter Period's start date/\n");
	 Period.PeriodEnds = ReadFullDate("Enter Period's end date/\n");

	 return Period;
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

 short DiffInDays(stDate& Date1, stDate& Date2, bool IncludeLastDate = false)
 {
	 short Counter = 0;
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }

	 return (IncludeLastDate ? ++Counter : Counter);
 }


 bool IsDateWithinPeriod(stPeriod Period, stDate Date)
 {
	 return !((CompareDatesFunc(Date, Period.PeriodStarts) == enCompareDates::Before)
		 || (CompareDatesFunc(Date, Period.PeriodEnds) == enCompareDates::After));
 }

int main()
{
	stPeriod Period = TakePeriodFromUser();
	stDate Date = ReadFullDate("Enter the date: \n");

	if (IsDateWithinPeriod(Period, Date))
		cout << "Yes, Date is wition the period.\n";
	else
		cout << "No, Date is NOT within the period.\n";

	system("pause>0");
	return 0;
} 
