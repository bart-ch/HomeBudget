#include "ExpensesManager.h"

ExpensesManager::ExpensesManager(int idOfLoggedInUser, string expensesFilename)
    : ID_OF_LOGGED_IN_USER(idOfLoggedInUser),
      expensesFiles(expensesFilename)
{
    expenses = expensesFiles.loadExpensesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
}

void ExpensesManager::addNewExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> NEW EXPENSE MENU <<<" << endl << endl;
    expense = enterDataOfNewExpense();

    expenses.push_back(expense);
    expensesFiles.addExpenseToFile(expense);
    cout << "New expense has been added." << endl;

    system("Pause");

}

Expense ExpensesManager::enterDataOfNewExpense()
{
    Expense expense;
    char choice;
    string amount;
    float amountFloat,amountRoundedToNearest;

    expense.setUserId(ID_OF_LOGGED_IN_USER);
    expense.setTransactionId(expensesFiles.getIdOfLastExpense() + 1);

    cout << endl << "Is the expense from today? Press 'y' to confirm. Press any key to enter own date: ";
    choice = AncillaryMethods::getCharacter();

    if (choice == 'y')
        expense.setDate(datesManager.getCurrentDate());
    else
    {
        cout << "Enter date of the expense. Please use yyyy-mm-dd format: ";
        expense.setDate(datesManager.enterNewDate());
    }



    cout << "What is the expense: ";
    expense.setItem(AncillaryMethods::getSingleLine());

    cout << "What is the amount of the expense[PLN]: ";
    amount = AncillaryMethods::getSingleLine();
    amount = AncillaryMethods::replaceComaWithPeriod(amount);
    while(!AncillaryMethods::isAmountFormatCorrect(amount))
    {
        amount = AncillaryMethods::getSingleLine();
        amount = AncillaryMethods::replaceComaWithPeriod(amount);
    }

    amountFloat = atof(amount.c_str());
    amountRoundedToNearest = roundf(amountFloat * 100) / 100;
    expense.setAmount(amountRoundedToNearest);

    return expense;
}

void ExpensesManager::listAllExpenses()
{
    for(int i = 0; i < expenses.size(); i++)
    {
        cout << expenses[i].getUserId() << endl;
        cout << expenses[i].getTransactionId() << endl;
        cout << expenses[i].getDate()<< endl;;
        cout << expenses[i].getAmount()<< endl;;
        cout << expenses[i].getItem()<< endl;;
    }
    system("pause");
}

vector<Expense> ExpensesManager::getExpensesOfLoggedInUser()
{
    return expenses;
}



