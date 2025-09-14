#include <iostream>
using namespace std;


void PrintFibonacciSeries(short HowManyTimes, int Num1 , int Num2)
{

	if (HowManyTimes > 0)
	{
		int result = Num1 + Num2;
		cout << result << "  ";
		Num2 = Num1;
		Num1 = result;
	}

		PrintFibonacciSeries(HowManyTimes - 1, Num1 , Num2);
}



int main()
{
	PrintFibonacciSeries(10 , 0 , 1);

	system("pause>0");
	return 0;
}
