#include <iostream> 

using namespace std;

struct linkedList
{
    int value;
    linkedList *nextElement;
};

int getValue();
linkedList *insertElement(linkedList *list, int value);
void printList(linkedList *list);

linkedList *removeElement(linkedList *element, int value);

int main()
{
    linkedList *list = NULL;

    int value = 1;
    while (value)
    {
        value = getValue();
        if (value != 0)
        {
            list = insertElement(list,value);    
        }
    }
    
    printList (list);

    cout << " enter the value to remove\n";
    value = getValue();
    list = removeElement(list, value);
    printList(list);
}

int getValue()
{
    cout << " enter value (zero to finish inserting): ";
    int value ;
    cin >> value;
    return value; 
}

linkedList *insertElement(linkedList *list, int value)
{
    if (list == NULL) // base case - if the list is empty
    {
        list = new linkedList;
        list->value = value;
        list->nextElement = NULL;
        return list;
    }
    
    linkedList *newElement = new linkedList;
    newElement->value = value;
    newElement->nextElement = list;
    list = newElement;
    return list;
}

void printList(linkedList *list)
{
    linkedList *printedList = list;
    cout << "-----LIST-----\n";
    while (printedList != NULL) 
    {
        cout << printedList->value << endl;
        printedList = printedList -> nextElement;
    }
    cout << "-----END-----\n";
}

linkedList *removeElement(linkedList *element, int value)
{
    if (element == NULL) // base case - if the list is empty or we are at the end of list and there was no considered element
    {
        return NULL; 
    }

    if (element->value == value) // base case - if the considered element is found
    {
        linkedList *nextElement = element->nextElement;
        delete element;
        return nextElement;
    }
    element->nextElement = removeElement(element->nextElement, value);
    return element;
}