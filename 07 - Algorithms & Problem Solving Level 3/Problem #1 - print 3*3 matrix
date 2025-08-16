#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;



int randomeNumber(int from, int to)
{
	int randomeNumber = rand() % (to - from + 1) + from;
	return randomeNumber;
}

void FillMatrixWithRandomeNums(int arr[3][3], short Colomns, short Rows)
{
	for (int C = 0; C < Colomns; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			arr[C][R] = randomeNumber(1, 100);
		}
	}
}

void PrintRandomeMatrix(int arr[3][3] , short Colomns , short Rows)
{
	FillMatrixWithRandomeNums(arr, Colomns, Rows);

	for (int C = 0; C < Colomns; C++)
	{
		for (int R = 0; R < Rows; R++)
		{
			cout << setw(3) << arr[C][R] << "       ";
		}
		cout << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	cout << "A 3*3 matrix elements: " << endl; 
 PrintRandomeMatrix(arr,3,3);
 system("pause>0");





	return 0;
}
