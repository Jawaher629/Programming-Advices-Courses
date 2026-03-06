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

void PrintMatrix(int arr1[3][3], short Rows, short Colomns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
			cout << setw(3) << arr1[r][c] << "     ";
		cout << "\n";
	}
}

int SumEachRowInMatrix(int arr1[3][3], short RowsNumber, short Colomns)
{
	int sum = 0;

	for (short i = 0; i <= Colomns - 1; i++)
	{
		sum += arr1[RowsNumber][i];
	}
	return sum;
}

void SumRowsInArray(int arr1[3][3], int arrSum[3], short Rows, short Colomns)
{
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] = SumEachRowInMatrix(arr1, i, 3);
	}
}

void PrintRowsSumArray(int arrSum[3], short Rows)
{
	cout << "Sum array printed: \n";
	for (short i = 0; i < Rows; i++)
	{
		cout << "Row # " << i + 1 <<" sum: " << arrSum[i] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3] , arrSum[3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "A 3*3 randome matrix filled: \n";
	PrintMatrix(arr1, 3, 3);
	SumRowsInArray(arr1, arrSum, 3, 3);
	PrintRowsSumArray(arrSum, 3);

	return 0;
}
