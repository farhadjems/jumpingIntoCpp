#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> highScore;
    string playerName;

    cout << "Please enter player name: ";
    getline(cin, playerName);

    int score = 0;

    while (score > 0)
    {
        cout << "please enter score: ";
        cin >> score;
        highScore.push_back(score);
        sort(highScore.begin(), highScore.end());
        for (int i = 0; i < highScore.size(); i++)
        {
            cout << highScore[i] << '\t';
        }
        cout << endl;
    }

    return 0;
}