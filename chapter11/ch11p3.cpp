#include <iostream>

using namespace std;

struct personInfo // this structure considers the info of person
{
    string name;
    string address;
    string  phoneNumber;
};

int getPersonInfo(personInfo addressBook[], int numberOfPersons); // this function takes the info from user in the form of structure and returns it
int getMenu(); // this function prints the menu and takes the menu key from user
void showAddressBook(personInfo addressBook[],int numberOfPersons); // this function prints the address book

int main() // main function 
{
    personInfo addressBook[100];
    int numberOfPersons = 0;

    bool exitProgram = false;
    int menu = 1;
    do
    {
        menu = getMenu();
        if (menu == 1)
        {
            numberOfPersons = getPersonInfo(addressBook, numberOfPersons);
        }
        if (menu == 2)
        {
            showAddressBook(addressBook, numberOfPersons);
        }
        
    } while (!exitProgram);
    
}

int getPersonInfo(personInfo addressBook[], int numberOfPersons)
{
    personInfo person;
    string getEnter = ""; 
    getline(cin, getEnter, '\n');
    cout << " enter name: ";
    getline(cin, person.name, '\n');
    cout << " enter address: ";
    getline(cin, person.address, '\n');
    cout << " enter phone number: ";
    getline(cin, person.phoneNumber, '\n');

    addressBook[numberOfPersons] = person;
    
    return ++numberOfPersons;
}

int getMenu()
{
    bool isMenuOK = false;
    int menu = 0;
    do
    {
        cout << " choose one of the options\n";
        cout << " 1-enter person in address book\n 2-See address book\n";
        cin >> menu;
        if (menu== 1 || menu == 2)
        {
            break;
        }
        else
        {
            cout << " choose between the two below options\n";
        }
    } while (!isMenuOK);
    return menu;
}

void showAddressBook(personInfo addressBook[],int numberOfPersons)
{
    cout << endl << " -----------ADRESS BOOK-----------" << endl;
    for (int i = 0; i < numberOfPersons; i++)
    {
        cout << "name: " << addressBook[i].name << endl << "address: " << addressBook[i].address << endl << "phone number: " << addressBook[i].phoneNumber << endl << endl;
    }

    cout << "---------------------------------";
}