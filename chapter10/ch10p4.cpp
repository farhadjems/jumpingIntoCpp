#include <iostream> 

using namespace std;

enum ticTacToe // this enum is the type considers the options to fill the board
{
    e = 0, x = 1, o = 2,
};

enum turn // this enum is the type considers the turn of players
{
    player1, player2,
};

bool isGameOver(ticTacToe table[][3]); // this function checks the board if is game finished or not
void getValue(ticTacToe table[][3], turn whosTurn); // this function takes the slot number from user and fills it by knowing the turn if the slot is empty
turn changeTurn(turn whosTurn); // this function changes the turn between players
void printTable(ticTacToe table[][3]); // this function prints the board

int main()
{
    ticTacToe table[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j] = e;
        }
    }
    
    turn whosTurn = player1;
    do
    {
        getValue(table, whosTurn);
        printTable(table);
        whosTurn = changeTurn(whosTurn);
    } while (!isGameOver(table));
}


bool isGameOver(ticTacToe table[][3])
{
    int j = 1;
    for (int i = 0; i < 3; i++)
    {
        if (table[i][j] != e && table[i][j-1] == table[i][j] && table[i][j+1] == table[i][j])
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
    
    int i = 1;
    for (int j = 0; j < 3; j++)
    {
        if (table[i][j] != e && table[i-1][j] == table[i][j] && table[i+1][j] == table[i][j])
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
    return false;
}   

void getValue(ticTacToe table[][3], turn whosTurn)
{
    ticTacToe slot = e;
    int slotNumber = 0;
    bool slotFilledOK = false;
    do
    {
        cout << " enter the slot number (a number between 1 to 9): ";
        cin >> slotNumber; 

        int slotI = (slotNumber - 1) / 3;
        int slotJ = (slotNumber - 1) % 3;

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

void printTable(ticTacToe table[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << table[i][j] << '\t';
        }
        cout << endl;
    }
    
}