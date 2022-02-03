#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int createRandomNumber(int high, int low) // this function creates a random number in the range of low to high
{
    int randomNumber = rand()%(high-low) + low;
    return randomNumber;
}

int guessByPlayer(int high, int low) // this function takes the number from user
{
    int number = 0;
    while (true)
    {
        cout << " Guess the Number: ";
        cin >> number;
        if (number > high || number < low)
        {
            cout << " guess between " << low << " and " << high << endl;
        }
        else 
        {
            break;
        } 
    }
    return number;
}

void howIstheGuess(int answer, int guess) // this function compares guess and answer
{
    if (answer == guess)
    {
        cout << " Congrats! you have found the answer!!!\n";
        return;
    }
    else if (answer < guess)
    {
        cout << " guessing high!\n";
    }
    else
    {
        cout << " guessing low!\n";
    }
    
    
    if (abs(answer-guess)<10)
    {
        cout << " you are near to answer!!!\n";
    }
    else
    {
        cout << " you are far from the answer!!!\n";
    }   
}

int main() // main function 
{
    srand(time(NULL));
    int high = 100;
    int low = 0;
    cout << " guess between " << low << " and " << high << endl;
    int answer = createRandomNumber(high, low);
    int guess = 0;
    do
    {
        guess = createRandomNumber(high, low); // to solve the problem by system, change the guess by random number 
        cout << guess << endl;
        howIstheGuess(answer, guess);
        
    } while ((answer - guess));
    
}