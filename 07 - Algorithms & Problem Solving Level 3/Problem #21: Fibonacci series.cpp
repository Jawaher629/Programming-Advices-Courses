#include <iostream>
#include <string>
using namespace std;


void PrintFebonacciSeiress(int Num)
{
	int Prev1 = 1, Prev2 = 0 , FebAnswer = 0;
	cout << "Febonacci Series: 1,  ";
	for (int i = 2; i <= Num; ++i)
	{
		FebAnswer = Prev1 + Prev2;
		cout  << FebAnswer << ",  ";
		Prev2 = Prev1;
		Prev1 = FebAnswer;
	}
}

int main()
{
	PrintFebonacciSeiress(10);
	
	return 0;
}
