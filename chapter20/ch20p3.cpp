#include <iostream>
using namespace std;
int fibonacci(int n)
{
    // ! since the recursion is based on the summation of two last numbers
    // ! one base case is not enough! whatever n is, in the recursive calls
    // ! n would be "1", so that the terms (n-1) and (n-2) would be 0 and -1
    // ! since there is no base case to stop "-1" stack, recursive calls would continue
    // ! untill the stack gets full, causing "stack overflow" error
    if (n == 0)
    {
        return 0;
    }

    // ! By adding below loop, the problem of "-1" stack will be solved
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter the number to compute fibonacci for: " << endl;
    cin >> n;
    cout << fibonacci(n);
}