// Ny solution: 
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



bool IsSparceMatrix(int arr[3][3],  short Rows, short Columns)
{
	short Zero = 0 , NotZero = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (arr[i][j] == 0) Zero++;
			else
				NotZero++;
		}
	}
	return Zero > NotZero;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arr2[3][3]{ {0,0,0},{0,0,1},{0,0,0} };

	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";

	if (IsSparceMatrix(arr, 3, 3)) 
		cout << "It is a sparce matrix.\n";
	else
		cout << "It is not a sparce matrix.\n";

	system("pause>0");

	return 0;
}


// dr.Abu Hadhoud solution:
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

short CountAnumberInMatrix(int arr[3][3], short Num, short Rows, short Columns)
{
	short Count = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			if (arr[i][j] == Num) Count++;
		}
	}
	return Count;
}

bool IsSparceMatrix(int arr[3][3],  short Rows, short Columns)
{
	short MatrixSize = Rows * Columns;


	return(CountAnumberInMatrix(arr,0,3,3) >= MatrixSize /2) ;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arr2[3][3]={ {0,0,0},{0,0,1},{0,0,0} };

	FillMatrixWithRandomeNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintMatrix(arr2, 3, 3);
	cout << "------------------------------\n";


	if (IsSparceMatrix(arr2, 3, 3)) 
		cout << "It is a sparce matrix.\n";
	else
		cout << "It is not a sparce matrix.\n";

	system("pause>0");

	return 0;
}
