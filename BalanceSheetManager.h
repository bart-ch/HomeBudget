#ifndef BALANCESHEETMANAGER_H
#define BALANCESHEETMANAGER_H

#include "DatesManager.h"
#include "Expense.h"
#include "Income.h"
#include "AncillaryMethods.h"
#include <vector>

using namespace std;


class BalanceSheetManager
{
    DatesManager datesManager;
    void showBalanceSheetFromSpecifiedPeriod(vector<Income> incomes,vector<Expense> expenses,int startDate,int endDate);

    public:
        void showBalanceSheetFromCurrentMonth(vector<Income> incomes,vector<Expense> expenses);
        void showBalanceSheetFromPreviousMonth(vector<Income> incomes,vector<Expense> expenses);
        void showBalanceSheetFromSelectedPeriod(vector<Income> incomes,vector<Expense> expenses);

};

#endif // BALANCESHEETMANAGER_H
