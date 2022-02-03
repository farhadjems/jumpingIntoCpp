#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum coinSide  // this enum is useful for detemining the side of coin
{
    heads, tails,
};

coinSide flipTheCoin() // this function determines the side coin using the residual of random number related to two
{
    int headsOrTails = rand()%2;

    if (headsOrTails == 1)
    {
        return heads;
    }
    else
    {
        return tails;
    }
}

void printResult (coinSide coin) // this function shows the result of flipping 
{
    cout << " The result is: ";
    if (coin == heads)
    {
        cout << "Heads.\n";
    }
    else
    {
        cout << "Tails.\n";
    }
}

int main() // main function
{
    srand(time(NULL));
    coinSide coin = flipTheCoin();
    printResult(coin);
}