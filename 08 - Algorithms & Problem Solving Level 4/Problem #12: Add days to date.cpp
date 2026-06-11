#include <iostream>
#include <string>
using namespace std;
struct stDate {
	int Year = 0;
	int Month = 0;
	int Day = 0;
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


 stDate AddDaysToDate(int Days, stDate Date)
 {
	 int RemainingDays = Days + DaysFrombeginningOfYear(Date.Year, Date.Month, Date.Day) , MonthDays = 0;
	 Date.Month = 1;
	 while (true)
	 {
		 MonthDays = DaysInMonth(Date.Year, Date.Month);
		 if (RemainingDays > MonthDays)
		 {
			 RemainingDays -= MonthDays;
			 Date.Month++;

			 if (Date.Month > 12)
			 {
				 Date.Year++;
				 Date.Month = 1;
			 }
		 }
		 else
		 {
			 Date.Day = RemainingDays;
			 break;
		 }
	 }
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
	stDate Date = ReadFullDate();
	int DaysToAdd = ReadUserNumber("Enter number of days to add: ");

	Date = AddDaysToDate(DaysToAdd, Date);

	cout << "\nThe date after add [" << DaysToAdd << "] to it is: " << Date.Day << "/" << Date.Month << "/" << Date.Year << ".\n";


	system("pause>0");
	return 0;
} 
