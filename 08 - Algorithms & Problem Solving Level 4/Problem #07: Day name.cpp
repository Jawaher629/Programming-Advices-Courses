#include <iostream>
#include <string>
using namespace std;

 int ReadUserNumber(string Message)
{
	 int num = 0;
	cout << Message;
	cin >> num;
	return num;
}

 string IndexToDayName(int DayIndex)
 {
	 string DayName[] = { "Sunday","Monday","Tuesday","Wendesday","Thuresday","Friday","Saturday" };
	 return DayName[DayIndex];
 }

 short GetDayIndexs(short Month , short Year, short Day)
 {
	 short a = (14 - Month) / 12;
	 short y = Year - a;
	 short m = Month - (12 * a) - 2;
	 return (Day + y + (y / 4) - (y / 100) + y / 400 + ((31 * m) / 12)) % 7;
 }
 void PrintBirthDayDate(short Month, short Year, short Day)
 {
	 short DayIn = GetDayIndexs(Month, Year, Day);
	 cout << "\n- Date      : " << Day << "/" << Month << "/" << Year;
	 cout << "\n- Day order : " << DayIn + 1;
	 cout << "\n- Day name  : " << IndexToDayName(DayIn);

 }
 
int main()
{
	int Year = ReadUserNumber("Enter year: ") , Month = ReadUserNumber("Enter Month: ") , Day = ReadUserNumber("Enter the day: ");
	PrintBirthDayDate(Month,Year,Day);

	system("pause>0");
	return 0;
}
