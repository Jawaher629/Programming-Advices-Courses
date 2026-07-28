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

 short PeriodLengthInDays(stPeriod Period)
 {
	 return  DiffInDays(Period.PeriodStarts, Period.PeriodEnds);
 }

 bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
 {
	 return (CompareDatesFunc(Period2.PeriodEnds, Period1.PeriodStarts) == enCompareDates::Before || CompareDatesFunc(Period2.PeriodStarts, Period1.PeriodEnds) == enCompareDates::After) ? false : true;
 }

 short CountOverLapPeriodsDays(stPeriod Period1, stPeriod Period2)
 {
	 stPeriod OverLapPeriod;
	 OverLapPeriod.PeriodStarts = IsDay1BeforDay2(Period1.PeriodStarts, Period2.PeriodStarts) ? Period2.PeriodStarts: Period1.PeriodStarts;

	 OverLapPeriod.PeriodEnds = IsDay1BeforDay2(Period1.PeriodEnds, Period2.PeriodEnds)? Period1.PeriodEnds: Period2.PeriodEnds;

	 return PeriodLengthInDays(OverLapPeriod);
 }

int main()
{
	cout << "\n- Enter first period:-\n\n";
	stPeriod Period1 = TakePeriodFromUser();
	cout << "\n\n- Enter second period:-\n\n";
	stPeriod  Period2 = TakePeriodFromUser();

	short OverLapPeriodCount = CountOverLapPeriodsDays(Period1, Period2);

	if (OverLapPeriodCount!= 0)
		cout << "Period overlap is (" << OverLapPeriodCount << ") days.\n";
	else
		cout << "There is no overlap between the two periods\n";

	system("pause>0");
	return 0;
} 
//---------------------------------------------------------------------------------------------------------

// Dr. Abu Hadhoud solution: Compare longest period with the shorter one
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

 short PeriodLengthInDays(stPeriod Period)
 {
	 return  DiffInDays(Period.PeriodStarts, Period.PeriodEnds);
 }

 bool IsOverLapPeriods(stPeriod Period1, stPeriod Period2)
 {
	 return (CompareDatesFunc(Period2.PeriodEnds, Period1.PeriodStarts) == enCompareDates::Before || CompareDatesFunc(Period2.PeriodStarts, Period1.PeriodEnds) == enCompareDates::After) ? false : true;
 }

 bool IsDateWithinPeriod(stPeriod Period, stDate Date)
 {
	 return !((CompareDatesFunc(Date, Period.PeriodStarts) == enCompareDates::Before)
		 || (CompareDatesFunc(Date, Period.PeriodEnds) == enCompareDates::After));
 }

 int CountOverLapPeriodsDays(stPeriod Period1, stPeriod Period2)
 {
	 int Period1Length = PeriodLengthInDays(Period1);
	 int Period2Length = PeriodLengthInDays(Period2);
	 int OverLapDaysCounter = 0;

	 if (!IsOverLapPeriods(Period1, Period2))
		 return 0;

	 if (Period1Length < Period2Length)
	 {
		 while (IsDay1BeforDay2(Period1.PeriodStarts, Period1.PeriodEnds))
		 {
			 if (IsDateWithinPeriod(Period2, Period1.PeriodStarts))
				 OverLapDaysCounter++;
			 Period1.PeriodStarts = IncreaseDateByOneDay(Period1.PeriodStarts);
		 }
	 }
	 else
	 {
		 while (IsDay1BeforDay2(Period2.PeriodStarts, Period2.PeriodEnds))
	 {
		 if (IsDateWithinPeriod(Period1, Period2.PeriodStarts))
			 OverLapDaysCounter++;
		 Period2.PeriodStarts = IncreaseDateByOneDay(Period2.PeriodStarts);
	 }
	 }

	 return OverLapDaysCounter;
 }

int main()
{
	cout << "\n- Enter first period:-\n\n";
	stPeriod Period1 = TakePeriodFromUser();
	cout << "\n\n- Enter second period:-\n\n";
	stPeriod  Period2 = TakePeriodFromUser();

	short OverLapPeriodCount = CountOverLapPeriodsDays(Period1, Period2);

	if (OverLapPeriodCount!= 0)
		cout << "Period overlap is (" << OverLapPeriodCount << ") days.\n";
	else
		cout << "There is no overlap between the two periods\n";

	system("pause>0");
	return 0;
} 
