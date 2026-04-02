//My solution:
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
			arr1[r][c] = RandomeNumbers(1, 100);
		}
	}
}
void PrintMatrix(int arr1[3][3], short Rows, short Columns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
			printf( "%0*d    ",2, arr1[r][c]);
		cout << "\n";
	}
}

void PrintMidCol(int arr1[3][3], short Cols, short Rows)
{
	for (short i = 0; i < Cols;i++)
		{
			printf("%0*d    ", 2, arr1[i][1]);
			


		}
}

void PrintMidRow(int arr1[3][3], short Cols, short Rows)
{
	
		for (short j = 0; j < Rows; j++)
		{
			printf("%0*d    ", 2, arr1[1][j]);



		}
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	PrintMatrix(arr1, 3, 3);

	cout << "\nMiddle Column printed: \n\n";
	PrintMidCol(arr1, 3, 3);

	cout << "\nMiddle Row printed: \n\n";

	PrintMidRow(arr1, 3, 3);
	
	return 0;
}


//Dr.Abu Hadhoud solution:
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
			arr1[r][c] = RandomeNumbers(1, 100);
		}
	}
}
void PrintMatrix(int arr1[3][3], short Rows, short Columns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Columns; c++)
			printf( "%0*d    ",2, arr1[r][c]);
		cout << "\n";
	}
}

void PrintMidCol(int arr1[3][3], short Cols, short Rows)
{
	short MidCol = Cols / 2;;
	for (short i = 0; i < Cols;i++)
		{
			printf("%0*d    ", 2, arr1[i][MidCol]);
			


		}
}

void PrintMidRow(int arr1[3][3], short Cols, short Rows)
{
	short MidRow = Rows / 2;
		for (short j = 0; j < Rows; j++)
		{
			printf("%0*d    ", 2, arr1[MidRow][j]);



		}
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	PrintMatrix(arr1, 3, 3);

	cout << "\nMiddle Column printed: \n\n";
	PrintMidCol(arr1, 3, 3);

	cout << "\nMiddle Row printed: \n\n";

	PrintMidRow(arr1, 3, 3);
	
	return 0;
}
