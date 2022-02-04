#include <iostream>

using namespace std;

struct linkedList 
{
    string name;
    linkedList *nextElement;
};

void insertElement(linkedList **list, string name);
string getName();
void findElement(linkedList *list, string searchedElement);
void printList(linkedList *list);

int main()
{
    linkedList *list = new linkedList;
    list->nextElement = NULL;

    string name = "";
    while (name != " ")
    {
        name = getName();
        insertElement(&list, name);
    }
    printList(list);
    cout << " enter the name that you ar elooking for: ";
    getline (cin, name, '\n');

    if (name != " ")
    {
        findElement(list, name);
    }
}

void insertElement(linkedList **list, string name) // this function adds new element to the list
{
    linkedList *newElement = new linkedList;
    newElement->name = name;
    newElement->nextElement = *list;
    *list = newElement;
}

string getName() // this function gets the new name - and useful for getting the searched item
{
    cout << " enter the name (or space to quit): ";
    string name = " ";
    getline(cin, name, '\n');
    return name;
}

void findElement(linkedList *list, string searchedName) // this function finds the given name's element
{
    linkedList *searchList = list;

    while (searchList != NULL)
    {
        if (searchList->name == searchedName)
        {
            cout << " the name \"" << searchedName << "\" is in the list\n";
            return;
        }
        searchList = searchList->nextElement;
    }
    cout << " the name \"" << searchedName << "\" is not in the list\n";
}

void printList(linkedList *list)
{
    linkedList *printedList = list;
    int i = 1;

    cout << "----------LIST----------\n";
    cout << "number\tvalue\n";
    while (printedList != NULL)
    {
        cout << i << '\t' << printedList->name << endl;
        ++i;
        printedList = printedList->nextElement;
    }
    cout << "-----------END----------\n";
}