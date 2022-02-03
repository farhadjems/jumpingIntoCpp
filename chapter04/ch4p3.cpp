#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arithmeticOperator = "<unknown>"; // this variable takes the considered arithmetic operator
    double number1 = 0, number2 = 0; // this variables are defined to take the entered numbers from user

    cout << " enter the first number: ";
    cin >> number1;

    cout << " enter he arithmetic operator: ";
    cin >> arithmeticOperator;

    cout << "enter the second number: ";
    cin >> number2;

    if (arithmeticOperator == "+") // if the entered operator is +
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1+number2<< endl;
    }
    else if (arithmeticOperator == "-") // if the entered operator is -
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1-number2<< endl;
    }
    else if (arithmeticOperator == "*")// if the entered operator is *
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1*number2<< endl;
    }
    else if (arithmeticOperator == "/")// if the entered operator is /
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1/number2<< endl;
    }
    else // if the entered operator is wrong !
    {
        cout << " the inserted operator is wrong!\n";
    }
}