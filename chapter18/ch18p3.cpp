#include <iostream>
#include <map>

using namespace std;

enum MenuOption
{
    Exit = 0,
    Register = 1,
    Login = 2,
};

void registerUser(map<string, string> &dataBase);
void loginUser(map<string, string> &dataBase);

int main()
{
    map<string, string> dataBase;

    int menu = 1;
    while (menu)
    {
        cout << "please choose one of below options:" << endl
             << "1. Register" << endl
             << "2. Log in" << endl
             << "3. Exit" << endl;
        cin >> menu;
        cin.ignore();
        switch (menu)
        {
        case Exit:
            break;
            break;

        case Register:
            registerUser(dataBase);
            break;

        case Login:
            loginUser(dataBase);
            break;

        default:
            cout << "please choose one of existing options" << endl;
            break;
        }
    }
    return 0;
}

void registerUser(map<string, string> &dataBase)
{
    string username;
    string password;

    cout << "please enter username: ";
    getline(cin, username);

    cout << "please enter password: ";
    getline(cin, password);

    dataBase[username] = password;
}

void loginUser(map<string, string> &dataBase)
{
    string username;
    string password;

    bool isUserAvailable = false;
    while (!isUserAvailable)
    {
        cout << "please enter username: ";
        getline(cin, username);

        if (dataBase.find(username)->first == username)
        {
            isUserAvailable = true;
            bool access = false;
            while (!access)
            {
                cout << "please enter password: ";
                getline(cin, password);

                if (dataBase.find(username)->second == password)
                {
                    access = true;
                    cout << "Access Granted\n";
                }
                else
                {
                    cout << "the entered password is wrong, try again" << endl;
                }
            }
        }
        else
        {
            cout << "the entered username does not exist!, try again" << endl;
        }
    }
}