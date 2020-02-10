#include "BalanceSheetManager.h"

void BalanceSheetManager::showBalanceSheetFromCurrentMonth(vector<Income> incomes,vector<Expense> expenses)
{
    int dateOfFirstDayOfCurrentMonth = datesManager.getDateOfFirstDayOfCurrentMonth();
    int dateOfLastDayOfCurrentMonth = datesManager.getDateOfLastDayOfCurrentMonth();
    showBalanceSheetFromSpecifiedPeriod(incomes,expenses,dateOfFirstDayOfCurrentMonth,dateOfLastDayOfCurrentMonth);
}

void BalanceSheetManager::showBalanceSheetFromPreviousMonth(vector<Income> incomes,vector<Expense> expenses)
{
    int dateOfFirstDayOfPreviousMonth = datesManager.getDateOfFirstDayOfPreviousMonth();
    int dateOfLastDayOfPreviousMonth = datesManager.getDateOfLastDayOfPreviousMonth();
    showBalanceSheetFromSpecifiedPeriod(incomes,expenses,dateOfFirstDayOfPreviousMonth,dateOfLastDayOfPreviousMonth);
}

void BalanceSheetManager::showBalanceSheetFromSelectedPeriod(vector<Income> incomes,vector<Expense> expenses)
{
    int startDate = 0,endDate = 0;
    do
    {
        cout << "Enter start date. Please use yyyy-mm-dd format: ";
        startDate = datesManager.enterNewDate();
        cout << "Enter end date. Please use yyyy-mm-dd format: ";
        endDate = datesManager.enterNewDate();
        if(startDate > endDate)
            cout << "End date must be greater than start date. Try again." << endl;
    } while(startDate > endDate);

    showBalanceSheetFromSpecifiedPeriod(incomes,expenses,startDate,endDate);
}

void BalanceSheetManager::showBalanceSheetFromSpecifiedPeriod(vector<Income> incomes,vector<Expense> expenses,int startDate,int endDate)
{
    vector<Income> incomesFromSpecifiedPeriod;
    vector<Expense> expensesFromSpecifiedPeriod;
    float totalIncome=0,totalExpense=0,balance=0;

    system("cls");
    cout << ">>> BALANCE SHEET FROM " << AncillaryMethods::convertDateFromIntToString(startDate) << " TO " << AncillaryMethods::convertDateFromIntToString(endDate) << " <<<\n" << endl;

    for(int i = 0; i < incomes.size(); i++)
    {
        if(incomes[i].getDate() <= endDate && incomes[i].getDate() >= startDate)
        {
            incomesFromSpecifiedPeriod.push_back(incomes[i]);
            totalIncome += incomes[i].getAmount();
        }
    }

    for(int i = 0; i < expenses.size(); i++)
    {
        if(expenses[i].getDate() <= endDate && expenses[i].getDate() >= startDate)
        {
            expensesFromSpecifiedPeriod.push_back(expenses[i]);
            totalExpense += expenses[i].getAmount();
        }
    }
    sort(incomesFromSpecifiedPeriod.begin(),incomesFromSpecifiedPeriod.end());
    cout << ">>> INCOMES <<<\n " << endl;
    for(int i = 0; i < incomesFromSpecifiedPeriod.size(); i++)
        cout << "Date: " << AncillaryMethods::convertDateFromIntToString(incomesFromSpecifiedPeriod[i].getDate()) << "\nItem: " << incomesFromSpecifiedPeriod[i].getItem() << "\nAmount: " << incomesFromSpecifiedPeriod[i].getAmount() << " PLN\n" << endl;

    sort(expensesFromSpecifiedPeriod.begin(),expensesFromSpecifiedPeriod.end());
    cout << ">>> EXPENSES <<<\n" << endl;
    for(int i = 0; i < expensesFromSpecifiedPeriod.size(); i++)
        cout << "Date: " << AncillaryMethods::convertDateFromIntToString(expensesFromSpecifiedPeriod[i].getDate()) << "\nItem: " << expensesFromSpecifiedPeriod[i].getItem() << "\nAmount: " << expensesFromSpecifiedPeriod[i].getAmount() << " PLN\n" << endl;

    balance = totalIncome - totalExpense;
    cout <<"TOTAL INCOME: " << totalIncome << " PLN" << endl;
    cout <<"TOTAL EXPENSE: " << totalExpense << " PLN" << endl;
    cout <<"BALANCE: " << balance << " PLN" << endl;
    system("pause");
}
