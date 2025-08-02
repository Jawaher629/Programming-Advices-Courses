#include <iostream>

using namespace std;

int main()
{
	cout << "\n\n\t\t\tMultiplication Table From 1 To 10\n\n";
	for (int i = 1; i <= 10; i++) cout << '\t' << i;
	cout << endl;
	for (int i = 1; i <= 83; i++) cout << '_';
	cout << endl;

	for (int i = 1; i <= 10; i++)
	{
		if (i < 10) cout << i << "    |  ";
		else        cout << i << "   |  ";

		for (int j = 1; j <= 10; j++) cout << i * j << '\t';
		cout << endl;
	}
}
