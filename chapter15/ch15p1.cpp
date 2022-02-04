#include <iostream>

using namespace std;

struct linkedList
{
    int value;
    linkedList *nextElement;
};
linkedList *list = NULL;

int getValue();
void createElement();
void removeElement();
void printList();

int main()
{
    createElement();
    printList();
    removeElement();
    printList();
}

int getValue()
{
    cout << " enter the value: ";
    int value;
    cin >> value;
    return value;
}

void createElement()
{
    cout << " Create Element Function (enter zero to stop inserting)\n";
    int value = 0;
    while (true)
    {
        value = getValue();     
        if (value == 0)
        {
            return;
        }
        linkedList *newElement = new linkedList;
        newElement->value = value;
        newElement->nextElement = list;
        list = newElement;
    }
}

void removeElement()
{
    cout << " Remove Element Function\n";
    int value = getValue();
    if (list == NULL) // in the case that list is empty
    {
        cout << " list is empty\n";
        return;
    }
    
    if (list->value == value) // in the case that the first element is the element with the considered value
    {
        linkedList *searchedElement = list;
        list = list->nextElement;
        delete searchedElement;
        return;
    }

    if (list->nextElement == NULL) // in the case that list has just one element and that element is not the considered one
    {
        cout << "an element with value \"" << value << "\" does not exist\n";
        return;
    }
    // the mehtod considered here is that if we find the element which its next has the considered value, connect the last one to the next one and delete the found one
    linkedList *lastElement = list;
    linkedList *searchedElement = lastElement->nextElement;
    while (searchedElement != NULL) // looping over the list
    {
        if (searchedElement->value == value) // here the searched element will be found 
        {
            cout << "an element with value \"" << value << "\" has beed found and deleted\n";
            if (searchedElement->nextElement == NULL) // in the case that searched element is at the end of the list
            {
                lastElement->nextElement = NULL;
            }
            else
            {
                lastElement->nextElement = searchedElement->nextElement;
            }
            delete searchedElement;
            return;
        }
        // updating loop condition
        lastElement = searchedElement;
        linkedList *searchedElement = lastElement->nextElement;
    }
    cout << "an element with value \"" << value << "\" does not exist\n";
}

void printList()
{
    cout << "\n----------LIST----------\n";
    if (list == NULL)
    {
        cout << " list is empty\n";
        cout << "----------END----------\n";
        return;
    }
    linkedList *printList = list;
    int i = 1;
    cout <<"element number\tvalue\n";
    while (printList!=NULL)
    {
        cout << i << "\t\t" << printList->value << endl;
        ++i;
        printList = printList->nextElement; 
    }
    cout << "----------END----------\n\n";
}

