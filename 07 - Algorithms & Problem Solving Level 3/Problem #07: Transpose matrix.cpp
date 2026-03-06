#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomeNumbers(int From, int To)
{
	int Randome = rand() % (To - From + 1) + From;
	return Randome;
}


void FillInTheMatrixWithOrderNums(int arr1[3][3], short Rows, short Columns)
{
	short Num = 1;
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
		{
			arr1[r][c] = Num++;
			
		}
	}
}

void PrintMatrix(int arr1[3][3], short Rows, short Colomns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
			cout << setw(3) << arr1[r][c] << "     ";
		cout << "\n";
	}
}

void TransposedMatrix(int arr1[3][3], int Transposearr[3][3], short Rows, short Columns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
		{
			Transposearr[r][c] = arr1[c][r];
		}
	}
}


int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3],Transposearr[3][3];
	FillInTheMatrixWithOrderNums(arr1, 3, 3);
	cout << "A 3*3 randome matrix filled: \n";
	PrintMatrix(arr1, 3, 3);
	TransposedMatrix(arr1, Transposearr, 3, 3);
	cout << "Transposed Matrix: \n";
	PrintMatrix(Transposearr, 3, 3);

	return 0;
}
