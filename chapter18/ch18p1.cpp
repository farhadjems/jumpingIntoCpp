#include <iostream>
#include <map>

using namespace std;

enum menu
{   
    addItem = 1, changeItem = 2, listItem = 3, finishProgram = 4,
};

map<string,string> addressBook;
menu showMenu(menu menuKey);
void runProgram(menu menuKey);
void addItemToMap();
void changeItemOfMap();
void listItemOfMap();

int main()
{
    menu menuKey = finishProgram;

    cout << " This is an address book program\n";
    do
    {
        menuKey = showMenu(menuKey);
        runProgram(menuKey);
    } while (menuKey != finishProgram);
}

menu showMenu(menu menuKey)
{
    int key = 4;
    while (true)
    {
        cout << " choose one the below options:\n1- add new address\n2- change address\n3- print the address list\n4- quit\n";
        cin >> key;
        if (key < 5 && key > 0)
        {
            break;
        }
    }
    switch (key)
    {
    case 1:
        menuKey = addItem;
        break;
    
    case 2:
        menuKey = changeItem;
        break;

    case 3:
        menuKey = listItem;
        break;

    case 4:
        menuKey = finishProgram;
        break;
    }
    return menuKey;
}

void runProgram(menu menuKey)
{
    switch (menuKey)
    {
    case addItem:
        addItemToMap();
        break;
    
    case changeItem:
        changeItemOfMap();
        break;
    
    case listItem: 
        listItemOfMap();
        break;
    
    case finishProgram:
        return;
        break;
    }
}

void addItemToMap()
{
    cout << " Enter the name: ";
    string name;
    getline(cin, name, '\t');

    cout << " Enter the email: ";
    string email;
    getline(cin, email, '\t');

    addressBook[name] = email;
}

void changeItemOfMap()
{
    cout << " enter the name: ";
    string name = "";
    getline(cin, name, '\t');

    map<string,string>::iterator itr = addressBook.find(name);

    if (itr != addressBook.end())
    {
        cout << " enter the new address of " << itr->first << ": ";
        cin >> itr->second;
    }
    else
    {
        cout << " the name entered is not found!!!\n";
    }
}

void listItemOfMap()
{
    for (map<string,string>::iterator itr = addressBook.begin(), end = addressBook.end(); itr != end; ++itr)
    {
        cout << "name: " << itr->first << '\t' << "address: " << itr->second << endl;
    }
}




