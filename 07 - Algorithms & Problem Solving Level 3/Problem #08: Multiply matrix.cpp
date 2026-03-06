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
			arr1[r][c] = RandomeNumbers(1, 10);
		}
	}
}
void PrintMatrix(int arr1[3][3], short Rows, short Colomns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
			printf( "%0*d    ",2, arr1[r][c]);
		cout << "\n";
	}
}

void MultiplyTwoMatrixes(int arr1[3][3], int arr2[3][3],int arrAnswer[3][3], short Rows, short Columns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
		{
			arrAnswer[r][c] = arr1[r][c] * arr2[r][c];
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3],arr2[3][3] , arrAnswer[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "Matrix 1: \n";
	PrintMatrix(arr1, 3, 3);

	FillInTheMatrixRandomly(arr2, 3, 3);
	cout << "matrix 2: \n";
	PrintMatrix(arr2, 3, 3);

	MultiplyTwoMatrixes(arr1, arr2, arrAnswer, 3, 3);
	cout << "Multiplication answer: \n";
	PrintMatrix(arrAnswer, 3, 3);
	return 0;
}
