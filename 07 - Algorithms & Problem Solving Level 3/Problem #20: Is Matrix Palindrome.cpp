// My solution: 

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


bool IsPalindromeMatrix(int arr[3][3], int Rows, int Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0 ; j < Columns; j++)
		{
			if (arr[i][j] != arr[Rows-i-1][Columns-j-1])
			return false;
		}
	}
	return true;
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3], arr2[3][3] = { {1,2,2},{2,2,2},{2,2,1} };

	FillMatrixWithRandomeNums(arr, 3, 3);

	cout << "Matrix 1 Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";


	if (IsPalindromeMatrix(arr, 3, 3))
		cout << "Yes. It is Palindrome Matrix\n";
	else
		cout << "No. It is Not Palindrome Matrix\n";
	


	system("pause>0");
	return 0;
}


// Abu Hadhoud solution:

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


bool IsPalindromeMatrix(int arr[3][3], int Rows, int Columns)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0 ; j < Columns/2; j++)
		{
			if (arr[i][j] != arr[i][Columns-j-1])
			return false;
		}
	}
	return true;
}






int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];

	FillMatrixWithRandomeNums(arr, 3, 3);

	cout << "Matrix 1 Elements: \n" << "------------------------------\n";
	PrintMatrix(arr, 3, 3);
	cout << "------------------------------\n";


	if (IsPalindromeMatrix(arr, 3, 3))
		cout << "Yes. It is Palindrome Matrix\n";
	else
		cout << "No. It is Not Palindrome Matrix\n";
	


	system("pause>0");
	return 0;
}
