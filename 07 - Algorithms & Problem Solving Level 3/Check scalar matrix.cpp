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

bool IsScalarMatrix(int arr1[3][3], short Rows, short Cols)
{
	int FirstElementInMatrix = arr1[0][0];
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && arr1[i][j] != FirstElementInMatrix)
				return false;
			else if (i != j && arr1[i][j] != 0)
				return false;
		}

	return true;
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3] = { {7,0,0},{0,7,0},{0,0,7} };
	FillInTheMatrixRandomly(arr1, 3, 3);

	cout << "Matrix: \n";
	PrintMatrix(arr1, 3, 3);
	
	if (IsScalarMatrix(arr1, 3, 3))
		cout << "Matrix is SCALAR matrix.\n";
	else
		cout << "Matrix is NOT scalar matrix.\n";
	
	return 0;
}
