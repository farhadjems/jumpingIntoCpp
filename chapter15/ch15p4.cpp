#include <iostream>

using namespace std;

enum SlotType
{
    emt = 1,
    XXX = 2,
    OOO = 3,
};

struct TicTacToe
{
    SlotType slot;
    TicTacToe *nextSlot;
};

void addNewSlot(TicTacToe *slotList)
{
    TicTacToe *newSlot = new TicTacToe;
    newSlot->slot = emt;
    newSlot->nextSlot = slotList;
    slotList = newSlot;
}

int main()
{
}