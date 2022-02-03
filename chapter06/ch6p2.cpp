#include <iostream>

using namespace std;

double getNumber(string numberName) // this function gets a value from the user and returns it.
{
    cout << " Enter the value of " << numberName << ": ";
    double number;
    cin >> number;
    return number;
}

string getArithmeticOperator() // this function gets the arithmetic operator from the user: +, -, *, /
{
    cout << " enter he arithmetic operator: ";
    string arithmeticOperator = "<unknown>";
    cin >> arithmeticOperator;
    return arithmeticOperator;
}

double Sum(double number1,double number2) // this function returns the sum of two numbers
{
    return number1 + number2;
    
}

double Minus(double number1, double number2) // this function returns the subtraction of two numbers
{
    return number1 - number2;
}

double Multiply(double number1, double number2) // this function returns the multiplication of two numbers
{
    return number1 * number2;
}

double Divide(double number1, double number2) // this function returns the division of two numbers
{
    if(number2 == 0)
    {
        return 0;
    }
    return number1 / number2;
}

void calculator(double number1, double number2, string arithmeticOpertor) // this function computes the result of the given arithmetic operator on two numbers.
{
    double result = 0;
    if (arithmeticOpertor == "+")
    {
        result = Sum(number1, number2);
    }
    else if (arithmeticOpertor == "-")
    {
        result = Minus(number1, number2);
    }
    else if (arithmeticOpertor == "*")
    {
        result = Multiply(number1, number2);
    }
    else if (arithmeticOpertor == "/")
    {
        result = Divide(number1, number2);
    }
    else 
    {
        cout << " the operator is not arithmetic\n";
        return;
    }
    cout << number1 << arithmeticOpertor << number2 << "=" << result;
}

int main() // main function
{
    double number1 = getNumber("first number");
    string arithmeticOperator = getArithmeticOperator();
    double number2 = getNumber("second number");
    calculator(number1, number2, arithmeticOperator);
}