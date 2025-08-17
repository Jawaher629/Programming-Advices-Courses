#include <ctime>
#include <iostream>
#include <iomanip>
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

void PrintRandomeMatrix(int arr[3][3] , short Rows , short Columns)
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

int SumTheColumnsOfMatrix(int arr[3][3],short Rows,short ColumnsNum)
{
	int sum = 0;
	for (short j = 0; j < Rows; j++)
	{
		sum += arr[j][ColumnsNum];
	}
	return sum;
}


void PrintTheSumOfMatrixColumns(int arr[3][3], short Rows, short Columns)
{
	cout << "The sum of the matrix: " << endl << endl;
	for (int j = 0; j < Rows; j++)
	{
		cout << "The sum of column number " << j + 1 << ": " << SumTheColumnsOfMatrix(arr, Rows, j) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Tha matrix elements: \n" << "-----------------------------------\n";
    PrintRandomeMatrix(arr,3,3);
	cout << "-----------------------------------\n";
	PrintTheSumOfMatrixColumns(arr, 3, 3);

    system("pause>0");





	return 0;
}
