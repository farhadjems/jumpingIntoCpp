#include <iostream>
#include <string>

using namespace std;

int getNumber(); // this function takes the number from user
string readNumber(int number); // this function turns the number integer to string
int rankNumber(int number); // this functoin computes the rank of number
string readThreeDigitNumber(int number); // this function reads the 3 digit number 
string rankString(int rank); // this function turns the rank into 
string hundredsToString(int hundreds); // this function turns the number in the hundreds number string
string tensToString(int tens, int ones); // this function turns the number to tens number string
string onesToString(int ones); // this function turns the number into one string 
string tenToTwentyString(int tens, int ones); // this function reads the numbers from ten to nineteen since the algorithm of reading is different 

int main() // main function
{
    int numberDigit = getNumber();
    string numberString = readNumber(numberDigit);
    cout << endl << numberString << endl;
}

int getNumber()
{
    cout << endl << " enter number to read: ";
    int number = 0;
    cin >> number;
    return number;
}

string readNumber (int number)
{
    if (number == 0)
    {
        return "zero";
    }
    
    int rank = rankNumber (number);
    int threeDigitNumber = 0;
    string numberString = "";
    
    bool isNumberNegative = false;
    if (number < 0)
    {
        number = -number;
        isNumberNegative = true;
    }
    
    for (int  i = 1; i < rank+1; i++)
    {
        threeDigitNumber = number % 1000;
        number = number / 1000;
        numberString = readThreeDigitNumber (threeDigitNumber) + rankString(i) + numberString;
    }

    if (isNumberNegative)
    {
        numberString = "minus " + numberString;
    }
    
    return numberString;
}

int rankNumber (int number)
{
    int rank = 0;
    while (number)
    {
        number = number /1000;
        rank++;
    }
    return rank;
}

string readThreeDigitNumber(int number)
{
    int ones = (number%10) / 1;
    int tens = (number%100) / 10;
    int hundreds = (number%1000) / 100;
    
    string threeDigitNumber = hundredsToString(hundreds) + tensToString (tens, ones);
    
    return threeDigitNumber;
}

string onesToString(int ones)
{
    string onesString = "";
    if (ones == 0)
    {
        onesString = "";
    }
    else if (ones == 1)
    {
        onesString = "one ";
    }
    else if (ones == 2)
    {
        onesString = "two ";
    }
    else if (ones == 3)
    {
        onesString = "three ";
    }
    else if (ones == 4)
    {
        onesString = "four ";
    }
    else if (ones == 5)
    {
        onesString = "five ";
    }
    else if (ones == 6)
    {
        onesString = "six ";
    }
    else if (ones == 7)
    {
        onesString = "seven ";
    }
    else if (ones == 8)
    {
        onesString = "eight ";
    }
    else if (ones == 9)
    {
        onesString = "nine ";
    }
    else
    {
        onesString = "errorOnesToString ";
    }

    return onesString;
}

string tensToString(int tens, int ones)
{
    string tensString = "";

    if (tens == 0)
    {
        tensString = "";
    }
    else if (tens == 1)
    {
        tensString = tenToTwentyString(tens, ones);
        return tensString; 
    }
    else if (tens == 2)
    {
        tensString = "twenty ";
    }
    else if (tens == 3)
    {
        tensString = "thirty ";
    }
    else if (tens == 4)
    {
        tensString = "fourty ";
    }
    else if (tens == 5)
    {
        tensString = "fifty ";
    }
    else if (tens == 6)
    {
        tensString = "sixty ";
    }
    else if (tens == 7)
    {
        tensString = "seventy ";
    }
    else if (tens == 8)
    {
        tensString = "eighty ";
    }
    else if (tens == 9)
    {
        tensString = "ninety ";
    }
    else 
    {
        tensString = "errorTensToString";
    }
    tensString += onesToString(ones);
    return tensString;
}

string tenToTwentyString(int tens, int ones)
{
    int number = tens * 10 + ones;
    string numberString = "";
    if (number == 11)   
    {
        numberString = "eleven ";
    }
    else if (number == 12)   
    {
        numberString = "twelve ";
    }
    else if (number == 13)   
    {
        numberString = "thirteen ";
    }
    else if (number == 14)   
    {
        numberString = "fourteen ";
    }
    else if (number == 15)   
    {
        numberString = "fifteen ";
    }
    else if (number == 16)   
    {
        numberString = "sixteen ";
    }
    else if (number == 17)   
    {
        numberString = "seventeen ";
    }
    else if (number == 18)   
    {
        numberString = "eighteen ";
    }
    else if (number == 19)   
    {
        numberString = "nineteen ";
    }
    else 
    {
        numberString = "errorTenToTwenty ";
    }

    return numberString;
}

string hundredsToString(int hundreds)
{
    string hundredsString = "";
    if (hundreds == 0)
    {
        hundredsString = "";
    }
    else if (hundreds >= 1 && hundreds < 10)
    {
        if (hundreds == 1)
        {
            hundredsString = onesToString (hundreds) + "hundred ";    
        }
        else  
        {
           hundredsString = onesToString (hundreds) + "hundreds ";
        }
    } 
    return hundredsString;
}

string rankString (int rank)
{
    string rankToString = "";
    if (rank == 1 || rank == 0)
    {
        rankToString = "";   
    }
    else if (rank == 2)
    {
        rankToString = "thousand ";   
    }
    else if (rank == 3)
    {
        rankToString = "milion ";   
    }
    else if (rank == 4)
    {
        rankToString = "bilion";   
    } 
    else if (rank > 4)
    {
        rankToString = "moreThanBilion";
    }
    else 
    {
        rankToString = "errorrankString";
    }
    return rankToString;
}