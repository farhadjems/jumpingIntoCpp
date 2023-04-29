#include <iostream>
using namespace std;

void towerOfHanoi(int numberOfDisks, char from_rod, char to_rod, char aux_rod)
{
    if (numberOfDisks == 0)
    {
        return;
    }
    towerOfHanoi(numberOfDisks - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << numberOfDisks << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(numberOfDisks - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int numberOfDisks = 0;
    cout << "Enter number of disks: ";
    cin >> numberOfDisks;
    cout << "--------------------------------";
    // A, B and C are names of rods
    towerOfHanoi(numberOfDisks, 'A', 'C', 'B');
    cout << "--------------------------------";
    return 0;
}