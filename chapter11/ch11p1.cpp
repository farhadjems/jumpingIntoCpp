#include <iostream>
#include <string>

using namespace std;

struct idCart // this structure takes the name, address, and phone number 
{
    string name;
    string address;
    string phoneNumber;
};

idCart getPersonInfo() // this function takes the info from user in the form of structure and returns it 
{
    idCart personInfo;
    
    cout << " enter your name: ";
    getline(cin, personInfo.name, '\n');

    cout << " enter your address: ";
    getline(cin, personInfo.address, '\n');

    cout << " enter your phone number: ";
    getline(cin, personInfo.phoneNumber, '\n');

    return personInfo;
}

void printPersonInfo(idCart personInfo) // this function prints the info inserted from user
{
    cout << " you have entered the below information:\n";
    cout << " name: " << personInfo.name << endl;
    cout << " name: " << personInfo.address << endl;
    cout << " name: " << personInfo.phoneNumber << endl;
}

int main() // main function
{
    idCart personInfo = getPersonInfo();
    printPersonInfo(personInfo);
}