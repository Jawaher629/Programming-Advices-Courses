#include <ctime>
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;



int RandomeNumber(int from, int to)
{
	int randomeNumber = rand() % (to - from + 1) + from;
	return randomeNumber;
}


void FillMatrixWithRandomeNums(int arr[3][3], short Rows, short Columns)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			arr[i][j] = RandomeNumber(1, 10);
		}
	}
}
void FillMatrix2WithRandomeNums(int arr[3][3], short Rows, short Columns)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			arr[i][j] = RandomeNumber(1, 10);
		}
	}
}

void MatrixesProduct(int arr1[3][3], int arr2[3][3], int ArrProduct[3][3], short Rows, short Colomns)
{
	short counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Colomns; j++)
		{
			ArrProduct[i][j] = arr1[i][j] * arr2[i][j];
		}
	}
}

void PrintMatrix(int arr[3][3],  short Rows, short Columns)
{

	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			printf("%0*d      ",2,arr[C][R]);
		}
		cout << endl << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arr2[3][3] , arrProduct[3][3];


	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	FillMatrix2WithRandomeNums(arr2, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr2, 3, 3);
	cout << "------------------------------\n";

	MatrixesProduct(arr, arr2,arrProduct ,3, 3);
	cout << "Transdosed Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arrProduct, 3, 3);
	cout << "------------------------------\n";


	system("pause>0");





	return 0;
}
