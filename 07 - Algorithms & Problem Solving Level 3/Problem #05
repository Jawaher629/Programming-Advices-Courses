#include <ctime>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;



int randomeNumber(int from, int to)
{
	int randomeNumber = rand() % (to - from + 1) + from;
	return randomeNumber;
}

void FillMatrixWithRandomeNums(int arr[3][3], short Rows, short Columns)
{
	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Columns; R++)
		{
			arr[C][R] = randomeNumber(1, 100);
		}
	}
}

void PrintRandomeMatrix(int arr[3][3], short Rows, short Columns)
{

	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			cout << setw(3) << arr[C][R] << "       ";
		}
		cout << endl << endl;
	}
}

int SumTheColumnsOfMatrix(int arr[3][3], short Rows, short ColumnsNum)
{
	int sum = 0;
	for (short j = 0; j < Rows; j++)
	{
		sum += arr[j][ColumnsNum];
	}
	return sum;
}

void CopyMatrixColumnsSum( int arr[3][3],int arrSum[3],short Rows, short Columns)
{
	for (int i = 0; i < Columns; i++)
	{
		arrSum[i] = SumTheColumnsOfMatrix(arr, Rows, i);

	}
}


void PrintSumArray(int arr[3], int length)
{
	for (int j = 0; j < length; j++)
	{
		cout << "Column's number " << j + 1 << " sum = " << arr[j] << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintRandomeMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	CopyMatrixColumnsSum(arr,arrSum,3,3);
	cout << "Columns Sum: \n";
	PrintSumArray(arrSum, 3);

	system("pause>0");





	return 0;
}
