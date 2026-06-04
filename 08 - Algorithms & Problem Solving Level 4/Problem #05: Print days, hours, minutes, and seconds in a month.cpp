// Ny solution:
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

	 if(Month == 2)
	 return (IsLeapYear(Year) ? 29 : 28);
		 

	 return ((Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31);
		
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
//---------------------------------------------------------------------------------------------
//Dr.Abu Hadhoud solution:
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

	 if(Month == 2)
	 return (IsLeapYear(Year) ? 29 : 28);
		 
	 int arr30days[4] = { 4,6,9,11 };
	 for (int i = 1; i <= 4; i++)
	 {
		 if (arr30days[i - 1] == Month)
			 return 30;
	 }
	 return 31;
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
