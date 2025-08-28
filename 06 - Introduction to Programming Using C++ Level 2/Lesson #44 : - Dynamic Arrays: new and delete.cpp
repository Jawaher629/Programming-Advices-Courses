#include <iostream>

using namespace std;


void TakeStudentsGrades()
{
    int num = 0;
    float* ptr;
    cout << "Enter how many students: ";
    cin >> num;

    ptr = new float[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter student number " << i + 1 << " grade: ";
        cin >> *(ptr + i);
        cout << endl;
    }
    cout << "Students grades: \n";
    for (int i = 0; i < num; i++)
    {
        cout << "Students number " << i + 1 << " grade: " << *(ptr + i) << endl;

    }
    delete [] ptr;
}



int main()
{
    TakeStudentsGrades();

    return 0;
}
