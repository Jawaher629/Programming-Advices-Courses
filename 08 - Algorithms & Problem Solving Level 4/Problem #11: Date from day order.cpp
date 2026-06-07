#include <iostream>
#include <string>
using namespace std;
struct stDate {
	short Year = 0;
	short Month = 0;
	short Day = 0;
};
bool IsLeapYear( int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);

}

int DaysInMonth(int Year, int Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return (IsLeapYear(Year) ? 29 : 28);


	return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);

}

 short ReadUserNumber(string Message)
{
	 short num = 0;
	cout << Message;
	cin >> num;
	return num;
}

 short DaysFrombeginningOfYear(short Year, short Month, short Day)
 {
	 short counter = 0;
	 for (short i = 1; i <= Month - 1; i++)
	 {
		 counter += DaysInMonth(Year, i);
	 }
	 counter += Day;
	 return counter;
 }

 stDate DateFromDayOrder(short DayOrder , short Year)
 {
	 stDate Date;
	 short RamainingDays = DayOrder;
	 Date.Year = Year;
	 Date.Month = 1;
	 

	 while (true)
	 {
		 short MonthDays = DaysInMonth(Year, Date.Month);
		 if (RamainingDays > MonthDays)
		 {
			 RamainingDays -= MonthDays;
			 Date.Month++;
		 }
		 else
		 {
			 Date.Day = RamainingDays;
			 break;
		 }
	 }
	 return Date;

 }

int main()
{
	short Year = ReadUserNumber("Enter the year: "), Month = ReadUserNumber("Enter the month: "), Day = ReadUserNumber("Enter the day: ") , DaysOrder = DaysFrombeginningOfYear(Year, Month, Day);
	cout << "Number of days from the beginning of the year: " << DaysOrder << endl;
	stDate Date = DateFromDayOrder(DaysOrder, Year);

	cout << "The Date for [" << DaysOrder << "] is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << ".\n";



	system("pause>0");
	return 0;
}
