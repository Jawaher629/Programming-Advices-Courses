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

bool IsIdentityMatrix(int arr1[3][3], short Rows, short Cols)
{
	
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr1[i][j] != 1)
				return false;
			else if (i != j && arr1[i][j] != 0)
				return false;
		}

	return true;
}





int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3] = { {1,0,0},{0,1,0},{0,0,1} };
	FillInTheMatrixRandomly(arr1, 3, 3);

	cout << "Matrix: \n";
	PrintMatrix(arr1, 3, 3);
	
	if (IsIdentityMatrix(arr1, 3, 3))
		cout << "Matrix is IDENTITY.\n";
	else
		cout << "Matrix is NOT identity.\n";
	
	return 0;
}
