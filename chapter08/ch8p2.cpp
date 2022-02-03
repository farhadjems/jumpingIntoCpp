#include <iostream>

using namespace std;

string ordinalNumber(int number) // this number turns the day number unteger to string 
{
    string  numberToString = "";
    switch (number)
    {
        case 1:
            numberToString = "first ";
            break;
        case 2:
            numberToString = "second ";
            break;
        case 3:
            numberToString = "third ";
            break;
        case 4:
            numberToString = "fourth ";
            break;
        case 5:
            numberToString = "fifth ";
            break;
        case 6:
            numberToString = "sixth ";
            break;
        case 7:
            numberToString = "seventh ";
            break;
        case 8:
            numberToString = "eighth";
            break;
        case 9:
            numberToString = "ninth";
            break;
        case 10:
            numberToString = "tenth";
            break;
        case 11:
            numberToString = "eleventh";
            break;
        case 12:
            numberToString = "twelvth";
            break;
        default:
            numberToString = "errorOrdinalNumber ";
            break;
    }
    return numberToString;
}

void dayLyrics(int dayNumber) // this function retunrs the part of lyrics related to the day number
{
    string lyrics = "On the " + ordinalNumber(dayNumber) +"day of Christmas my true love sent to me\n";

    switch (dayNumber)
    {
        case 12:
            lyrics += "tweleve drummers drumming.\n";
        
        case 11:
            lyrics += "eleven pipers piping.\n";
        
        case 10:
            lyrics += "ten lords a-leaping.\n";
        
        case 9:
            lyrics += "nine ladies dancing.\n";

        case 8:
            lyrics += "eight maid a-milking.\n";
        
        case 7:
            lyrics += "seven swans a-swimming.\n";

        case 6:
            lyrics += "six geese a-lying.\n";
        
        case 5:
            lyrics += "five gold rings.\n";

        case 4:
            lyrics += "four calling birds.\n";
        
        case 3:
            lyrics += "Three French hens.\n";

        case 2:
            lyrics += "Two turtle doves.\nAnd ";
        
        case 1:
            lyrics += "partridge in a pear tree.\n";

    }

    cout << lyrics;
}

int main () // main function 
{
    for (int i = 1; i < 13; i++)
    {
        dayLyrics(i);
    }
    
}