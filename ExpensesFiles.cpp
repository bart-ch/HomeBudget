#include "ExpensesFiles.h"

ExpensesFiles::ExpensesFiles(string filename)
    : XmlFile(filename)
{
    idOfLastExpense = 0;
}

void ExpensesFiles::addExpenseToFile(Expense expense)
{
    CMarkup xml;

    string transactionDate = AncillaryMethods::convertDateFromIntToString(expense.getDate());
    string amountOfIncome = AncillaryMethods::floatToStringConversion(expense.getAmount());

    bool fileExists = xml.Load(getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId",expense.getUserId());
    xml.AddElem("ExpenseId",expense.getTransactionId());
    xml.AddElem("Date",transactionDate);
    xml.AddElem("Item",expense.getItem());
    xml.AddElem("Amount",amountOfIncome);
    xml.Save(getFileName());

    idOfLastExpense++;
}

vector<Expense> ExpensesFiles::loadExpensesOfLoggedInUserFromFile(int idOfLoggedInUser)
{
    Expense expense;
    int idOfUserInFile, date;
    float amount;
    vector <Expense> expenses;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());

    if (fileExists)
    {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while(xml.FindElem("Expense"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            idOfUserInFile = atoi(xml.GetData().c_str());
            if(idOfLoggedInUser == idOfUserInFile)
            {
                expense.setUserId(idOfUserInFile);
                xml.FindElem("ExpenseId");
                expense.setTransactionId(atoi(xml.GetData().c_str()));
                xml.FindElem("Date");
                date = AncillaryMethods::convertDateFromStringToInt(xml.GetData());
                expense.setDate(date);
                xml.FindElem("Item");
                expense.setItem(xml.GetData());
                xml.FindElem("Amount");
                amount = stof(xml.GetData());
                expense.setAmount(amount);

                expenses.push_back(expense);
            }
            xml.OutOfElem();
            idOfLastExpense++;
        }
    }
    return expenses;
}

int ExpensesFiles::getIdOfLastExpense()
{
    return idOfLastExpense;
}

