#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum slotMachine // this enum considers the environment of variables for slot machine 
{
    lemon, watermelon, strawberry, tangerine, orange, banana,
};

slotMachine createRandomSlot(); // this function choose the slot element based on a random number
void printResult(slotMachine slot1,slotMachine slot2,slotMachine slot3); // this function prints the result of slot machine 
void checkResult(slotMachine slot1,slotMachine slot2,slotMachine slot3); // this function checks the result of slot machine 
string enumToString(slotMachine slot); // this function turns the enum to string 

int main() // main function
{
    srand(time(NULL));

    slotMachine slot1 = createRandomSlot(), slot2 = createRandomSlot(), slot3 = createRandomSlot();

    printResult(slot1, slot2, slot3);
    checkResult(slot1, slot2, slot3);
}

slotMachine createRandomSlot()
{
    int randomNumber = rand() % 6;

    switch (randomNumber)
    {
    case 0:
        return lemon;
        break;
    
    case 1:
        return watermelon;
        break;
    
    case 2:
        return strawberry;
        break;
    
    case 3:
        return tangerine;
        break;
    
    case 4:
        return orange;
        break;
    
    case 5:
        return banana;
        break;
    }
}

void printResult(slotMachine slot1,slotMachine slot2,slotMachine slot3)
{
    string stringSlot1, stringSlot2, stringSlot3;
    stringSlot1 = enumToString(slot1);
    stringSlot2 = enumToString(slot2);
    stringSlot3 = enumToString(slot3);
    
    cout << endl << stringSlot1 << '\t' << stringSlot2 << '\t' << stringSlot3 << endl;
}

void checkResult(slotMachine slot1,slotMachine slot2,slotMachine slot3)
{
    if (slot1 == slot2 && slot2 == slot3)
    {
        cout << " you have won the game !!!!\n";
    }
}

string enumToString(slotMachine slot)
{
    
    switch (slot)
    {
    case 0:
        return "lemon";
        break;
    
    case 1:
        return "watermelon";
        break;
    
    case 2:
        return "strawberry";
        break;
    
    case 3:
        return "tangerine";
        break;
    
    case 4:
        return "orange";
        break;
    
    case 5:
        return "banana";
        break;
    }
}