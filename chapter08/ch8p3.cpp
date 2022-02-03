#include <iostream>

using namespace std;

enum playerTurn {
    firstPlayer = 1, secondPlayer = 2,
};

playerTurn determineWhosTurn(playerTurn whosTurn); // this function changes the player turn
bool isPlayerWinner(string slot0,string slot1,string slot2,string slot3,string slot4,string slot5,string slot6,string slot7,string slot8); // this function checks if a players wins the game or not 
int getSlot(playerTurn whosTurn); // this function gets the chosen slot from user and returns the slot number if it is OK
string fillSlot(playerTurn whosTurn); // this function fills the chosen slot
void printTable (string slot1,string slot2,string slot3,string slot4,string slot5,string slot6,string slot7,string slot8,string slot9); // this function prints board

int main() // main function
{
    string slot1 = "eee", slot2 = "eee", slot3 = "eee", slot4 = "eee", 
    slot5 = "eee", slot6 = "eee", slot7 = "eee", slot8 = "eee", slot9 = "eee";

    
    playerTurn whosTurn = firstPlayer;
    int slot = 0;

    do
    {
        slot = getSlot(whosTurn);
        
        switch (slot)
        {
        case 1:
            if (slot1 == "eee")
            {
                slot1 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;
        
        case 2:
            if (slot2 == "eee")
            {
                slot2 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 3:
            if (slot3 == "eee")
            {
                slot3 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 4:
            if (slot4 == "eee")
            {
                slot4 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 5:
            if (slot5 == "eee")
            {
                slot5 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 6:
            if (slot6 == "eee")
            {
                slot6 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 7:
            if (slot7 == "eee")
            {
                slot7 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 8:
            if (slot8 == "eee")
            {
                slot8 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;

        case 9:
            if (slot9 == "eee")
            {
                slot9 = fillSlot(whosTurn);
                whosTurn = determineWhosTurn(whosTurn);
            }
            else{
                cout << "the chosen slot is full!";
            }
            break;
        }
        printTable(slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9);

    } while (!isPlayerWinner(slot1, slot2, slot3, slot4, slot5, slot6, slot7, slot8, slot9));
    
    
}

playerTurn determineWhosTurn(playerTurn whosTurn)
{
    if (whosTurn == firstPlayer)
    {
        return secondPlayer;
    }
    
    if (whosTurn == secondPlayer)
    {
        return firstPlayer; 
    }
}

bool isPlayerWinner(string slot1,string slot2,string slot3,string slot4,string slot5,string slot6,string slot7,string slot8,string slot9)
{
    string winner = "";
    if (slot1 != "eee" && slot1 == slot2 && slot2 == slot3)
    {
        winner = slot2;
    }
    
    if (slot4 != "eee" && slot4 == slot5 && slot5 == slot6)
    {
        winner = slot5;
    }

    if (slot7 != "eee" && slot7 == slot8 && slot8 == slot9)
    {
        winner = slot8;
    }

    if (slot1 != "eee" && slot1 == slot4 && slot4 == slot7)
    {
        winner = slot4;
    }

    if (slot2 != "eee" && slot2 == slot5 && slot5 == slot8)
    {
        winner = slot4;
    }

    if (slot3 != "eee" && slot3 == slot6 && slot6 == slot9)
    {
        winner = slot5;
    }

    if (winner != "")
    {
        cout << " \n !!!Player ";
        if (winner == "xxx")
        {
            cout << "1 ";
        }
        else
        {
            cout << "2 ";
        }
        cout << "has won the game!!!\n";
        return true;
    }

    return false;
}

int getSlot(playerTurn whosTurn)
{
    int slot;
    if (whosTurn == firstPlayer)
    {
        cout << " player 1's turn to choose slot: ";
    }
    else
    {
        cout << " player 2's turn to choose slot: ";
    }

    cin >> slot;
    return slot;
}

string fillSlot(playerTurn whosTurn)
{
    if (whosTurn == firstPlayer)
    {
        return "xxx";
    }
    
    else
    {
        return "ooo";
    }
}

void printTable (string slot1,string slot2,string slot3,string slot4,string slot5,string slot6,string slot7,string slot8,string slot9)
{
    cout << slot1 << '\t' << slot2 << '\t' << slot3 << '\t' <<endl;
    cout << slot4 << '\t' << slot5 << '\t' << slot6 << '\t' <<endl;
    cout << slot7 << '\t' << slot8 << '\t' << slot9 << '\t' <<endl; 
}