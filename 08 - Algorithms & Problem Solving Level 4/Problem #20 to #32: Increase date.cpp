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
	 int RemainingDays = Days + DaysFrombeginningOfYear(Date.Year, Date.Month, Date.Day), MonthDays = 0;
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

 stDate AddOneWeekToDate(stDate Date)
 {
	 return (AddDaysToDate(7, Date));
 }

 stDate AddXWeeksToDate(stDate Date, int WeeksMultiplier)
 {
	 return (AddDaysToDate(7 * WeeksMultiplier, Date));
 }

 stDate AddOneMonthToDate(stDate Date)
 {
	 return (AddDaysToDate(30, Date));
 }

 stDate AddXMonthsToDate(stDate Date, int MonthsMultiplier)
 {
	 return (AddDaysToDate(30 * MonthsMultiplier,Date));
 }

 stDate AddOneYearToDate(stDate Date)
 {
	 return (AddDaysToDate(365, Date));
 }

 stDate AddXYearsToDate(stDate Date, int YearMultiplier)
 {
	 return (AddDaysToDate(365 * YearMultiplier, Date));
 }

 stDate AddOneDecadeToDate(stDate Date)
 {
	 return (AddDaysToDate(365 * 10, Date));
 }

 stDate AddXDecadesToDate(stDate Date, int DecadesMultiplier)
 {
	 return (AddDaysToDate((365 * 10)* DecadesMultiplier, Date));
 }

 stDate AddOneCenturyToDate(stDate Date)
 {
	 return (AddDaysToDate((365 * 100), Date));
 }

 stDate AddOneMillenniumToDate(stDate Date)
 {
	 return (AddDaysToDate((365 * 1000), Date));
 }

int main()
{
	cout << "Enter the date 1: \n";
	stDate Date1 = ReadFullDate();

	cout << "\n\n";

	Date1 = AddDaysToDate(10, Date1);
	cout << "1 - Date after adding " << 10 << " Days: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddOneWeekToDate(Date1),
	cout << "2 - Date after adding one week: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddXWeeksToDate(Date1,10);
	cout << "3 - Date after adding 10 weeks: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddOneYearToDate(Date1);
	cout << "4 - Date after adding one year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddXYearsToDate(Date1,10);
	cout << "5 - Date after adding 10 years: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddOneDecadeToDate(Date1);
	cout << "6 - Date after adding one decade: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddXDecadesToDate(Date1,10);
	cout << "7 - Date after adding 10 decades: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddOneCenturyToDate(Date1);
	cout << "8 - Date after adding one century: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = AddOneMillenniumToDate(Date1);
	cout << "9 - Date after adding one millennium: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;


	system("pause>0");
	return 0;
} 
