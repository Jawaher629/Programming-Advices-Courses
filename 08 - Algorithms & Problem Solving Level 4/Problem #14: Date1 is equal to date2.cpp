//My solution:
#include <iostream>
#include <string>
using namespace std;
struct stDate {
	int Year = 0;
	int Month = 0;
	int Day = 0;
};


 short ReadUserNumber(string Message)
{
	 short num = 0;
	cout << Message;
	cin >> num;
	return num;
}

 bool IsDay1EqualToDay2(stDate Date1, stDate Date2)
 {
	 return (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
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
	stDate Date1 = ReadFullDate();
	stDate Date2 = ReadFullDate();

	if (IsDay1EqualToDay2(Date1, Date2))
		cout << "\nYes, date 1 is Equal to date 2.\n";
	else 
		cout << "\nNo, date 1 is NOT equal date 2.\n";



	system("pause>0");
	return 0;
} 
