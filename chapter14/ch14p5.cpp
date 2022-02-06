#include <iostream> 

using namespace std;

struct sizeInfo 
{
    int x;
    int y;
};

void getGBoardSize(sizeInfo &size); // this function takes the size of board from user 
void changePlayerTurn(int &playerTurn); // this function changes player turn
bool isGameOver(char **board, sizeInfo &size, char &playerChar);
void printBoard(char **board, sizeInfo &size);
void setPlayerChoice(int &playerTurn, char **board, sizeInfo &size);

int main()
{
    // if you rather to play with anothe chars, just change below variables
    char emptyChar = '-';
    char player1Char = '+';
    char player2Char = '*';
    
    sizeInfo size; // this variabel holds the size of the board
    getGBoardSize(size); 

    char **board = new char*[size.x];
    for (int i = 0; i < size.x; i++)
    {
        board[i] = new char[size.y];
        for (int j = 0; j < size.y; j++)
        {
            board[i][j] = emptyChar;
        }
    }
    
    cout << " \n player 1 sign is "<< player1Char << "\n player 2 sign is " << player2Char <<"\n\n";
    
    int playerTurn = 1;

    while (!isGameOver(board, size, player1Char) && !isGameOver(board, size, player2Char))
    {
        printBoard(board, size);
        setPlayerChoice(playerTurn, board, size);
        changePlayerTurn(playerTurn);
    }
    
    changePlayerTurn(playerTurn);
    cout << "\n\n PLAYER " << playerTurn << " Has WON THE GAME!\n\n";
    printBoard(board, size);
    cout << endl << endl;

    return 0;
}

void getGBoardSize(sizeInfo &size)
{
    cout << "enter the width of the board: ";
    cin >> size.y;

    cout << "enter the Height of the board: ";
    cin >> size.x;
    
}

void changePlayerTurn(int &playerTurn)
{
    if (playerTurn == 1)
    {
        playerTurn = 2;
    }
    else if (playerTurn == 2)
    {
        playerTurn = 1;
    }
}

bool isGameOver(char **board, sizeInfo &size, char &playerChar)
{
    // horizontal check
    for (int i = 0; i < size.x; i++)
    {
        for (int j = 0; j < size.y - 3; j++)
        {
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3] && board[i][j] == playerChar)
            {
                return true;
            }
        }
    }
    
    // vertical check
    for (int j = 0; j < size.y; j++)
    {
        for (int i = 0; i < size.x - 3; i++)
        {
            if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j] && board[i][j] == playerChar)
            {
                return true;
            }
        }
    }
    
    // oblique check
    for (int i = 0; i < size.x - 3; i++)
    {
        for (int j = 0; j < size.y - 3; j++)
        {
            if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3] && board[i][j] == playerChar)
            {
                return true;
            }
        } 
    }
   
    // oblique check
    for (int i = size.x - 1; i >= 3 ; i--)
    {
        for (int j = 0; j < size.y - 3; j++)
        {
            if (board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3] && board[i][j] == playerChar)
            {
                return true;
            }
        }
    }

    return false;
}

void printBoard(char **board, sizeInfo &size)
{
    cout << '\t';
    for (int i = 0; i < size.y; i++)
    {
        cout << i+1 << " ";
    }
    cout << endl;

    for (int i = 0; i < size.x; i++)
    {
        cout << '\t';
        for (int j = 0; j < size.y; j++)
        {
            cout << board[i][j] <<" ";
        }
        cout << endl;
    }
}

void setPlayerChoice(int &playerTurn, char **board, sizeInfo &size)
{
    int columnNumber = 0;
    do
    {
        cout << "player " << playerTurn << ", choose a column: ";
        cin >> columnNumber;
        columnNumber--;
        if (columnNumber < 0 || columnNumber > size.y)
        {
            cout << " the chosen column does not exist!, try again\n";
        }
        else if (board[0][columnNumber] != '-')
        {
            cout << " the chosen column is full! try again\n";
        }
        else
        {
            break;
        }
    } while (true);
    
    for (int i  = size.x - 1; i >= 0; i--)
    {
        if (board[i][columnNumber] == '-')
        {
            if (playerTurn == 1)
            {
                board[i][columnNumber] = '+';
            }
            
            if (playerTurn == 2)
            {
                board[i][columnNumber] = '*';
            }
            break;
        }
    }
}




