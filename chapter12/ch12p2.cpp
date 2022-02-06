#include <iostream> 

using namespace std;

int main()
{
    int i = 0; // this variable need a slot in memory which its size is 4 bytes

    int votes [10]; // this array need 10 slots in memory, each of them is in size of 4 bytes

    /* 
        votes[9] has the distance equal of 10 variables which each of them is in size of 4 bytes to votes[0]   
        variable i is in different location of array votes, its not between array's elements
    */ 
}