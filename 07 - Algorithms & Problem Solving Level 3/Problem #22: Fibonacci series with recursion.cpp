#include <iostream>
#include <string>
using namespace std;


void PrintFibonacciSeiresWithRecursion(short Num,int Prev1, int Prev2)
{
	int FibNumber = 0;
	if (Num > 0)
	{
		FibNumber = Prev1 + Prev2;
		Prev1 = Prev2;
		Prev2 = FibNumber;
		cout << FibNumber << ",  ";
	}
	PrintFibonacciSeiresWithRecursion(Num - 1, Prev1, Prev2);
}


int main()
{

	PrintFibonacciSeiresWithRecursion(10, 1, 0);
	
	return 0;
}
