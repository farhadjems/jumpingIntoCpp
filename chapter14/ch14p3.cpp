#include <iostream>

using namespace std;

int main()
{
    int **table = new int*[3];
    for (int i = 0; i < 3; i++)
    {
        table[i] = new  int [3];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &table[i][j] << "\t"; // printing the addresses
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete [] table[i];
    }
    delete[] table;

    
}