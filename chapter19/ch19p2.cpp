#include <iostream>
#include <vector>

using namespace std;

void printData(const vector<vector<string>> &tabularData, const char &separatingCharacter);

int main()
{
    char separatingCharacter;

    cout << "please enter separator character: ";
    cin >> separatingCharacter;

    vector<vector<string>> tabularData;

    string line = "";

    while (line != "0")
    {
        cout << "please enter new line of tabular data or zero to exit program: ";
        cin >> line;
        vector<string> newLine;

        int separatorPosition = 0;
        while (separatorPosition != line.npos)
        {
            int newSeparatorPosition = line.find(separatingCharacter, separatorPosition);
            if (newSeparatorPosition != line.npos)
            {
                string substr = line.substr(separatorPosition, newSeparatorPosition - separatorPosition);
                newLine.push_back(substr);
                separatorPosition = newSeparatorPosition + 1;
            }
            else
            {
                string substr = line.substr(separatorPosition, newLine.size() - separatorPosition);
                newLine.push_back(substr);
                separatorPosition = newSeparatorPosition;
            }
        }
        tabularData.push_back(newLine);
    }

    printData(tabularData, separatingCharacter);
}

void printData(const vector<vector<string>> &tabularData, const char &separatingCharacter)
{
    for (int i = 0; i < tabularData.size(); i++)
    {
        for (int j = 0; j < tabularData[i].size(); j++)
        {
            cout << tabularData[i][j] << "\t";
        }
        cout << endl;
    }
}