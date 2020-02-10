#include "IncomesFiles.h"

IncomesFiles::IncomesFiles(string filename)
    : XmlFile(filename)
{
    idOfLastIncome = 0;
}

void IncomesFiles::addIncomeToFile(Income income)
{
    CMarkup xml;

    string transactionDate = AncillaryMethods::convertDateFromIntToString(income.getDate());
    string amountOfIncome = AncillaryMethods::floatToStringConversion(income.getAmount());

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("IncomeId",income.getTransactionId());
    xml.AddElem("Date",transactionDate);
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount",amountOfIncome);
    xml.Save(getFileName());

    idOfLastIncome++;
}

vector<Income> IncomesFiles::loadIncomesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Income income;
    int idOfUserInFile, date;
    float amount;
    vector <Income> incomes;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (fileExists)
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while(xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            idOfUserInFile = atoi(xml.GetData().c_str());
            if(idOfLoggedInUser == idOfUserInFile)
            {
                income.setUserId(idOfUserInFile);
                xml.FindElem("IncomeId");
                income.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = AncillaryMethods::convertDateFromStringToInt(xml.GetData());
                income.setDate(date);
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Amount");
                amount = stof(xml.GetData());
                income.setAmount(amount);

                incomes.push_back(income);
            }
            xml.OutOfElem();
            idOfLastIncome++;
        }
    }
    return incomes;
}

int IncomesFiles::getIdOfLastIncome()
{
    return idOfLastIncome;
}

