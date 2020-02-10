#include "HomeBudget.h"

HomeBudget::HomeBudget(string usersFilename,string incomesFilename,string expensesFilename)
    : userManager(usersFilename),
      INCOMES_FILENAME(incomesFilename),
      EXPENSES_FILENAME(expensesFilename)
{
}

void HomeBudget::registerUser()
{
    userManager.registerUser();
}

void HomeBudget::logIn()
{
    userManager.logIn();
    if(userManager.isUserLoggedIn())
    {
        incomesManager = new IncomesManager(userManager.getLoggedInUserId(),INCOMES_FILENAME);
        expensesManager = new ExpensesManager(userManager.getLoggedInUserId(),EXPENSES_FILENAME);
        balanceSheetManager = new BalanceSheetManager();
    }
}

void HomeBudget::changePasswordOfLoggedInUser()
{
    userManager.changePasswordOfLoggedInUser();
}

void HomeBudget::logOut()
{
    userManager.logOut();
    delete incomesManager;
    incomesManager = NULL;
    delete expensesManager;
    expensesManager = NULL;
    delete balanceSheetManager;
    balanceSheetManager = NULL;
}

char HomeBudget::selectChoiceFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AncillaryMethods::getCharacter();

    return choice;
}

char HomeBudget::selectChoiceFromUserMenu()
{
    char choice;

    system("cls");
    cout << "    >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add new income" << endl;
    cout << "2. Add new expense" << endl;
    cout << "3. Balance sheet from current month" << endl;
    cout << "4. Balance sheet from previous month" << endl;
    cout << "5. Balance sheet from selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AncillaryMethods::getCharacter();

    return choice;
}

bool HomeBudget::isUserLoggedIn()
{
    if(userManager.isUserLoggedIn())
        return true;
    else
        return false;
}
void HomeBudget::addNewIncome()
{
    if(userManager.isUserLoggedIn())
    {
        incomesManager -> addNewIncome();
    }
}

void HomeBudget::addNewExpense()
{
    if(userManager.isUserLoggedIn())
    {
        expensesManager -> addNewExpense();
    }
}

void HomeBudget::listAllIncomes()
{
    if(userManager.isUserLoggedIn())
    {
        incomesManager -> listAllIncomes();
    }
}

void HomeBudget::listAllExpenses()
{
    if(userManager.isUserLoggedIn())
    {
        expensesManager -> listAllExpenses();
    }
}

void HomeBudget::showBalanceSheetFromCurrentMonth()
{
    if(userManager.isUserLoggedIn())
    {
        balanceSheetManager -> showBalanceSheetFromCurrentMonth(incomesManager -> getIncomesOfLoggedInUser(), expensesManager -> getExpensesOfLoggedInUser());
    }
}

void HomeBudget::showBalanceSheetFromPreviousMonth()
{
    if(userManager.isUserLoggedIn())
    {
        balanceSheetManager -> showBalanceSheetFromPreviousMonth(incomesManager -> getIncomesOfLoggedInUser(), expensesManager -> getExpensesOfLoggedInUser());
    }
}

void HomeBudget::showBalanceSheetFromSelectedPeriod()
{
    if(userManager.isUserLoggedIn())
    {
        balanceSheetManager -> showBalanceSheetFromSelectedPeriod(incomesManager -> getIncomesOfLoggedInUser(), expensesManager -> getExpensesOfLoggedInUser());
    }
}
