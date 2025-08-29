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


int MatrixSum(int arr[3][3],  short Rows, short Columns)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (int j = 0 ; j < Columns ; j++)
		
			Sum += arr[i][j];
	}
	return Sum;
}

string CompareMatSum( int Sum1, int Sum2)
{
	return (Sum1 == Sum2 ? "Yes, Matrices are equal.\n" : "No, Matrices are not equal.\n");
}


void PrintMatrix(int arr[3][3], short Rows, short Columns)
{

	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			printf("%0*d      ", 2, arr[C][R]);
		}
		cout << endl << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3] , arr2[3][3];


	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix 1 Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	FillMatrixWithRandomeNums(arr2, 3, 3);
	cout << "Matrix 2 Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	

	cout <<	CompareMatSum(MatrixSum(arr, 3, 3) , MatrixSum(arr2, 3, 3));
	

	system("pause>0");





	return 0;
}
