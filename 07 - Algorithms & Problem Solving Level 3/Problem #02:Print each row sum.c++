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

void PrintEachRowSum(int arr1[3][3], short Rows, short Colomns)
{
	cout << "The sum of each sum in the matrix: " << endl;
	for (short i = 0; i < Rows; i++)
	{
		cout << "Row #" << i + 1 << " Sum = " << SumEachRowInMatrix(arr1, i, Colomns) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "A 3*3 randome matrix filled: \n";
	PrintMatrix(arr1, 3, 3);

	PrintEachRowSum(arr1, 3, 3);

	return 0;
}
