#include <iostream>

using namespace std;

int main()
{
    cout << "Division of two numbers\n enter the Numerator: ";
    double numerator; // defining the numerator variable
    cin >> numerator; // taking the number from user
    cout<< " Enter the denominator: "; 
    double denominator; // defining the denominator 
    cin >> denominator; // taking the number from user
    cout << " the division of given two numbers is: " << numerator / denominator << endl; // printing the result of division 
}