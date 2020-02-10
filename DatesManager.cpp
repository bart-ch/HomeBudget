#include "DatesManager.h"

int DatesManager::getCurrentDate()
{
    time_t t = time(0);
    tm * currentDate = localtime( & t );
    stringstream yearSS,monthSS,daySS;
    string dateString,year,month,day;
    int dateInteger;

    yearSS << currentDate->tm_year+1900;
    year = yearSS.str();
    monthSS << currentDate->tm_mon+1;
    month = monthSS.str();
    if(currentDate->tm_mon+1 < 10)
        month.insert(0,"0");

    daySS << currentDate->tm_mday;
    day = daySS.str();
    if(currentDate->tm_mday < 10)
        day.insert(0,"0");

    dateString = year + month + day;
    dateInteger = atoi(dateString.c_str());
    return dateInteger;
}

int DatesManager::enterNewDate()
{
    string date;
    string year,month,day;
    int dateInteger;

    do
    {
        date = AncillaryMethods::getSingleLine();
        stringstream dateSS(date);
        getline(dateSS,year,'-');
        getline(dateSS,month,'-');
        getline(dateSS,day,'-');
    }
    while(doesDateHasGoodFormatAndPeriod(year,month,day) == false);
    date = year + month + day;
    dateInteger = atoi(date.c_str());

    return dateInteger;
}

bool DatesManager::doesDateHasGoodFormatAndPeriod(string& year,string& month,string& day)
{
    time_t t = time(0);
    tm * currentDate = localtime( & t );
    int yearInteger, monthInteger, dayInteger;
    yearInteger = atoi(year.c_str());
    monthInteger = atoi(month.c_str());
    dayInteger = atoi(day.c_str());
    if(yearInteger < 2000 || yearInteger > currentDate->tm_year+1900)
    {
        cout << "Entered date has invalid format or exceeds the permitted period (2000-01-01 to the last day of current month). " << endl << "Try again: ";
        return false;
    }

    if(monthInteger < 1 || monthInteger > 12)
    {
        cout << "Entered date has invalid format or exceeds the permitted period (from 2000-01-01 to the last day of current month). " << endl << "Try again: ";
        return false;
    }

    if(dayInteger < 1 || dayInteger > getNumberOfDaysOfMonth(monthInteger,yearInteger))
    {
        cout << "Entered date has invalid format or exceeds the permitted period (from 2000-01-01 to the last day of current month). " << endl << "Try again: ";
        return false;
    }

    if(yearInteger == currentDate->tm_year+1900 && monthInteger > currentDate->tm_mon+1)
    {
        cout << "Entered date has invalid format or exceeds the permitted period (from 2000-01-01 to the last day of current month). " << endl << "Try again: ";
        return false;
    }

    if(monthInteger < 10 && month[0]!='0')
        month.insert(0,"0");

    if(dayInteger < 10 && day[0]!='0')
        day.insert(0,"0");

    return true;
}

int DatesManager::getNumberOfDaysOfMonth(int month, int year)
{
    int days;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (isLeapYear)
            days = 29;
        else
            days = 28;
    }
    else
        days = 31;
    return days;
}

int DatesManager::getDateOfFirstDayOfCurrentMonth()
{
    string currentDateString,dateOfFirstDayOfCurrentMonthString;
    int currentDate,dateOfFirstDayOfCurrentMonth;

    currentDate = getCurrentDate();
    currentDateString = AncillaryMethods::IntToStringConversion(currentDate);
    dateOfFirstDayOfCurrentMonthString = currentDateString.replace(6,2,"01");
    dateOfFirstDayOfCurrentMonth = AncillaryMethods::StringToIntConversion(dateOfFirstDayOfCurrentMonthString);

    return dateOfFirstDayOfCurrentMonth;
}

