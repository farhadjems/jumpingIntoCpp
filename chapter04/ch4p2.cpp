#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userName = "<unknown>"; // variable for username
    string password = "<unknown>"; // variable for password

    cout << " enter the user name: ";
    cin >> userName; // taking the username

    cout << "enter the password: ";
    cin >> password; // taking the password

    if (userName == "im.farhad" && password == "1234") // cheking if the entered username and password are correct or not 
    {
        cout << " Access Granted!\n"; // if the entered uesrname or password is true 
    }
    else  // if the entered uesrname or password is wrong 
    {
        cout << " the inserted user name or password is wrong!\n quitting\n";
    }
}