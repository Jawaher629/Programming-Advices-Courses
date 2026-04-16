#include <iostream>
#include <string>
using namespace std;


void PrintFibonacciSeiress(int Num)
{
	int Prev1 = 1, Prev2 = 0 , FibAnswer = 0;
	cout << "Fibonacci Series: 1,  ";
	for (int i = 2; i <= Num; ++i)
	{
		FibAnswer = Prev1 + Prev2;
		cout  << FibAnswer << ",  ";
		Prev2 = Prev1;
		Prev1 = FibAnswer;
	}
}

int main()
{
	PrintFibonacciSeiress(10);
	
	return 0;
}
