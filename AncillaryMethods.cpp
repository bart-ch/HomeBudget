#include "AncillaryMethods.h"

string AncillaryMethods::IntToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AncillaryMethods::replaceFirstLetterUppercaseAndOtherLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AncillaryMethods::StringToIntConversion(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

char AncillaryMethods::getCharacter()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "Must be a single character. Please reenter: ";
    }
    return sign;
}

string AncillaryMethods::getSingleLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string AncillaryMethods::checkIfPasswordHasAtLeast4Character (string password)
{
    while(password.length() < 4)
    {
        cout << "Your password must be at least 4 characters long: ";
        password = AncillaryMethods::getSingleLine();
    }
    return password;
}

bool AncillaryMethods::isAmountFormatCorrect(string amount)
{
    for(int i = 0; i < amount.length(); i++)
    {
        if((amount[i] < '0' || amount[i] > '9') && (amount[i] != '.'))
        {
            cout << "Entered amount has invalid format. Try again: ";
            return false;
        }
    }

    return true;
}

string AncillaryMethods::convertDateFromIntToString(int date)
{
    string dateString = IntToStringConversion(date);
    dateString.insert(4,"-");
    dateString.insert(7,"-");

    return dateString;
}

int AncillaryMethods::convertDateFromStringToInt(string date)
{
    int dateInteger = 0;
    date.erase(4,1);
    date.erase(6,1);
    dateInteger = StringToIntConversion(date);
    return dateInteger;

}

string AncillaryMethods::replaceComaWithPeriod(string amount)
{
    for(int i = 0; i < amount.length(); i++)
    {
        if(amount[i] == ',')
            amount[i] = '.';
    }
    return amount;
}

string AncillaryMethods::floatToStringConversion(float amount)
{
    stringstream stream;
    stream << amount;
    string amountString = stream.str();
    return amountString;
}
