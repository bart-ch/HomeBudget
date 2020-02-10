#ifndef INCOMESFILES_H
#define INCOMESFILES_H

#include "XmlFile.h"
#include "Income.h"
#include "Markup.h"
#include "AncillaryMethods.h"
#include <vector>
#include <cmath>


class IncomesFiles : public XmlFile
{
    int idOfLastIncome;

    public:
        IncomesFiles(string filename);
        void addIncomeToFile(Income income);
        vector<Income> loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser);
        int getIdOfLastIncome();
};

#endif // INCOMESFILES_H
