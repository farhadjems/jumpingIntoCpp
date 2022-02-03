#include <iostream>

using namespace std;

int main()
{
    for (int i = 99; i > 0; i--) // printing the below lyrics 99 times - in each time, using the loop variable is a good option for changing the lyrics 
    {
        cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
        cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    }
}