#include <iostream>

using namespace std;

struct friends
{
    string name;
    int days;
};

int *getMenu(); // this function prints the manu and gets the key from user
friends *checkSizeOfArray(friends *firendList, int *size, int *numberOfFriends); // this functions checks if array is full or not , if the array is full, new array is created and its size is double 
void enterNewFriend(friends *friendList, int *size, int *numberOfFriends); // this function gets the info of new element and saves it in the address book
void editFriendInfo(friends *friendList, int *size); // this function edits the info of element
void printFriendList(friends *friendList, int size); // this function prints the address book 
int findFriend(friends *friendList, int size, string friendName); // this function finds the element in array by giving the name
void getEnter(); // this function clears the buffer

int main() // main function 
{
    int *size = new int;
    *size = 1000;
    friends *friendList = new friends[*size];   
    int *numberOfFriends = new int;
    *numberOfFriends = 0;
    
    int *menu = getMenu();

    while (true)
    {
        if (*numberOfFriends == *size)
        {
            friendList = checkSizeOfArray(friendList, size, numberOfFriends);
        }
        
        switch (*menu)
        {
            case 1:
                enterNewFriend(friendList, size, numberOfFriends);
                break;

            case 2:
                editFriendInfo(friendList, size);
                break;

            case 3:
                printFriendList(friendList, *numberOfFriends);
                break;

            case 4:
                return 0;
                break;
        }
        menu = getMenu();
    }

    delete[] friendList;
    delete numberOfFriends;
    delete size;
}

int *getMenu()
{
    int *menu = new int;
    bool isMenuOK = false;
    do
    {
        cout << " choose one of the below options:\n 1-Enter new friend Info\n 2-Edit firend Info\n 3-Print firend list\n 4-Exit program\n";
        cin >> *menu;
        if (*menu == 1 || *menu == 2 || *menu == 3 || *menu == 4)
        {
            break;
        }
        cout << " choose one of the options shown below.\n";
    } while (!isMenuOK);
    return menu;
}

friends *checkSizeOfArray(friends *friendList, int *size, int *numberOfFriends)
{
    friends *newFriendList = new friends[*size * 2]; 
    for (int i = 0; i < *size; i++)
    {
        newFriendList[i] = friendList[i]; 
    }
    return newFriendList;   
}

void enterNewFriend(friends *friendList,int *size, int *numberOfFriends)
{
    getEnter();
    friends newFriend; 
    cout << " enter friend's name: ";
    getline(cin, newFriend.name, '\n');
    cout << " enter number of days from last speak: ";
    cin >> newFriend.days;
    friendList[*numberOfFriends]  = newFriend;
    ++*numberOfFriends;
}

void editFriendInfo(friends *friendList,int *size)
{
    getEnter();
    string friendName = "";
    cout << " enter the name of friend: ";
    getline(cin, friendName, '\n');
    int friendIndex = findFriend(friendList, *size, friendName);
    if (friendIndex != *size + 1)
    {
        cout << " change the number of days from last speak: ";
        cin >> friendList[friendIndex].days;
    }
    else
    {
        cout << " the entered name does not exist in the list!\n";
    }
}
int findFriend(friends *friendList, int size, string friendName)
{
    for (int i = 0; i < size; i++)
    {
        if (friendList[i].name == friendName)
        {
            return i;
        }
    }
    return (size + 1);
}

void printFriendList(friends *friendList,int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << friendList[i].name << '\t' << friendList[i].days << endl;
    }
}          

void getEnter()
{
    string enter = "";
    getline(cin, enter, '\n');
}




