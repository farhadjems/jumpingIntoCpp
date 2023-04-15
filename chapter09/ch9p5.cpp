#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
    to implement the code we need to create a system which can give cards a unique number
    so, consider:
        diamonds = 0, hearts = 1, clubs = 2, spades = 3.
    and:
        0 = Ace, 1 = two, ... , 12 = king.
    so, for example:
        3 clubs is = 2 + (2*13) = 29
    The range card numbers is from 0 to 51.
*/
enum CardType
{
    diamonds = 0,
    hearts = 1,
    clubs = 2,
    spades = 3,
};
enum CardNumber
{
    ace = 0,
    two = 1,
    three = 2,
    four = 3,
    five = 4,
    six = 5,
    seven = 6,
    eight = 7,
    nine = 8,
    ten = 9,
    jack = 10,
    queen = 11,
    king = 12
};
enum HandValue
{
    noValue = -1,
    highCard = 0,
    onePair = 1,
    twoPair = 2,
    threeOfAKind = 3,
    straight = 4,
    flush = 5,
    fullHouse = 6,
    fourOfAKind = 7,
    straightFlush = 8,
    royalFlush = 9
};
//------ VARIABLES ------
// note that implementing this code without arrays gets you a huge mistake
//------ FUNCTIONS ------
// to choose cards randomly, we need a function to create that random card
int getRandomCard();
// reads a given card
string readCard(int card);
void setTableCards(int tableCards[]);
bool isTableCardDuplicate(int cards[], int size);
void printTable(int cards[], int size, string message);
void setUserCards(int userCards[], int tableCards[]);
bool isUserCardDuplicate(int tableCards[], int userCard);
void compareCards(int userCards[], int tableCards[]);
//------ MAIN FUNCTION ------
int main()
{
    srand(time(NULL)); // to create the seed

    int tableCards[5];
    for (int i = 0; i < 5; i++)
    {
        tableCards[i] = -1;
    }
    int userCards[2];
    for (int i = 0; i < 2; i++)
    {
        tableCards[i] = -1;
    }

    setTableCards(tableCards);

    while (true)
    {
        printTable(tableCards, 5, "----TABLE CARDS----");
        setUserCards(userCards, tableCards);
        printTable(userCards, 2, "----USER CARDS----");
        compareCards(userCards, tableCards);

        cout << endl
             << "For New Table Cards, Please Enter 1" << endl
             << "For Finishing the Program, Enter 0" << endl
             << "else press Enter to Set new User Cards" << endl;
        string userChoice = "";
        if (userChoice == "1")
        {
            setTableCards(tableCards);
        }
        else if (userChoice == "0")
        {
            break;
        }
    }
    return 0;
}

int getRandomCard()
{
    // since the card number is between 0 and 52, no need to take interval low and high!
    int randomCard = (random() % 52);
    // cout << randomCardNumber << endl;
    return randomCard;
}
string readCard(int card)
{
    int cardType = card / 13;
    // cout << cardType << endl;
    int cardNumber = (card % 13);
    // cout << cardNumber << endl;

    string cardName = "";

    switch (cardNumber)
    {
    case ace:
        cardName = "Ace";
        break;
    case two:
        cardName = "Two";
        break;
    case three:
        cardName = "Three";
        break;
    case four:
        cardName = "Four";
        break;
    case five:
        cardName = "Five";
        break;
    case six:
        cardName = "Six";
        break;
    case seven:
        cardName = "Seven";
        break;
    case eight:
        cardName = "Eight";
        break;
    case nine:
        cardName = "Nine";
        break;
    case ten:
        cardName = "Ten";
        break;
    case jack:
        cardName = "Jack";
        break;
    case queen:
        cardName = "Queen";
        break;
    case king:
        cardName = "King";
        break;
    default:
        cout << "\n------------------------\nError occoured in reading CardNumber\n------------------------\n";
        break;
    }
    // cout << cardName << endl;

    switch (cardType)
    {
    case diamonds:
        cardName += " of diamonds";
        break;
    case hearts:
        cardName += " of hearts";
        break;
    case clubs:
        cardName += " of clubs";
        break;
    case spades:
        cardName += " of spades";
        break;
    default:
        cout << "\n------------------------\nError occoured in reading CardType\n------------------------\n";
        break;
    }

    // cout << cardName << endl;

    return cardName;
}
void setTableCards(int tableCards[])
{
    for (int i = 0; i < 5; i++)
    {
        do
        {
            tableCards[i] = getRandomCard();
        } while (isTableCardDuplicate(tableCards, i));
    }
}
bool isTableCardDuplicate(int cards[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (cards[i] == cards[size])
        {
            return true;
        }
    }
    return false;
}
void printTable(int cards[], int size, string message)
{
    cout << message << endl;
    for (int i = 0; i < size; i++)
    {
        cout << readCard(cards[i]) << endl;
    }
}
void setUserCards(int userCards[], int tableCards[])
{
    // first user card checks
    do
    {
        userCards[0] = getRandomCard();
    } while (isUserCardDuplicate(tableCards, userCards[0]));
    // second user card checks
    do
    {
        userCards[1] = getRandomCard();
    } while ((userCards[1] == userCards[0]) || isUserCardDuplicate(tableCards, userCards[0]));
}
bool isUserCardDuplicate(int tableCards[], int userCard)
{
    for (int i = 0; i < 5; i++)
    {
        if (userCard == tableCards[i])
        {
            return true;
        }
    }
    return false;
}
void compareCards(int userCards[], int tableCards[])
{
    // check with two cards in hand
    for (int i = 0; i < 4; i++)
    {
        int TC1 = tableCards[i];
        int TC2 = tableCards[i + 1];
        tableCards[i] = userCards[0];
        tableCards[i + 1] = userCards[1];
        // checkHandValue(tableCards);
        tableCards[i] = TC1;
        tableCards[i + 1] = TC2;
    }
    // check with one card in hand
    // first card
    for (int i = 0; i < 5; i++)
    {
        int TC = tableCards[i];
        tableCards[i] = userCards[0];
        // checkHandValue(tableCards);
        tableCards[i] = TC;
    }
    // second card
    for (int i = 0; i < 5; i++)
    {
        int TC = tableCards[i];
        tableCards[i] = userCards[1];
        // checkHandValue(tableCards);
        tableCards[i] = TC;
    }
    // check the table itself
    // checkHandValue(tableCards);
}
HandValue checkHighCard(int cards[])
{
}
HandValue checkOnePair(int cards[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (cards[i] == cards[j])
            {
                return onePair;
            }
        }
    }
    return noValue;
}
HandValue checkTwoPair(int cards[])
{
}
HandValue checkThreeOfAKind(int cards[])
{
}
HandValue checkStraight(int cards[])
{
}
HandValue checkFlush(int cards[])
{
}
HandValue checkFullHouse(int cards[])
{
}
HandValue checkFourOfAKind(int cards[])
{
}
HandValue checkStraightFlush(int cards[])
{
}
HandValue checkRoyalFlush(int cards[])
{
}
