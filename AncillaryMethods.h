#ifndef ANCILLARYMETHODS_H
#define ANCILLARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AncillaryMethods
{
public:
    static string IntToStringConversion(int number);
    static string replaceFirstLetterUppercaseAndOtherLowercase(string text);
    static int StringToIntConversion(string number);
    static char getCharacter();
    static string getSingleLine();
    static string checkIfPasswordHasAtLeast4Character (string password);
    static bool isAmountFormatCorrect(string price);
    static string convertDateFromIntToString(int date);
    static int convertDateFromStringToInt(string date);
    static string replaceComaWithPeriod(string amount);
    static string floatToStringConversion(float amount);
};

#endif
