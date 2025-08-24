#include <ctime>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


void FillMatrixWithOrderedNums(int arr[3][3], short Rows, short Columns)
{
	int i = 0;
	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Columns; R++)
		{
			i++;
		    arr[C][R] = i;
		}
	}
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Colomns)
{
	short counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colomns; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

void PrintMatrix(int arr[3][3],  short Rows, short Columns)
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


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arrTransposed[3][3];


	FillMatrixWithOrderedNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	TransposeMatrix(arr, arrTransposed, 3, 3);
	cout << "Transdosed Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arrTransposed, 3, 3);
	cout << "------------------------------\n";


	system("pause>0");





	return 0;
}
