#include <iostream>

using namespace std;

void multiTable(int sizeX, int sizeY, int **table) // this function computes the multi table and saves it in table
{
    
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            table[i][j] = (i+1)*(j+1);
        }
    }
}   

void printTable(int sizeX, int sizeY, int **table) // this function prints the table
{
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() // main function
{
    cout << " enter the x-size of table: ";
    int sizeX;
    cin >> sizeX;

    cout << " enter the y-size of table: ";
    int sizeY;
    cin >> sizeY;
    int **table = new int*[sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        table[i] = new int[sizeY];
    }

    multiTable(sizeX, sizeY, table);
    printTable(sizeX, sizeY, table);
    
    for (int i = 0; i < sizeX; i++)
    {
        delete [] table[i];
    }
    delete [] table;
    
}