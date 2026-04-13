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

void PrintIntersectedNumbers(int arr1[3][3], int arr2[3][3], short Rows, short Cols)
{
	int Num = 0;
	for(short i = 0;i < Rows;i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Num = arr1[i][j];
			if (IsNumberFound(arr2, 3, 3,Num))
			{
				cout << setw(3) << Num << "       ";
			}
		}
	}

}



int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillInTheMatrixRandomly(Matrix1, 3, 3);
	cout << "Matrix 1: \n";
	PrintMatrix(Matrix1, 3, 3);

	FillInTheMatrixRandomly(Matrix2, 3, 3);
	cout << "Matrix 2: \n";
	PrintMatrix(Matrix2, 3, 3);

	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	
	return 0;
}
