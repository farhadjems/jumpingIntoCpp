#include <iostream>

using namespace std;

// just comment out the condition scope to see its working

int main()
{
    // problem 01
    // for (int i = 99; i > 0; i--) // printing the below lyrics 99 times - in each time, using the loop variable is a good option for changing the lyrics 
    // {
        // cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
        // cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    // }
    // int i = 99;
    // while (i > 0)
    // {
    //     cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
    //     cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    //     i--;
    // }

    // i = 99;
    // do
    // {
    //     cout << i << " bottles of beer on the wall\t" << i << " bottles of beer\n";
    //     cout << "take one down, pass it around\t" << i-1 << " bottles of beer on the wall\n\n";
    //     i--;
    // } while (i>0);

    // problem 02
    int menuOption = 0;
    string menuMessage = "Choose one option:\n1.option1\n2.option2\n3.option3\n";

    int firstKey = 1;
    int lastKey = 3;

    // do
    // {
    //     cout << menuMessage;
    //     cin >> menuOption;
    // } while (menuOption < firstKey || menuOption > lastKey);
    
    // while(true)
    // {
    //     cout << menuMessage;
    //     cin >> menuOption;
    //     if (menuOption >= firstKey && menuOption <= lastKey)
    //     {
    //         break;
    //     }
    // }

    // for (int i = 0; i < i+1; i++)
    // {
    //     cout << menuMessage;
    //     cin >> menuOption;
    //     if (menuOption >= firstKey && menuOption <= lastKey)
    //     {
    //         break;
    //     }
    // }
    // OR
    // for (menuOption; menuOption < firstKey || menuOption > lastKey; )
    // {
    //     cout << menuMessage;
    //     cin >> menuOption;
    // }
    // cout << " you've chosen option number " << menuOption << endl;  
    
    //problem 03
    int input = 0; // variable for taking the inserted value
    int sum = 0; // variable for saving the sum 

    // do
    // {
    //     cout << " enter number (or \"0\" to exit): ";
    //     cin >> input; 
    //     sum += input;
    // } while (input != 0);

    // while(input != 0) 
    // {
    //     cin >> input; 
    //     sum += input;
    // }
    // for (input; input != 0; )
    // {
    //     cin >> input; 
    //     sum += input;
    // }
     cout << " the sum of all inserted numbers is: " << sum << endl;

    // problem 04
    string userName = "im.farhad"; // this is the correct username
    string password = "1234"; // this is the password

    string userInput = " "; // this variable takes the inserted username 
    string passInput = " "; // this variable takes the inserted password

    int iterateTimes = 3; // determines the number of tries that user can enter username and password

    // for (int i = 0; i < iterateTimes; i++)
    // {
    //     cout << " Enter username: ";
    //     cin >> userInput;

    //     cout << " Enter password: ";
    //     cin >> passInput;

    //     if (userInput == userName && passInput == password) // this condition checks if its correct or not
    //     {
    //         cout << " Access Granted!\n";
    //         return 0;
    //     }
    //     else
    //     {
    //         cout << " username or password inserted is wrong! try again\n";
    //     }
    // }
    
    
    // int i = 0;
    // while ( i < iterateTimes)
    // {
    //     cout << " Enter username: ";
    //     cin >> userInput;

    //     cout << " Enter password: ";
    //     cin >> passInput;

    //     if (userInput == userName && passInput == password) // this condition checks if its correct or not
    //     {
    //         cout << " Access Granted!\n";
    //         return 0;
    //     }
    //     else
    //     {
    //         cout << " username or password inserted is wrong! try again\n";
    //     }
    // }

    // int i = 0;
    // do
    // {
    //     cout << " Enter username: ";
    //     cin >> userInput;

    //     cout << " Enter password: ";
    //     cin >> passInput;

    //     if (userInput == userName && passInput == password) // this condition checks if its correct or not
    //     {
    //         cout << " Access Granted!\n";
    //         return 0;
    //     }
    //     else
    //     {
    //         cout << " username or password inserted is wrong! try again\n";
    //     }
    // } while (i < iterateTimes);
    
    cout << " number of tries are finished, acces denied!\n";
}