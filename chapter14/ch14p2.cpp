#include <iostream>

using namespace std;

void multiTable(int sizeX, int sizeY, int sizeZ, int ***table) // this function computes the elements of mutil table 
{
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            for (int k = 0; k < sizeZ; k++)
            {
                table[i][j][k] = (i+1)*(j+1)*(k+1);
            }
        }
    }
}   

void printTable(int sizeX, int sizeY, int sizeZ, int ***table) // this function prints the table in levels 
{
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            for (int k = 0; k < sizeZ; k++)
            {
                cout << table[i][j][k] << "\t";
            }
            cout << endl;      
        }
        cout << "\n***\n";
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

    cout << " enter the z-size of table: ";
    int sizeZ;
    cin >> sizeZ; 

    int ***table = new int**[sizeX];
    for (int i = 0; i < sizeX; i++)
    {
        table[i] = new int*[sizeY];
        for (int j = 0; j < sizeY; j++)
        {
            table[i][j] = new int[sizeZ];
        }        
    }

    multiTable(sizeX, sizeY, sizeZ, table);
    printTable(sizeX, sizeY, sizeZ, table);
    
   for (int i = 0; i < sizeX; i++)
   {
       for (int j = 0; j < sizeY; j++)
       {
           delete[] table[i][j];
       }
       delete[] table[i];
   }
   delete [] table;
   
}