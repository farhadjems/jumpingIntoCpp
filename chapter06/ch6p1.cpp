#include <iostream>

using namespace std;
 
void bottleSong() // this function prints the "99 bottles of beer" song 
{
    for (int i = 99; i > 0; i--)
    {
        cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
        cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    }
}

void calculator() // this function is an arithmetic calculator
{
    string arithmeticOperator = "<unknown>";
    double number1 = 0, number2 = 0;

    cout << " enter the first number: ";
    cin >> number1;

    cout << " enter he arithmetic operator: ";
    cin >> arithmeticOperator;

    cout << "enter the second number: ";
    cin >> number2;

    if (arithmeticOperator == "+")
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1+number2<< endl;
    }
    else if (arithmeticOperator == "-")
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1-number2<< endl;
    }
    else if (arithmeticOperator == "*")
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1*number2<< endl;
    }
    else if (arithmeticOperator == "/")
    {
        cout << number1 << arithmeticOperator << number2 <<"="<< number1/number2<< endl;
    }
    else
    {
        cout << " the inserted operator is wrong!\n";
    }

}

void sumNumbers() // this function computes the sum of entered numbers, the process will be ended by entering "0"
{
    int input = 0;
    int sum = 0;
    do
    {
        cout << " enter number (or \"0\" to exit): ";
        cin >> input;
        sum += input;
    } while (input!=0);

    cout << " the sum of all inserted numbers is: " << sum << endl;
}

void startProgram(int menuKey) // this function executes the function related to the chosen option from user
{
    if (menuKey == 1)
    {
        bottleSong();
    }
    else if(menuKey == 2)
    {
        calculator();
    }
    else
    {
        sumNumbers();
    }
    
}

int main() // main function
{
    int menuOption = 0;
    string menuMessage = "Choose one option:\n1.bottles song\n2.calculator\n3.sum numbers\n";

    int firstKey = 1;
    int lastKey = 3;

    do
    {
        cout << menuMessage;
        cin >> menuOption;
    } while (menuOption < firstKey || menuOption > lastKey);
    
    cout << " you've chosen option number " << menuOption << endl;

    startProgram(menuOption);
}