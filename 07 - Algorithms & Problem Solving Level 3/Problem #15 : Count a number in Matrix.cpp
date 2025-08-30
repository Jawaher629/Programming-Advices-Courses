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


short CountAnumberInMatrix(int arr[3][3],int Num ,short Rows, short Columns)
{
	short count = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)

		{
			if (arr[i][j] == Num) count++;
		}
	}
	return count;
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
	int arr[3][3] ;
	short Num = 0;
  
	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";
  
	cout << "Enter the number to count in matrix: ";
	cin >> Num;
	cout << Num <<  " has been found " << CountAnumberInMatrix(arr, Num, 3, 3) << " times.\n";

	system("pause>0");





	return 0;
}
