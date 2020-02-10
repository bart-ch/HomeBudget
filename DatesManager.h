#ifndef DATESMANAGER_H
#define DATESMANAGER_H

#include <time.h>
#include <sstream>
#include <iostream>
#include "AncillaryMethods.h"

using namespace std;

class DatesManager
{
    bool doesDateHasGoodFormatAndPeriod(string& year,string& month,string& day);
    int getNumberOfDaysOfMonth(int month, int year);
    string getDateOfPreviousMonth(string currentDateString);

public:
    int getCurrentDate();
    int enterNewDate();
    int getDateOfFirstDayOfCurrentMonth();
    int getDateOfLastDayOfCurrentMonth();
    int getDateOfFirstDayOfPreviousMonth();
    int getDateOfLastDayOfPreviousMonth();
};

#endif // DATESMANAGER_H
