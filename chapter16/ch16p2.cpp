#include <iostream>

using namespace std;

void reversePrint(int array[], int size);

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }
    reversePrint(array, 10);
}

void reversePrint(int array[], int size)
{
    cout << array[size-1] << endl;
    if (size-1 > 0)
    {
        reversePrint(array, size-1);
    }
}