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


void PrintMatrixRow(int arr[3][3],  short Rows, short Colomns)
{
	short MiddleRow = Rows / 2;
	for (short i = 0; i < Rows; i++)
	{
		
		
			printf("%0*d      ", 2, arr[MiddleRow][i]);

		
	}
}

void PrintMatrixColumn(int arr[3][3], short Rows, short Colomns)
{
	short MiddleCol = Colomns / 2;

	for (short i = 0; i < Rows; i++)
	
		{
			printf("%0*d      ", 2, arr[i][MiddleCol]);

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


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];


	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	
	cout << "Matrix middel Row: \n";
	PrintMatrixRow(arr, 3, 3);
	cout << "\n------------------------------\n";

	cout << "Matrix middel column: \n";
	PrintMatrixColumn(arr, 3, 3);

	cout << "\n------------------------------\n";

	system("pause>0");





	return 0;
}
