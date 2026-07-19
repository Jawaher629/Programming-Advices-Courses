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


 stDate CalculateVacEndDay(stDate VacationBegaining, short VacationPeriod)
 {
	
	 short WeekEndCounter = 0;
	 
	 while (IsItWeekEnd(VacationBegaining))
	 {
		 VacationBegaining = IncreaseDateByOneDay(VacationBegaining);
	 }
	 for (short i = 1; i <= VacationPeriod + WeekEndCounter; i++)
	 {
		 if (IsItWeekEnd(VacationBegaining))
			 WeekEndCounter++;

		 VacationBegaining = IncreaseDateByOneDay(VacationBegaining);

	 }
	 while (IsItWeekEnd(VacationBegaining))
	 {
		 VacationBegaining = IncreaseDateByOneDay(VacationBegaining);
	 }
	 return VacationBegaining;
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

int main()
{
	stDate Date1 = ReadFullDate("Enter vacation starting day/\n"), Date2;
	short VacationDaysNumber = ReadUserNumber("Enter your actual vacation days number: ");

	Date2 = CalculateVacEndDay(Date1, VacationDaysNumber);
	cout << "\n\nVacation starts: \n";
	cout << IndexToDayName(GetDayIndexs(Date1)) << ", " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << ".\n\n";
	cout << "Vacation ends at: \n";
	cout << IndexToDayName(GetDayIndexs(Date2)) << ", " << Date2.Day << "/" << Date2.Month << "/" << Date2.Year << ".\n";

	system("pause>0");
	return 0;
} 
