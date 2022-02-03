#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userName = "im.farhad"; // this is the correct username
    string password = "1234"; // this is the password

    string userInput = " "; // this variable takes the inserted username 
    string passInput = " "; // this variable takes the inserted password

    int iterateTimes = 3; // determines the number of tries that user can enter username and password

    for (int i = 0; i < iterateTimes; i++)
    {
        cout << " Enter username: ";
        cin >> userInput;

        cout << " Enter password: ";
        cin >> passInput;

        if (userInput == userName && passInput == password) // this condition checks if its correct or not
        {
            cout << " Access Granted!\n";
            return 0;
        }
        else
        {
            cout << " username or password inserted is wrong! try again\n";
        }
    }

    cout << " number of tries are finished, acces denied!\n";
    return 0;
    
}