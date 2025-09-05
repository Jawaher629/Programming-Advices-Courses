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



bool IsNumExistsInMatrix(int arr[3][3], int Num ,  short Rows, short Columns)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (arr[i][j] == Num)
			{

				return true;
			};
		}
	}
	return false;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], Num = 0;

	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	cout << "Enter a number to search for: ";
	cin >> Num;

	if (IsNumExistsInMatrix(arr, Num, 3, 3))
		cout << "Yes, " << Num << " is in matrix.\n";
	else
		cout << "No, " << Num << " is NOT in matrix.\n";


	system("pause>0");

	return 0;
}
