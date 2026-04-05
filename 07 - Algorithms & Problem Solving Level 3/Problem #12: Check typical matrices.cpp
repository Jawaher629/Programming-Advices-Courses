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

bool AreMayricesTypical(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
			if (arr1[i][j] != arr2[i][j])
				return false;

	return true;
}





int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2 [3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	FillInTheMatrixRandomly(arr2, 3, 3);

	cout << "Matrix 1: \n";
	PrintMatrix(arr1, 3, 3);

	cout << "Matrix 2: \n";
	PrintMatrix(arr2, 3, 3);

	if (AreMayricesTypical(arr1, arr2, 3, 3))
		cout << "Matrices are TYPICAL.";
	else
		cout << "Matrices are NOT typical.";
	
	
	
	
	return 0;
}
