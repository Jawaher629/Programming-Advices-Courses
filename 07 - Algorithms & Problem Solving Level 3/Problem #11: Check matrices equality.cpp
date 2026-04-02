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
	cout << endl;
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

	int arr1[3][3], arr2[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	FillInTheMatrixRandomly(arr2, 3, 3);

	cout << "Matrix 1:\n";
	PrintMatrix(arr1, 3, 3);

	cout << "Matrix 2:\n";
	PrintMatrix(arr2, 3, 3);
	
	if (SumOfMtrix(arr1, 3, 3) == SumOfMtrix(arr2, 3, 3))
	{
		cout << "Matrices are Equal!\n";
	}
	else
		cout << "Matrices are NOT equal!\n";
	
	return 0;
}

//----------------------------------------------------------------------------------------------------------

  //Dr. Abu Hadhoud solution:

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
	cout << endl;
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

bool IsMatricesEqual(int arr1[3][3], int arr2[3][3], short Rows, short Columns)
{
	return (SumOfMtrix(arr1, Rows, Columns) == SumOfMtrix(arr2, Rows, Columns));
}


int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3], arr2[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	FillInTheMatrixRandomly(arr2, 3, 3);

	cout << "Matrix 1:\n";
	PrintMatrix(arr1, 3, 3);

	cout << "Matrix 2:\n";
	PrintMatrix(arr2, 3, 3);
	
	if (IsMatricesEqual(arr1,arr2,3,3))
	{
		cout << "Matrices are Equal!\n";
	}
	else
		cout << "Matrices are NOT equal!\n";
	
	
	return 0;
}
