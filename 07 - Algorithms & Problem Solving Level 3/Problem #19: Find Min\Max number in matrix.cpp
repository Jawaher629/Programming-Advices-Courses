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
			printf( "%0*d    ", 2,arr1[r][c]);
		cout << "\n";
	}
	cout << endl;
}


bool IsNumberFound(int arr1[3][3], short Rows, short Cols, int Num)
{
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] == Num)
				return true;
		}
	return false;
}

int FindMinNumber(int Matrix1[3][3], short Rows, short Cols)
{
	int MinNumber = Matrix1[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
			if (Matrix1[i][j] < MinNumber)
				MinNumber = Matrix1[i][j];
	}

	return MinNumber;
}

int FindMaxNumber(int Matrix1[3][3], short Rows, short Cols)
{
	int MaxNumber = Matrix1[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
			if (Matrix1[i][j] > MaxNumber)
				MaxNumber = Matrix1[i][j];
	}

	return MaxNumber;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillInTheMatrixRandomly(Matrix1, 3, 3);
	cout << "Matrix 1: \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "Maximum number in matrix is: " << FindMaxNumber(Matrix1, 3, 3) << endl;
	cout << "Minimum number in matrix is: " << FindMinNumber(Matrix1, 3, 3) << endl;

	
	return 0;
}
