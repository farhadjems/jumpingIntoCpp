#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userame = "<unknown>";
    string password = "<unknown>";

    cout << " enter the user name: ";
    cin >> userame;

    cout << "enter the password: ";
    cin >> password;

    if ((userame == "im.farhad" && password == "1234") || (userame == "kim.j" && password == "4567"))
    {
        cout << " Access Granted!\n";

    }
    else // here another chane is given to user if the password or username is entered wrong 
    {
        cout << " the inserted user name or password is wrong! try again\n";
        
        cout << " enter the user name: ";
        cin >> userame;
        cout << "enter the password: ";
        cin >> password;
        if ((userame == "im.farhad" && password == "1234") || (userame == "kim.j" && password == "4567"))
        {
            cout << " Access Granted!\n";

        }
        else 
        {
            cout << " no tries remaining. quitting!\n";
        }
    }
}