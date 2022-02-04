#include <iostream>

using namespace std;

int findElement(int array[], int size, int value, int index);
int findElementFaster (int array[], int size, int value, int startIndex, int lastIndex); // !!!NOTE THAT this function works properly if the array is sorted !!!

int main()
{
    int const size = 10;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
    
    int index_2 = findElement(array, size, 2, 0);
    cout << index_2 << endl;

    int index_3 = findElementFaster(array, size, 3, 0, size-1);
    cout << index_3<< endl;
}

int findElement(int array[], int size, int value, int index)
{
    if (index == size) // base case - if the index has passed over the array and no element found 
    {
        return -1;
    }
    
    if (array[index] == value) // base case - if the element is found
    {
        return index;
    }
    findElement(array, size, value, index+1);
}

int findElementFaster (int array[], int size, int value, int startIndex, int lastIndex) // !!!NOTE THAT this function works properly if the array is sorted !!!
{
    int midIndex = (startIndex + lastIndex) / 2;

    if (midIndex == size) // base case - defensive - if no element found
    {
        return -1;
    }

    if (array[midIndex] == value)
    {
        return midIndex;
    }
    if (array[midIndex-1] == value)
    {
        return midIndex-1;
    }
    
    if (array[midIndex+1] == value)
    {
        return midIndex+1;
    }
    
    if (array[midIndex] < value)
    {
        findElementFaster(array, size, value, startIndex, midIndex);
    }
    
    if (array[midIndex] > value)
    {
        findElementFaster(array, size, value, midIndex, lastIndex);
    }
}


