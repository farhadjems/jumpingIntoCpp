#include <iostream> 

using namespace std;

int power(int base,int exponent);

int main()
{
    cout << " enter base: ";
    int base = 0; 
    cin >> base;
    
    cout << " enter exponent: ";
    int exponent = 0; 
    cin >> exponent;
    
    cout << base << " ^ " << exponent << " = " << power(base, exponent) << endl;
}

int power(int base,int exponent)
{
    if (exponent == 0) // base case - if the exponent is zero
    {
        return 1;
    }
    
    if (exponent == 1) // base case - if the exponent is one 
    {
        return base;
    }
    
    return base * power(base, exponent-1);
}