#include <iostream>
#include <cmath>

using namespace std;

bool isConditionAvailable(int number); // this function checks that the condition is available for the given number
bool isNumberPrime(int number); // this function checks that if the given number is prime or not 
bool isDivisibleToNumber(int number, int divisor); // this function checks that if the number is divisable to the given divisor or not
int numberOfPrimeFactors (int number , int primeFactor); // this function determines the number of the given prime factor of the given number 


int main()
{
    int firstNumber = 1;
    int lastNumber = 1000;

    for (int i = firstNumber; i < lastNumber+1; i++)
    {
        if (isConditionAvailable(i))
        {
            cout << i << endl;
        }
    }
}

bool isConditionAvailable(int number)
{
    int primeFactorsSum = 0;
    int primeFactorRepeats = 0;
    for (int  i = 2; i < number/2 + 1; i++)
    {
        if (isNumberPrime(i))
        {
            if (isDivisibleToNumber(number,i))
            {
                primeFactorRepeats = numberOfPrimeFactors(number, i);
                primeFactorsSum += primeFactorRepeats * i;
            }
        }
    }

    if (isNumberPrime(primeFactorsSum))
    {
        return true;
    }
    return false;
}

bool isNumberPrime(int number)
{
    if (number == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < sqrt(number)+1; i++)
        {
            if (number % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}

bool isDivisibleToNumber(int number, int divisor)
{
    if (number % divisor == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int numberOfPrimeFactors (int number , int primeFactor)
{
    int primeFactorRepeated = 0;
    while (true)
    {
        if (number % primeFactor == 0)
        {
            number /= primeFactor;
            primeFactorRepeated++;
        }
        else 
        {
            break;
        }
    }
    return primeFactorRepeated;
}