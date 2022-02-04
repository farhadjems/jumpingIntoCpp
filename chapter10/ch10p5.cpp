#include <iostream> 

using namespace std;

enum ticTacToe{
    e = 0, x = 1, o = 2,
};

enum turn {
    player1, player2,
};

bool isGameOver(ticTacToe table[][8], int size); 
void getValue(ticTacToe table[][8], int size, turn whosTurn);
turn changeTurn(turn whosTurn);
void printTable(ticTacToe table[][8], int size);
int getSize(); // this function takes the size of board from user


int main()
{ 
    ticTacToe table[8][8];
    int size = getSize();    
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            table[i][j] = e;
        }
    }
    
    turn whosTurn = player1;
    do
    {
        getValue(table, size, whosTurn);
        printTable(table, size);
        whosTurn = changeTurn(whosTurn);
    } while (!isGameOver(table, size));
}


bool isGameOver(ticTacToe table[][8], int size)
{
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size-2; j++)
        {
            if (table[i][j] != e && table[i][j-1] == table[i][j] && table[i][j+1] == table[i][j] && table[i][j] == table[i][j+2])
        {
            if (table[i][j] == x)
            {
                cout << "\n player 1 has won the game!!! \n";
            }
            if (table[i][j] == o)
            {
                cout << "\n player 2 has won the game!!! \n";
            }
            return true;
        }
        }
        
    }
    
    
    for (int j = 0; j < size; j++)
    {
        for (int i = 1; i < size-2; i++)
        {
            if (table[i][j] != e && table[i-1][j] == table[i][j] && table[i+1][j] == table[i][j] && table[i][j] == table[i+2][j])
            {
                if (table[i][j] == x)
                {
                    cout << "\n player 1 has won the game!!! \n";
                }
                if (table[i][j] == o)
                {
                    cout << "\n player 2 has won the game!!! \n";
                }
                return true;
            }
        }
        
    }
    return false;
}   

void getValue(ticTacToe table[][8], int size, turn whosTurn)
{
    ticTacToe slot = e;
    int slotNumber = 0;
    bool slotFilledOK = false;
    do
    {
        cout << " enter the slot number (a number between 1 to " << size*size <<"): ";
        cin >> slotNumber; 

        int slotI = (slotNumber - 1) / size;
        int slotJ = (slotNumber - 1) % size;

        if (table[slotI][slotJ] == e)
        {
            slotFilledOK = true;
            if (whosTurn == player1)
            {
                table[slotI][slotJ] = x;
            }

            if (whosTurn == player2)
            {
                table[slotI][slotJ] = o;
            }
            break;
        }

        cout << endl << " the chosen slot is filled, please enter another slot\n";
    } while (!slotFilledOK);
    
}

turn changeTurn(turn whosTurn)
{
    if (whosTurn == player1)
    {
        whosTurn = player2;
    }

    else
    {
        whosTurn = player1;
    }
    return whosTurn;
}

void printTable(ticTacToe table[][8], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << table[i][j] << '\t';
        }
        cout << endl;
    }
}

int getSize()
{
    bool isSizeOK = true;
    int size = 0;
    do
    {
        cout << " enter the size of the board (min is 4 and max is 8): ";
        cin >> size;
        if (size > 8 || size < 4)
        {
            cout << " the min size of board is 4 and max is 8, please enter the number in range.\n";
        }
        else
        {
            break;
        }
    } while (!isSizeOK);
    return size;
}