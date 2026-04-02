// My solution:

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomeNumbers(int From, int To)
{
	int Randome = rand() % (To - From + 1) + From;
	return Randome;
}


void FillInTheMatrixRandomly(int arr1[3][3], short Rows, short Colomns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
		{
			arr1[r][c] = RandomeNumbers(1, 100);
		}
	}
}
void PrintMatrix(int arr1[3][3], short Rows, short Columns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
			printf( "%0*d    ",2, arr1[r][c]);
		cout << "\n";
	}
}

int SumOfMtrix(int arr1[3][3], short Cols, short Rows)
{
	int Sum = 0;
		for(short i = 0 ; i < Rows ;i++)
			for (short j = 0; j < Cols; j++)
			{
				Sum += arr1[i][j];
			}
		return Sum;
}




int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	PrintMatrix(arr1, 3, 3);

	cout << "\n Matrix's Sum = " << SumOfMtrix(arr1, 3, 3);
	
	
	return 0;
}
