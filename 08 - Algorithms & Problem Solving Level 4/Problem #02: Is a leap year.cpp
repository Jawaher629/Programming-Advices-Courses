//My solution: 
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
int main()
{
	int num = ReadUserNumber("Enter the year: ");
	if (IsLeapYear(num))
		cout << num << " is a leap year.";
	else
		cout << num << " is NOT a leap year.";

	system("pause>0");
	return 0;
}
