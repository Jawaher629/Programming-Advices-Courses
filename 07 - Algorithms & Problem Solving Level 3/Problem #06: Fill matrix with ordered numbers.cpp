#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int RandomeNumbers(int From, int To)
{
	int Randome = rand() % (To - From + 1) + From;
	return Randome;
}


void FillInTheMatrixWithOrderNums(int arr1[3][3], short Rows, short Colomns)
{
	short Num = 1;
	for (short r = 0; r < Rows; r++)
	{
		for (short c = 0; c < Colomns; c++)
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


int main()
{
	srand((unsigned)time(NULL));

	int arr1[3][3];
	FillInTheMatrixWithOrderNums(arr1, 3, 3);
	cout << "A 3*3 randome matrix filled: \n";
	PrintMatrix(arr1, 3, 3);
	

	return 0;
}
