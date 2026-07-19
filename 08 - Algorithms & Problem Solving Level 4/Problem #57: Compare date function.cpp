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
enum enCompareDates { Equal = 0, After = 1, Before = -1 };

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


int main()
{
	stDate Date1 = ReadFullDate("Enter date1 details/\n"), Date2 = ReadFullDate("Enter date2 details/\n");
	cout <<"\nCompare Result = " << (CompareDatesFunc(Date1, Date2));
	
	system("pause>0");
	return 0;
} 
