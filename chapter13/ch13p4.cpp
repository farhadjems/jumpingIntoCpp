#include <iostream>

using namespace std;

int calculator (int num1, int num2, int &multiply) // this function gets two numbers and compute the sum and multiply of them 
{
    int sum = num1 + num2;
    multiply = num1 * num2;
    return sum;
}

int main() // main function 
{
    int num1 = 10;
    int num2 = 12;
    int multiply = 0;
    int sum = calculator(num1, num2, multiply);
    cout << num1 << "+" << num2 <<"=" << sum << endl;
    cout << num1 << "*" << num2 <<"=" << multiply << endl;
}