int DatesManager::getDateOfLastDayOfCurrentMonth()
{
    string currentDateString,dateOfLastDayOfCurrentMonthString,numberOfDaysOfCurrentMonthString,currentMonthString,yearOfCurrentMonthString;
    int currentDate,dateOfLastDayOfCurrentMonth,numberOfDaysOfCurrentMonth,yearOfCurrentMonth,currentMonth;

    currentDate = getCurrentDate();
    currentDateString = AncillaryMethods::IntToStringConversion(currentDate);
    dateOfLastDayOfCurrentMonthString = currentDateString;

    yearOfCurrentMonthString.append(currentDateString,0,4);
    currentMonthString.append(currentDateString,4,2);

    yearOfCurrentMonth = AncillaryMethods::StringToIntConversion(yearOfCurrentMonthString);
    currentMonth = AncillaryMethods::StringToIntConversion(currentMonthString);

    numberOfDaysOfCurrentMonth = getNumberOfDaysOfMonth(currentMonth,yearOfCurrentMonth);
    numberOfDaysOfCurrentMonthString = AncillaryMethods::IntToStringConversion(numberOfDaysOfCurrentMonth);
    dateOfLastDayOfCurrentMonthString.replace(6,2,numberOfDaysOfCurrentMonthString);

    dateOfLastDayOfCurrentMonth = AncillaryMethods::StringToIntConversion(dateOfLastDayOfCurrentMonthString);

    return dateOfLastDayOfCurrentMonth;
}

int DatesManager::getDateOfFirstDayOfPreviousMonth()
{
    string currentDateString,dateOfFirstDayOfPreviousMonthString;
    int currentDate,dateOfFirstDayOfPreviousMonth;

    currentDate = getCurrentDate();
    currentDateString = AncillaryMethods::IntToStringConversion(currentDate);
    currentDateString.replace(6,2,"01");

    dateOfFirstDayOfPreviousMonthString = getDateOfPreviousMonth(currentDateString);

    dateOfFirstDayOfPreviousMonth = AncillaryMethods::StringToIntConversion(dateOfFirstDayOfPreviousMonthString);

    return dateOfFirstDayOfPreviousMonth;
}

int DatesManager::getDateOfLastDayOfPreviousMonth()
{
    string currentDateString,dateOfLastDayOfPreviousMonthString,numberOfDaysOfPreviousMonthString,previousMonthString,yearOfPreviousMonthString;
    int currentDate,dateOfLastDayOfPreviousMonth,numberOfDaysOfPreviousMonth,previousMonth,yearOfPreviousMonth;

    currentDate = getCurrentDate();
    currentDateString = AncillaryMethods::IntToStringConversion(currentDate);

    dateOfLastDayOfPreviousMonthString = getDateOfPreviousMonth(currentDateString);

    yearOfPreviousMonthString.append(dateOfLastDayOfPreviousMonthString,0,4);
    previousMonthString.append(dateOfLastDayOfPreviousMonthString,4,2);

    yearOfPreviousMonth = AncillaryMethods::StringToIntConversion(yearOfPreviousMonthString);
    previousMonth = AncillaryMethods::StringToIntConversion(previousMonthString);

    numberOfDaysOfPreviousMonth = getNumberOfDaysOfMonth(previousMonth,yearOfPreviousMonth);
    numberOfDaysOfPreviousMonthString = AncillaryMethods::IntToStringConversion(numberOfDaysOfPreviousMonth);
    dateOfLastDayOfPreviousMonthString.replace(6,2,numberOfDaysOfPreviousMonthString);

    dateOfLastDayOfPreviousMonth = AncillaryMethods::StringToIntConversion(dateOfLastDayOfPreviousMonthString);

    return dateOfLastDayOfPreviousMonth;
}

string DatesManager::getDateOfPreviousMonth(string currentDateString)
{
    int currentYear,previousYear,previousMonth,currentMonth;
    string dateWithPreviousMonth,currentYearString,previousYearString,currentMonthString,previousMonthString;
    if(currentDateString[4] == '0' && currentDateString[5] == '1')
    {
        currentDateString.replace(4,2,"12");
        currentYearString.append(currentDateString,0,4);
        currentYear = AncillaryMethods::StringToIntConversion(currentYearString);
        previousYear = currentYear - 1;
        previousYearString = AncillaryMethods::IntToStringConversion(previousYear);
        dateWithPreviousMonth = currentDateString.replace(0,4,previousYearString);
    }
    else
    {
        currentMonthString.append(currentDateString,4,2);
        currentMonth = AncillaryMethods::StringToIntConversion(currentMonthString);
        previousMonth = currentMonth - 1;
        if(previousMonth < 10 )
        {
            previousMonthString = AncillaryMethods::IntToStringConversion(previousMonth);
            previousMonthString.insert(0,"0");
        }
        else
            previousMonthString = AncillaryMethods::IntToStringConversion(previousMonth);

        dateWithPreviousMonth = currentDateString.replace(4,2,previousMonthString);
    }

    return dateWithPreviousMonth;
}
