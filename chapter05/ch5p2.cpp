#include <iostream>
#include <string>

using namespace std;

int main()
{
    int menuOption = 0;
    string menuMessage = "Choose one option:\n1.option1\n2.option2\n3.option3\n";

    int firstKey = 1;
    int lastKey = 3;

    do
    {
        cout << menuMessage;
        cin >> menuOption;
    } while (menuOption < firstKey || menuOption > lastKey);
    
    cout << " you've chosen option number " << menuOption << endl;
}