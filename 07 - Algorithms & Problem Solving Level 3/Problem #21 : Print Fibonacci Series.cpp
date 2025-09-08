#include <ctime>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


void PrintFibonacciSeries(short HowManyTimes)
{
	int num1 = 1 , num2= 0, result = 0;
	for (int i = 1; i < HowManyTimes; i++)
	{
		result = num2 + num1;

		cout << result << "  ";
		num2 = num1;
		num1 = result;

	}
}

int main()
{
	PrintFibonacciSeries(10);

	system("pause>0");
	return 0;
}
