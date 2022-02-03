#include <iostream>

using namespace std;


void bottleSong() // this function prints the "99 bottles of beer song"
{
    for (int i = 99; i > 0; i--)
    {
        cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
        cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    }
}

void calculator() // this function computes the result of applying the given arithmetic operator on two given numbers
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

void sumNumbers() // this function computes the sum of given numbers, enter "0" to finish the computation
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

void startProgram(int menuKey) // this function executes the function chosen by user
{
    switch (menuKey)
    {
    case 1:
        bottleSong(); 
        break;
    case 2:
        calculator();
        break;
    case 3: 
        sumNumbers();
        break;
    default:
        cout << endl << " Ther requested application is not available!\n";
        break;
    }
} 

int main () // main function 
{
    int menuKey = 0;

    while (true)
    {
        cout << "choose one of the below programs:\n 1- bottle song\n 2- calculator\n 3-sum of numbers\n";
        cin >> menuKey;
        if (menuKey>0 && menuKey<4)
        {
            break;
        }
        else
        {
            cout << " please choose number between 1 to 3!!!\n";
        }
    }
    startProgram(menuKey);
}
