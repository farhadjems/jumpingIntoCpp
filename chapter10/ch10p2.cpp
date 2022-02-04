#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArrayWithRandomNumbers(int array[],int size); // this functions fills the given array with random numbers 
void printArray(int array[],int size); // this function prints the array
void sortArray(int array[],int size); // this function sorts the given array
int findSmallestRemainingElement(int array[], int size, int currentIndex); // this function finds the index of smallest element from the given index ot last
void swapElements(int array[], int firstElement, int secondElement); // this function swaps two element which their given indices are given
void printArrayInfo(int array[], int size); // this function prints the max, min, and average of elements in the given array 

int main () // main function
{
    int size = 50; // to change the size of array, just change the value of this variable
    int array[size];
    fillArrayWithRandomNumbers(array, size);
    cout << " Un-sorted array:\n";
    printArray(array, size);
    sortArray(array,size);
    printArrayInfo(array,size);
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

void printArrayInfo(int array[], int size)
{
    int maxElement = array[size-1];
    int minElemnet = array[0];
    int average = 0;

    for (int i = 0; i < size; i++)
    {
        average += array[i];
    }
    average /= size;
    cout << " Maximum Value in the array: " << maxElement << endl;
    cout << " Minimum Value in the array: " << minElemnet << endl;
    cout << " Average Value in the array: " << average << endl;
}