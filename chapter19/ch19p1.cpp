#include <iostream>

using namespace std;

int main()
{
    string needle;
    string haystack;

    cout << "please enter the haystack: ";
    getline(cin, haystack);

    cout << "please enter the needle: ";
    getline(cin, needle);

    int numberOfNeedles = 0;

    int j = 0;
    for (int i = haystack.find(needle, 0); i != haystack.npos; i = haystack.find(needle, i))
    {
        ++numberOfNeedles;
        ++i;
    }

    cout << needle << " appears " << numberOfNeedles << " times in " << haystack << endl;

    return 0;
}