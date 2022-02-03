#include <iostream>
#include <string>

using namespace std;

bool isInfoCorrect(string username,string password) // this functions checks if the user and pass are correct
{
    if (username == "im.farhad" && password == "1234") 
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() // main program
{
    string userame = "<unknown>";
    string password = "<unknown>";

    while (true)
    {
        cout << " enter the username: ";
        cin >> userame;

        cout << "enter the password: ";
        cin >> password;
        
        if ( isInfoCorrect(userame,password))
        {
            cout << " Access Granted!\n";
            break;
        }
        else 
        {
            cout << " the inserted username or password is wrong! try again\n";
        }
    }
}