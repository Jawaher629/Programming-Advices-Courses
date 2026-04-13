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

int ReadNumberFromUser(string Massege)
{
	int num = 0;
	cout << Massege << endl;
	cin >> num;
	return num;
}

int CountNumberInMatrix(int arr1[3][3], short Rows, short Cols, short Num)
{
	int Counter = 0;
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] == Num)
				Counter++;
		}
	return Counter;
}





int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];

	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "Matrix: \n";
	PrintMatrix(arr1, 3, 3);

	int Num = ReadNumberFromUser("Enter number to count\n");
	cout << "Number[" << Num << "] Found [" << CountNumberInMatrix (arr1,3,3,Num) << "]Times.\n";
	return 0;
}
