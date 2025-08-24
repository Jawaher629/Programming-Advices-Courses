#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


void FillMatrixWithOrderedNums(int arr[3][3], short Rows, short Columns)
{
	int i = 0;
	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Columns; R++)
		{
			i++;
		    arr[C][R] = i;
		}
	}
}

void PrintOrderedMatrix(int arr[3][3], short Rows, short Columns)
{

	for (int C = 0; C < Rows; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			cout << setw(3) << arr[C][R] << "       ";
		}
		cout << endl << endl;
	}
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	
	FillMatrixWithOrderedNums(arr, 3, 3);
	cout << "Matrix Elements: \n" << "------------------------------\n";
	PrintOrderedMatrix(arr, 3, 3);
	cout << "------------------------------\n";


	system("pause>0");





	return 0;
}
