#include <iostream>
#include <map>

using namespace std;

enum menu
{
    finishProgram = 0,
    addItem = 1,
    changeItem = 2,
    listItem = 3,

};

menu showMenu(menu menuKey);
void runProgram(menu menuKey);
void addItemToMap(map<string, string> &addressBook);
void changeItemOfMap(map<string, string> &addressBook);
void listItemOfMap(map<string, string> &addressBook);

int main()
{
    map<string, string> addressBook;
    cout << "This is an address book program\n";
    int key = 1;
    while (key)
    {
        cout << "choose one the below options:" << endl
             << "1. add new address" << endl
             << "2. change address" << endl
             << "3. print the address list" << endl
             << "0. finish program" << endl;
        cin >> key;

        switch (key)
        {
        case finishProgram:
            break;
            break;

        case addItem:
            addItemToMap(addressBook);
            break;

        case changeItem:
            changeItemOfMap(addressBook);
            break;

        case listItem:
            listItemOfMap(addressBook);
            break;

        default:
            cout << "Please Choose one of the existing options in the menu" << endl;
            break;
        }
    }
}

void addItemToMap(map<string, string> &addressBook)
{
    cout << " Enter the name: ";
    string name;
    getline(cin, name, '\t');

    cout << " Enter the email: ";
    string email;
    getline(cin, email, '\t');

    addressBook[name] = email;
}

void changeItemOfMap(map<string, string> &addressBook)
{
    cout << " enter the name: ";
    string name = "";
    getline(cin, name, '\t');

    map<string, string>::iterator itr = addressBook.find(name);

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

void listItemOfMap(map<string, string> &addressBook)
{
    for (map<string, string>::iterator itr = addressBook.begin(), end = addressBook.end(); itr != end; ++itr)
    {
        cout << "name: " << itr->first << '\t' << "address: " << itr->second << endl;
    }
}
