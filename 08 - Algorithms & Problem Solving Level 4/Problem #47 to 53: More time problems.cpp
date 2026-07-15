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

 string IndexToDayName(int DayIndex)
 {
	 string DayName[] = { "Sunday","Monday","Tuesday","Wendesday","Thuresday","Friday","Saturday" };
	 return DayName[DayIndex];
 }

 stDate GetSystemDate()
 {
	 stDate Date;
	 time_t Time = time(0);
	 tm* Now = localtime(&Time);

	 Date.Year = Now->tm_year + 1900;
	 Date.Month = Now->tm_mon + 1;
	 Date.Day = Now->tm_mday;

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

 int DiffInDays(stDate& Date1, stDate& Date2, bool IncludeLastDate = false)
 {
	 int Counter = 0;
	 while (IsDay1BeforDay2(Date1, Date2))
	 {
		 Counter++;
		 Date1 = IncreaseDateByOneDay(Date1);

	 }

	 return (IncludeLastDate ? ++Counter : Counter);
 }

 short GetDayIndexs(short Month, short Year, short Day)
 {
	 short a = (14 - Month) / 12;
	 short y = Year - a;
	 short m = Month - (12 * a) - 2;
	 return (Day + y + (y / 4) - (y / 100) + y / 400 + ((31 * m) / 12)) % 7;
 }

 short GetDayIndexs(stDate Date)
 {
	 return GetDayIndexs(Date.Month, Date.Year, Date.Day);
 }

 short IsItEndOfTheWeek(stDate Date)
 {
	 return GetDayIndexs(Date) == 6;
 }

 bool IsItWeekEnd(stDate Date)
 {
	 return (GetDayIndexs(Date) == 6 || GetDayIndexs(Date) == 5);
 }

 bool IsItBusinessDay(stDate Date)
 {
	 return !IsItWeekEnd(Date);
 }

 short DaysUntillTheEndOfTheWeek(stDate Date)
 {
	 return 6 - GetDayIndexs(Date);
 }

 short DaysUntillEndOfMonth(stDate Date)
 {
	 stDate EndOfMonth;
	 EndOfMonth.Day = DaysInMonth(Date.Year, Date.Month);
	 EndOfMonth.Month = Date.Month;
	 EndOfMonth.Year = Date.Year;

	 return DiffInDays(Date, EndOfMonth);

 }

 short DaysUntillEndOfYear(stDate Date)
 {
	 stDate EndOfMonth;
	 EndOfMonth.Day = 31;
	 EndOfMonth.Month = 12;
	 EndOfMonth.Year = Date.Year;

	 return DiffInDays(Date, EndOfMonth);

 }

 void PrintDateDetails()
 {
	 stDate Date1 = GetSystemDate();

	 cout << "\n Today is: " << IndexToDayName(GetDayIndexs(Date1)) << "," << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << ".";

	 cout << "\n- Is it end of the week?\n";
	 if (IsItEndOfTheWeek(Date1))
		 cout << "Yes, it's SaturDay, it's the end of the week.\n";
	 else
		 cout << "No, it's NOT the end of the week.\n";

	 cout << "\n- Is it Weekend?\n";
	 if (IsItWeekEnd(Date1))
		 cout << "Yes, It is Weekend.\n";
	 else
		 cout << "No, It is Not weekend.\n";

	 cout << "\n- Is it business day?\n";
	 if (IsItBusinessDay(Date1))
		 cout << "Yes, It is a Business day.\n\n";
	 else
		 cout << "No, it is NOT a business day.\n\n";

	 cout << "- Days untill the end of week: " << DaysUntillTheEndOfTheWeek(Date1) << " day(s)." << endl;
	 cout << "- Days untill the end of month: " << DaysUntillEndOfMonth(Date1) << " day(s)." << endl;
	 cout << "- Days untill end of year: " << DaysUntillEndOfYear(Date1) << " day(s).";

 }

int main()
{
	
	PrintDateDetails();

	system("pause>0");
	return 0;
} 
