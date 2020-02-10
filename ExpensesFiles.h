#ifndef EXPENSESFILES_H
#define EXPENSESFILES_H

#include "XmlFile.h"
#include "Expense.h"
#include "Markup.h"
#include "AncillaryMethods.h"
#include <vector>
#include <cmath>

class ExpensesFiles : public XmlFile
{
    int idOfLastExpense;

    public:
        ExpensesFiles(string filename);
        void addExpenseToFile(Expense expense);
        vector<Expense> loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser);
        int getIdOfLastExpense();
};

#endif // EXPENSESFILES_H
