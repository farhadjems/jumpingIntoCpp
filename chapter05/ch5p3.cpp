#include <iostream>

using namespace std;

int main()
{
    int input = 0; // variable for taking the inserted value
    int sum = 0; // variable for saving the sum 

    do
    {
        cout << " enter number (or \"0\" to exit): ";
        cin >> input; 
        sum += input;
    } while (input!=0);

    cout << " the sum of all inserted numbers is: " << sum << endl;
}