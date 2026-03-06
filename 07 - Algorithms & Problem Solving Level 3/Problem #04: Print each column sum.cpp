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

void PrintMatrix(int arr1[3][3], short Rows, short Colomns)
{
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
			cout << setw(3) << arr1[r][c] << "     ";
		cout << "\n";
	}
}

int SumEachColumnInMatrix(int arr1[3][3], short Row, short ColumnsNumber)
{
	int sum = 0;

	for (short i = 0; i < Row ; i++)
	{
		sum += arr1[i][ColumnsNumber];
	}
	return sum;
}

void PrintEachColumnSum(int arr1[3][3], short Rows, short Column)
{
	cout << "The sum of each sum in the matrix: " << endl;
	for (short i = 0; i < Rows; i++)
	{
		cout << "Column #" << i + 1 << " Sum = " << SumEachColumnInMatrix(arr1, Rows, i) << endl;
	}
}



int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixRandomly(arr1, 3, 3);
	cout << "A 3*3 randome matrix filled: \n";
	PrintMatrix(arr1, 3, 3);
	
	SumEachColumnInMatrix(arr1, 3, 3);
	PrintEachColumnSum(arr1, 3, 3);

	return 0;
}
