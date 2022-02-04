#include <iostream>

using namespace std;

void getName (string *firstName, string *lastName) // this function gets the user first name and gets last name if its not determined before 
{
    cout << " enter first name: ";
    cin >> *firstName;

    if (lastName == NULL)
    {
        cout << " enter last name: ";
        cin >> *lastName;
    }
}

int main () // main function
{
    string *p_firstName = NULL, *p_lastName = NULL;
    cout << " using pointers:\n";
    getName(p_firstName, p_lastName);
}