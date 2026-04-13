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


bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
	int MaxNumber = Matrix1[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols / 2; j++)
			if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
				return false;
	}

	return true;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], PlinMatrix[3][3] = { {0,0,0},{7,7,7},{0,0,0} };

	FillInTheMatrixRandomly(Matrix1, 3, 3);
	cout << "Matrix 1: \n";
	PrintMatrix(PlinMatrix, 3, 3);

	if (IsPalindromeMatrix(PlinMatrix, 3, 3))
		cout << "Yes, It is a Palindrom matrix.\n";
	else
		cout << "No, It is NOT a plindrone matrix.\n";


	
	return 0;
}
