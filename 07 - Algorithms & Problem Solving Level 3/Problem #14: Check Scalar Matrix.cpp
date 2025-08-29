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


bool IsScalarMatrix(int arr[3][3], short Rows, short Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)

		{
			if (i == j && arr[i][j] != arr[0][0])
				return false;
			else if (i != j && arr[i][j] != 0)
				return false;
		}
	}
	return true;
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
	int arr[3][3];
	int arr2[3][3] = { {7,0,0},{0,7,0},{0,0,7} };

	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix 1 Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	if (IsScalarMatrix(arr, 3, 3))
	{
		cout << "YES, It is scalar matrix.\n";
	}
	else 
		cout << "No, It is not scalar matrix.\n";





	

	system("pause>0");





	return 0;
}
