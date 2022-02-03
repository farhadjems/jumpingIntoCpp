#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pollQuestion = " enter the question here"; // this variable holds the inserted poll question
    cout << " enter the poll's question: ";
    getline(cin, pollQuestion, '\n'); // taking the poll question

    string option1 = "option1"; // this variable holds the 1st option
    cout << " enter the first option: ";
    getline(cin, option1, '\n'); // taking the 1st option

    string option2 = "option2"; // this variable holds the 2nd option
    cout << " enter the second option: ";
    getline(cin, option2, '\n'); // taking the 2nd option

    string option3 = "option3"; // this variable holds the 3rd option
    cout << " enter the third option: ";
    getline(cin, option3, '\n'); // taking the 3rd option

    string tab = "\t";
    string voteMessage = " please enter the vote or \"0\" to finish: ";
    string warningMessage = " the option number inserted is not valid, please enter the correct option number.";
    int vote1 = 0; // saving the votes for 1st option
    int vote2 = 0; // saving the votes for 2nd option
    int vote3 = 0; // saving the votes for 3rd option
    int vote = 1;

    while (true)
    {
        cout << pollQuestion << endl << option1 << tab << option2 << tab << option3 << tab << endl << voteMessage;
        cin >> vote;
        if (vote == 1)
        {
            vote1++;
        }
        else if (vote == 2)
        {
            vote2++;
        }
        else if (vote == 3)
        {
            vote3++;
        }
        else if (vote == 0)
        {
            break;
        }
        else
        {
            cout << warningMessage << endl;
        }
    }

    cout << option1 << tab << option2  << tab << option3 << endl;
    
    while (vote1 || vote2 || vote3) // drawing the diagram
    {
        if (vote1 > 0)
        {
            cout << "___\t";
            vote1--;
        }

        if (vote2 > 0)
        {
            cout << "___\t";
            vote2--;
        }

        if (vote3 > 0)
        {
            cout << "___\t";
            vote3--;
        }
        cout << endl;

        if (vote1 == 0 && vote2 == 0 && vote3 == 0)
        {
            break;
        }
    }

}