#include <iostream>

using namespace std;

void getNamePointer (string* firstName, string* lastName, string* fullName) // this function takes the first and last name of user using pointer
{
    cout << " enter first name: ";
    cin >> *firstName;

    cout << " enter last name: ";
    cin >> *lastName;

    *fullName = *firstName + *lastName;
}

void getNameReference (string& firstName, string& lastName, string& fullName) // this function takes the first and last name of user using references
{
    cout << " enter first name: ";
    cin >> firstName;

    cout << " enter last name: ";
    cin >> lastName;

    fullName = firstName + lastName;
}

int main () // main function
{
    string firstName = "", lastName = "", fullName="";    

    string *p_firstName = &firstName, *p_lastName = &lastName, *p_fullName = &fullName;
    cout << " using pointers:\n";
    getNamePointer(p_firstName, p_lastName, p_fullName);

    cout << " using refrences:\n";
    getNameReference(firstName, lastName, fullName);
}