#include <iostream> 

using namespace std;

struct linkedList
{
    int value;
    linkedList *nextElement;
};

void insertElementSorted(linkedList *list, int value);
void printList(linkedList *list);
int getValue();


int main()
{
    linkedList *list = new linkedList;
    list->nextElement = NULL;

    int value = 1;
    while (value)
    {
        value = getValue();
        insertElementSorted(list, value);
    }
    printList(list);
}

void insertElementSorted(linkedList *list, int value) // this function inserts the element in the manner that each element points to the greater element
{
    linkedList *newElement = new linkedList; // creating new element
    newElement->value = value;
    newElement->nextElement = NULL;
    
    if (list == NULL) // base case - if the list is empty
    {
        newElement->nextElement = NULL;
        list = newElement;
        return;
    }

    if (list->nextElement == NULL) // base case - if list just has one element
    {
        if (list->value >= value)
        {
            newElement->nextElement = list;
            list = newElement;
        }
        else
        {
            list->nextElement = newElement;
        }
        
        return;
    }
    
    // from now on , we consider that atleast there are two elements in the list
    linkedList *smallerElement = list;
    linkedList *biggerElement = list->nextElement;

    while (biggerElement != NULL) // if the value is between two elements
    {
        if (smallerElement->value < value && biggerElement->value >= value)
        {
            smallerElement->nextElement = newElement;
            newElement->nextElement = biggerElement;
            return;
        }
        
        smallerElement = biggerElement;
        biggerElement = smallerElement->nextElement;
    }

    // if the value is greater than the whole list - note that: update cond. in the loop makes the smaller element smaller than the new element so ... 
    smallerElement->nextElement = newElement;
}

void printList(linkedList *list)
{
    linkedList *printedList = list;
    int i = 1;

    cout << "----------LIST----------\n";
    cout << "number\tvalue\n";
    while (printedList != NULL)
    {
        cout << i << '\t' << printedList->value << endl;
        ++i;
        printedList = printedList->nextElement;
    }
    cout << "-----------END----------\n";
}

int getValue()
{
    cout << "enter value (or zero to quit): ";
    int value = 0;
    cin >> value;
    return value;
}

