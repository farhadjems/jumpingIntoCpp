#include <iostream>

using namespace std;

int main()
{
    int age1, age2; // defining two variables for saving the inserted number from user

    cout << " enter the first person's age: ";
    cin >> age1; // taking the first number

    cout << " enter the socond person's age: ";
    cin >> age2; // taking the second number

    if (age1 > age2 ) // checking if the fisrt person age is greater or not 
    {
        cout << " first person is older!\n";
    }
    else if (age1 < age2 ) // checking if the second person is greater or not 
    {
        cout << " second person is older!\n";
    }
    else // based on the above structure - the only remaining condition is two values are equal
    {
        cout << " they are at the same age!\n";    
    }

    if (age1 >= 100 && age2 >= 100)   // check if both ages are greater than 100 or not 
    {
        cout << " wow, they have lived at leased a century!!!\n";
    }
}