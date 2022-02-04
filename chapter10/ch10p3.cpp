#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArrayWithRandomNumbers(int array[],int size);
void printArray(int array[],int size);
void sortArray(int array[],int size);
int findSmallestRemainingElement(int array[], int size, int currentIndex);
void swapElements(int array[], int firstElement, int secondElement);
bool isArraySorted(int array[], int size);

int main ()
{
    int size = 10; // to change the size of array, just change the value of this variable
    int array[size];
    fillArrayWithRandomNumbers(array, size);
    
    cout << " array:\n";
    printArray(array, size);
    if (!isArraySorted(array, size))
    {
        sortArray(array,size);
        cout << " Sorted array:\n";
        printArray(array,size);
    }
    cout << " the array is sorted!";
}

void fillArrayWithRandomNumbers(int array[],int size)
{
    srand(time(NULL));
    int low = 0, high = 10;
    for (int i = 0; i < size; i++)
    {
        array[i] = rand()%(high-low) + low;
    }
}

void printArray(int array[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << array[i] << endl;
    }
}

void sortArray(int array[],int size)
{
    int smallestRemainingElement = 0;
    for (int i = 0; i < size; i++)
    {
        smallestRemainingElement = findSmallestRemainingElement(array, size, i);
        swapElements(array, i , smallestRemainingElement);
    }
}

int findSmallestRemainingElement(int array[], int size, int currentIndex)
{
    int smallestRemainingElement = currentIndex;
    for (int i = currentIndex+1; i < size; i++)
    {
        if (array[i] < array[smallestRemainingElement])
        {
            smallestRemainingElement = i;
        }
    }
    return smallestRemainingElement;
    
}

void swapElements(int array[], int firstElement, int secondElement)
{
    int temp = array[firstElement];
    array[firstElement] = array[secondElement];
    array[secondElement] = temp;
}

bool isArraySorted(int array[], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        for (int I = i+1; I < size; I++)
        {
            if (array[i] > array[I])
            {
                return false;
            }
        }
    }
    return true;
}