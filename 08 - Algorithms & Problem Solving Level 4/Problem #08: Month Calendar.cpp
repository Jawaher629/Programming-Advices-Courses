#include <iostream>
#include <string>
using namespace std;

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

 int ReadUserNumber(string Message)
{
	 int num = 0;
	cout << Message;
	cin >> num;
	return num;
}

 string IndexToDayName(int DayIndex)
 {
	 string DayName[7] = { "Sunday","Monday","Tuesday","Wendesday","Thuresday","Friday","Saturday" };
	 return DayName[DayIndex];
 }
 string MonthName(short MonthNum)
 {
	 string arrMonthName[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Des"};
	 return arrMonthName[MonthNum - 1];
 }

 short GetDayIndexs(short Month , short Year, short Day)
 {
	 short a = (14 - Month) / 12;
	 short y = Year - a;
	 short m = Month - (12 * a) - 2;
	 return (Day + y + (y / 4) - (y / 100) + y / 400 + ((31 * m) / 12)) % 7;
 }
 void PrintMonthCalender(int Month, int Year)
 {
	 int NumberOfDay = DaysInMonth(Year, Month);
	 int Current = GetDayIndexs(Month, Year, 1); 

	 printf("\n ____________________%s____________________\n", MonthName(Month).c_str());
	 printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	 int i;
	 for (i = 0; i < Current; i++)
		 printf("     ");

	 for (int j = 1; j <= NumberOfDay; j++)
	 {
		 printf("%5d", j);

		 if (++i == 7)
		 {
			 i = 0;
			 printf("\n");
		 }
	 }
	 printf("\n __________________________________________\n");
 }

 
int main()
{
	int Year = ReadUserNumber("Enter year: ") , Month = ReadUserNumber("Enter Month: ");
	PrintMonthCalender(Month, Year);

	system("pause>0");
	return 0;
}
