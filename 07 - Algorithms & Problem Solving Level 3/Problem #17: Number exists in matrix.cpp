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

int ReadIntFromUser(string Message)
{
	int Num = 0;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

bool IsNumberFound(int arr1[3][3], short Rows, short Cols, short Num)
{
	for (short i = 0; i < Rows; i++)
		for (short j = 0; j < Cols; j++)
		{
			if (arr1[i][j] == Num)
				return true;
		}
	return false;
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];

	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "Matrix: \n";
	PrintMatrix(arr1, 3, 3);

	short Num = ReadIntFromUser("Enter number to search: ");
	if (IsNumberFound(arr1, 3, 3,Num))
		cout << Num << " is EXISTS.\n";
	else
		cout << Num << " DOSE NOT exists.\n";

	
	return 0;
}
