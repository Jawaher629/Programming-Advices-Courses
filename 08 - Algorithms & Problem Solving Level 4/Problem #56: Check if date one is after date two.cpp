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

short GetDayIndexs(short Month, short Year, short Day);
short GetDayIndexs(stDate Date);

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

 bool IsItWeekEnd(stDate Date)
 {
	 return (GetDayIndexs(Date) == 6 || GetDayIndexs(Date) == 5);
 }

 bool IsItBusinessDay(stDate Date)
 {
	 return !IsItWeekEnd(Date);
 }

 string IndexToDayName(int DayIndex)
 {
	 string DayName[] = { "Sunday","Monday","Tuesday","Wendesday","Thuresday","Friday","Saturday" };
	 return DayName[DayIndex];
 }

 bool IsDay1BeforDay2(stDate Date1, stDate Date2)
 {
	 return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false);
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
	 return (!IsDay1BeforDay2(Date1, Date2));
 }

int main()
{
	stDate Date1 = ReadFullDate("Enter date1 details/\n"), Date2 = ReadFullDate("Enter date2 details/\n");
	if (IsDate1AfterDate2(Date1, Date2))
		cout << "Yes, Date 1 is after date 2.\n";
	else
		cout << "No, Date 1 is Not after date 2.\n";

	
	system("pause>0");
	return 0;
} 
