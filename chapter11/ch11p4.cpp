#include <iostream>

using namespace std;

const int numberOfScores = 2;
const int numberOfPlayers = 2;

struct scoreInfo
{
    int score;
    string name;
};

struct playerInfo
{
    scoreInfo scores[numberOfScores];
    string name;
};

playerInfo getPLayerInfo(); // this function gets the player info from user
playerInfo editPLayerScore(playerInfo player); // this function edits score of given player
void showPlayerInfo(playerInfo player); // this function prints player info
void showHighScore(playerInfo player); // this function prints high score of players
int highScoreIndex(playerInfo player); // this function returns the high score of given player
void showPlayerList(playerInfo player[]); // this function prints list of players
int menuMessage(); // this function prints the menu
int getPlayerNumber();
int getScoreNumber();

int main()
{
    playerInfo player[numberOfPlayers];

    for (int i = 0; i < numberOfPlayers; i++)
    {
        player[i] = getPLayerInfo();
    }

    int playerNumber = 0;
    while (true)
    {
        int menuKey = menuMessage();
        switch (menuKey)
        {
        case 1:
            playerNumber = getPlayerNumber();
            showPlayerInfo(player[playerNumber]);
            break;
        
        case 2:
            playerNumber = getPlayerNumber();
            player[playerNumber] = editPLayerScore(player[playerNumber]);
            break;

        case 3:
            playerNumber = getPlayerNumber();
            showHighScore(player[playerNumber]);
            break;

        case 4:
            for (int i = 0; i < numberOfPlayers; i++)
            {
                showHighScore(player[i]);
            }
            break;
        
        case 5: 
            for (int i = 0; i < numberOfPlayers; i++)
            {
                showPlayerInfo(player[i]);
            }
            break;

        case 6: 
            showPlayerList(player);
            break;

        case 7:
            return 0;
            break;
        
        default:
            cout << "error in switch menu in main function\n";
            break;
        }
    }
    return 0;
}


playerInfo getPLayerInfo()
{
    playerInfo player;  
    cout << " enter player name: ";
    cin >> player.name;

    for (int i = 0; i < numberOfScores; i++)
    {
        cout << "enter score " << i+1 << " name: ";
        cin >> player.scores[i].name;
        cout << "enter score" << i+1 << " value: ";
        cin >> player.scores[i].score;
    }
    return player;
}

playerInfo editPLayerScore(playerInfo player)
{
    int scoreNumber = getScoreNumber();
    cout << " enter the value of score of " << player.scores[scoreNumber].name << ": ";
    cin >> player.scores[scoreNumber].score;
    return player;
}

void showPlayerInfo(playerInfo player)
{
    cout << "\nplayer name: " << player.name;
    for (int i = 0; i < numberOfScores; i++)
    {
        cout << "\n\tscore " << player.scores[i].name << ": " << player.scores[i].score;
    }
}

void showHighScore(playerInfo player)
{
    cout << "player " << player.name << " high score: " << player.scores[highScoreIndex(player)].name <<"\t" << player.scores[highScoreIndex(player)].score << endl;
}

int highScoreIndex(playerInfo player)
{
    int highScoreIndex = 0;
    for (size_t i = 0; i < numberOfScores; i++)
    {
        if (player.scores[i].score > player.scores[highScoreIndex].score)
        {
            highScoreIndex = i;
        }
    }
    return highScoreIndex;
}

void showPlayerList(playerInfo player[])
{
    for (int i = 0; i < numberOfPlayers; i++)
    {
        cout << " player " << i << ": " << player[i].name << endl;
    }
}


int menuMessage()
{
    int menu = 0;
    do
    {
        cout << "\n\n choose one of the below options:" <<
            "\n\t1. See player Info" << 
            "\n\t2. Edit player score" <<
            "\n\t3. See player high score" << 
            "\n\t4. See high score of each player" <<
            "\n\t5. See all scores of all players" << 
            "\n\t6. See the list of all users" <<
            "\n\t7. Quit" << endl;
        cin >> menu;
    } while (menu < 1 || menu > 7);
    
    return menu;
}

int getPlayerNumber()
{
    int playerNumber = 0;
    do
    {
        cout << "enter the player number: ";
        cin >> playerNumber; 
    } while (playerNumber < 1 || playerNumber > numberOfPlayers);
    
    playerNumber--;
    return playerNumber;
}

int getScoreNumber()
{
    int scoreNumber = 0;   
    do
    {
        cout << "enter the score number: ";
        cin >> scoreNumber; 
    } while (scoreNumber < 1 || scoreNumber > numberOfScores);
    
    scoreNumber--;
    return scoreNumber;
}
