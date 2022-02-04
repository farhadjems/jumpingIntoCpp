#include <iostream>

using namespace std;

int main()
{
    int x1 = 1;
    int x2 = 2;
    int *px1 = &x1;
    int *px2 = &x2;

    cout << px1 << "\t" << px2 << endl << endl;
    if (px1 > px2) // comapring which address is bigger 
    {
        cout << "px1 is bigger\n";
    }
    else
    {
        cout << "px2 is bigger\n";
    }
    
}