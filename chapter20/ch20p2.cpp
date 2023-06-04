#include <iostream>
using namespace std;
int sumValues(int *values, int n)
{
    int sum; // !this variable must be initialized, it's not zero by default
    // int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += values[i];
    }
    return sum;
}
int main()
{
    int size;
    cout << "Enter a size: ";
    cin >> size;
    int *values = new int[size];
    int i; // !this variable must be initialized, it's not zero by default
    // int i = 0;
    while (i < size)
    {
        cout << "Enter value to add: ";
        cin >> values[++i]; // !since the incrementing operator ++ called before the variable
        // !this operator executes first. you have to do it later, or use: i++
    }

    // ! I added below loop to see the effect of using ++i and i++
    for (int j = 0; j < size; j++)
    {
        cout << values[j] << endl;
    }

    cout << "Total sum is: " << sumValues(values, size);
}