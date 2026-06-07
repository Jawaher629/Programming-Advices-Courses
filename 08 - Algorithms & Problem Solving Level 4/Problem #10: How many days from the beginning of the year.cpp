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


int main()
{
	short Year = ReadUserNumber("Enter the year: "), Month = ReadUserNumber("Enter the month: "), Day = ReadUserNumber("Enter the day: ");
	cout << "Number of days from the beginning of the year: " << DaysFrombeginningOfYear(Year, Month, Day);



	system("pause>0");
	return 0;
}
