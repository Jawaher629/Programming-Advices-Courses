#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear( int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);

}

 int ReadUserNumber(string Message)
{
	 int num = 0;
	cout << Message;
	cin >> num;
	return num;
}
 int DaysInMonth(int Year, int Month)
 {
	 if (Month < 1 || Month > 12)
		 return 0;
	 int arrDaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	 return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrDaysInMonth[Month - 1]);
 }

 int HoursInAMonth(int Number,int Month)
 {
	 return DaysInMonth(Number,Month) * 24;
 }
 int MinutesInAMonth(int Number, int Month)
 {
	 return  HoursInAMonth(Number,Month) * 60;
 }

 int SecondsInAMonth(int Number , int Month)
 {
	 return MinutesInAMonth(Number, Month) * 60;
		 
 }
 void PrintDaysHoursMinutesSecondsInYear(int Year, int Month)
 {
	 cout << "\nNumber of days in Month [" << Month << "] is: " << DaysInMonth(Year,Month) << endl;
	 cout << "\nNumber of hours in Month [" << Month << "] is: " << HoursInAMonth(Year, Month) << endl;
	 cout << "\nNumber of minutes in Month [" << Month << "] is: " << MinutesInAMonth(Year, Month) << endl;
	 cout << "\nNumber of seconds in Month [" << Month << "] is: " << SecondsInAMonth(Year, Month) << endl;
}

int main()
{
	int year = ReadUserNumber("Enter the year: ");
	int Month = ReadUserNumber("Enter month: ");
	PrintDaysHoursMinutesSecondsInYear(year,Month);
	system("pause>0");
	return 0;
}
