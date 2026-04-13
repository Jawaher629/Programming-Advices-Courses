//My Solution:
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


bool IsSparceMatrix(int arr1[3][3], short Rows, short Cols)
{
	short ZeroCounter = 0, NumCounter = 0;
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] == 0)
				ZeroCounter++;
			else
				NumCounter++;
		}
	if (ZeroCounter > NumCounter)
		return true;
	else
		return false;
}


int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3] = { {0,0,7},{0,0,8},{0,0,9} };

	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "Matrix: \n";
	PrintMatrix(arr1, 3, 3);
	if (IsSparceMatrix(arr1, 3, 3))
		cout << "Yes, It is Sparce matrix.\n";
	else
		cout << "No, It is NOT sparce matrix.\n";

	
	return 0;
}
