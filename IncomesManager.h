#ifndef INCOMESMANAGER_H
#define INCOMESMANAGER_H

#include "Income.h"
#include "AncillaryMethods.h"
#include "DatesManager.h"
#include "IncomesFiles.h"
#include <math.h>
#include <vector>
#include <iostream>

class IncomesManager
{
    const int ID_OF_LOGGED_IN_USER;
    vector<Income> incomes;
    Income enterDataOfNewIncome();
    DatesManager datesManager;
    IncomesFiles incomesFiles;

public:
    IncomesManager(int idOfLoggedInUser,string incomesFilename);
    void addNewIncome();
    void listAllIncomes();
    vector<Income> getIncomesOfLoggedInUser();
};

#endif // INCOMESMANAGER_H
