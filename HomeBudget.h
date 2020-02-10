#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include "UserManager.h"
#include "IncomesManager.h"
#include "ExpensesManager.h"
#include "BalanceSheetManager.h"

class HomeBudget
{
    UserManager userManager;
    IncomesManager* incomesManager;
    ExpensesManager* expensesManager;
    BalanceSheetManager* balanceSheetManager;

    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;

public:
    HomeBudget(string usersFilename="users.xml",string incomesFilename="incomes.xml",string expensesFilename="expenses.xml");
    void registerUser();
    void logIn();
    void changePasswordOfLoggedInUser();
    void logOut();
    void addNewIncome();
    void addNewExpense();
    void showBalanceSheetFromCurrentMonth();
    void showBalanceSheetFromPreviousMonth();
    void showBalanceSheetFromSelectedPeriod();
    bool isUserLoggedIn();
    void listAllIncomes();
    void listAllExpenses();
    char selectChoiceFromMainMenu();
    char selectChoiceFromUserMenu();

};

#endif // HOMEBUDGET_H
