// My solution:
#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear( int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);

}

 int ReadUserNumber(string Message)
{
	long int num = 0;
	cout << Message;
	cin >> num;
	return num;
}
 int DaysInAyear(int Number)
 {
	 return (!IsLeapYear(Number) ? 365 : 366);
 }

 int HoursInAyear(int Number)
 {
	 return (!IsLeapYear(Number) ? 365 * 24 : 366 * 24);
 }
 int MinutesInAyear(int Number)
 {
	 return (!IsLeapYear(Number) ? 365 * 24 * 60 : 366 * 24 * 60);
	
 }

 int SecondsInAyear(int Number)
 {
	 return (!IsLeapYear(Number) ? 365 * 24 * 3600 : 366 * 24 * 3600);
		 
 }
 void PrintDaysHoursMinutesSecondsInYear(int Year)
 {
	 cout << "\nNumber of days in year [" << Year << "] is: " << DaysInAyear(Year) << endl;
	 cout << "\nNumber of hours in year [" << Year << "] is: " << HoursInAyear(Year) << endl;
	 cout << "\nNumber of minutes in year [" << Year << "] is: " << MinutesInAyear(Year) << endl;
	 cout << "\nNumber of seconds in year [" << Year << "] is: " << SecondsInAyear(Year) << endl;
}

int main()
{
	int year = ReadUserNumber("Enter the year: ");
	
	PrintDaysHoursMinutesSecondsInYear(year);
	system("pause>0");
	return 0;
}
//------------------------------------------------------------------------------------------------------------
// Dr. Abu Hadhoud solution 
#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear( int Number)
{
	return ((Number % 4 == 0 && Number % 100 != 0) || Number % 400 == 0 ? true : false);

}

 int ReadUserNumber(string Message)
{
	long int num = 0;
	cout << Message;
	cin >> num;
	return num;
}
 int DaysInAyear(int Number)
 {
	 return (!IsLeapYear(Number) ? 365 : 366);
 }

 int HoursInAyear(int Number)
 {
	 return DaysInAyear(Number) * 24;
 }
 int MinutesInAyear(int Number)
 {
	 return  HoursInAyear(Number) * 60;
	
 }

 int SecondsInAyear(int Number)
 {
	 return MinutesInAyear(Number) * 60;
		 
 }
 void PrintDaysHoursMinutesSecondsInYear(int Year)
 {
	 cout << "\nNumber of days in year [" << Year << "] is: " << DaysInAyear(Year) << endl;
	 cout << "\nNumber of hours in year [" << Year << "] is: " << HoursInAyear(Year) << endl;
	 cout << "\nNumber of minutes in year [" << Year << "] is: " << MinutesInAyear(Year) << endl;
	 cout << "\nNumber of seconds in year [" << Year << "] is: " << SecondsInAyear(Year) << endl;
}

int main()
{
	int year = ReadUserNumber("Enter the year: ");
	
	PrintDaysHoursMinutesSecondsInYear(year);
	system("pause>0");
	return 0;
}
