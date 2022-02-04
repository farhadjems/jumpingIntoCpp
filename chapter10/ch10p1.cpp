#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArrayWithRandomNumbers(int array[],int size); // this function fills the given array with random numbers
void printArray(int array[],int size); // this function prints the given array
void sortArray(int array[],int size); // this function sorts the given array
int findSmallestRemainingElement(int array[], int size, int currentIndex); // this function finds the smallest element in array from the given index to end 
void swapElements(int array[], int firstElement, int secondElement); // this function swaps two elements which their indices are given


int main () // main function 
{
    int size = 10; // to change the size of array, just change the value of this variable
    int array[size];
    fillArrayWithRandomNumbers(array, size);
    cout << " Un-sorted array:\n";
    printArray(array, size);
    sortArray(array,size);
    cout << " Sorted array:\n";
    printArray(array,size);
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