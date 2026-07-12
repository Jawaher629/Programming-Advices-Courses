#include <iostream>
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

 
 stDate ReadFullDate()
 {
	 stDate Date;
	 Date.Year = ReadUserNumber("Enter the year: ");
	 Date.Month = ReadUserNumber("Enter the month: ");
	 Date.Day = ReadUserNumber("Enter the day: ");

	 return Date;
 }


 stDate DecreaseDateByOneDay(stDate Date)
 {
	 if (Date.Day == 1 && Date.Month == 1)
	 {
		 Date.Day = DaysInMonth(Date.Year, Date.Month);
		 Date.Month  = 12 ;
		 Date.Year-- ;
	 }
	 else if(Date.Day == 1)
	 {
		 Date.Month--;
		 Date.Day = DaysInMonth(Date.Year, Date.Month);
	 }
	 else
	 {
		 Date.Day--;
	 }

	 return Date;
 }

 stDate DecreaseXdaysFromDate(stDate Date, int DaysNum)
 {
	 for (int i = 1; i <= DaysNum; i++)
	 {
		 Date = DecreaseDateByOneDay(Date);
	 }

	 return Date;
 }

 stDate DecreaseOneWeekFromDate(stDate Date)
 {
	 for (int i = 1; i <= 7; i++)
	 {
		 Date = DecreaseDateByOneDay(Date);
	 }
	 return Date;
 }

 stDate DecreaseXWeeksFromDate(stDate Date, int WeeksMultiplier)
 {
	 for (int i = 1; i <= WeeksMultiplier ; i++)
	 {
		 Date = DecreaseOneWeekFromDate(Date);
	 }
	 return Date;
 }

 stDate DecreaseOneMonthFromDate(stDate Date)
 {
	 if (Date.Month == 1)
	 {
		 Date.Month == 12;
		 Date.Year--;
	 }
	 else
		 Date.Month--;

	 short NumberOfCurrentDays = DaysInMonth(Date.Year, Date.Month);
	 if (NumberOfCurrentDays > Date.Day)
	 {
		 Date.Day = NumberOfCurrentDays;
	 }

	 return Date;
 }

 stDate DecreaseXMonthsFromDate(stDate Date, int MonthsMultiplier)
 {
	 for (int i = 1; i <= MonthsMultiplier; i++)
	 {
		 Date = DecreaseOneMonthFromDate(Date);
	 }
	 return Date;
 }

 stDate DecreaseOneYearFromDate(stDate Date)
 {
	  Date.Year--;
	  return Date;
 }

 stDate DecreaseXYearsFromDate(stDate Date, int YearMultiplier)
 {
	 for (int i = 1; i <= YearMultiplier; i++)
	 {
		 Date = DecreaseOneYearFromDate(Date);
	 }
	 return Date;
 }

 stDate DecreaseXYearsFromDateFaster(stDate Date, int YearMultiplier)
 {
	 Date.Year -= YearMultiplier;
	 return Date;
 }

 stDate DecreaseOneDecadeFromDate(stDate Date)
 {
	 return DecreaseXYearsFromDate(Date, 10);
 }

 stDate DecreaseXDecadesFromDate(stDate Date, int DecadesMultiplier)
 {
	 Date.Year -= DecadesMultiplier * 10;
	 return Date;
 }

 stDate DecreaseOneCenturyFromDate(stDate Date)
 {
	 Date.Year -= 100;
	 return Date;
 }

 stDate DecreaseOneMillenniumFromDate(stDate Date)
 {
	 Date.Year -= 1000;
	 return Date;
 }

int main()
{
	cout << "Enter the date:\n\n";
	stDate Date1 = ReadFullDate();

	cout << "\n\n";

	Date1 = DecreaseDateByOneDay(Date1);
	cout << "01 - Date after decreasing one day: "  << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXdaysFromDate( Date1,10);
	cout << "02 - Date after decreasing " << 10 << " Days: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneWeekFromDate(Date1),
	cout << "03 - Date after decreasing one week: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXWeeksFromDate(Date1, 10);
	cout << "04 - Date after decreasing 10 weeks: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneMonthFromDate(Date1);
	cout << "05 - Date after decreasing one month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXMonthsFromDate(Date1,10);
	cout << "06 - Date after decreasing 10 months: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneYearFromDate(Date1);
	cout << "07 - Date after decreasing one year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXYearsFromDate(Date1,10);
	cout << "08 - Date after decreasing 10 years: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXYearsFromDateFaster(Date1, 10);
	cout << "09 - Date after decreasing 10 years FASTER: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneDecadeFromDate(Date1);
	cout << "10 - Date after decreasing one decade: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseXDecadesFromDate(Date1, 10);
	cout << "11 - Date after decreasing 10 decades: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneCenturyFromDate(Date1);
	cout << "12 - Date after decreasing one century: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseOneMillenniumFromDate(Date1);
	cout << "13 - Date after decreasing one millennium: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;


	system("pause>0");
	return 0;
} 
