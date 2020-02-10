#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include "Expense.h"
#include "AncillaryMethods.h"
#include "DatesManager.h"
#include "ExpensesFiles.h"
#include <math.h>
#include <vector>
#include <iostream>

class ExpensesManager
{
    const int ID_OF_LOGGED_IN_USER;
    vector<Expense> expenses;
    Expense enterDataOfNewExpense();
    DatesManager datesManager;
    ExpensesFiles expensesFiles;

public:
    ExpensesManager(int idOfLoggedInUser,string expensesFilename);
    void addNewExpense();
    void listAllExpenses();
    vector<Expense> getExpensesOfLoggedInUser();
};

#endif // EXPENSESMANAGER_H
