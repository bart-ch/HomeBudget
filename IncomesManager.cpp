#include "IncomesManager.h"

IncomesManager::IncomesManager(int idOfLoggedInUser, string incomesFilename)
    : ID_OF_LOGGED_IN_USER(idOfLoggedInUser),
      incomesFiles(incomesFilename)
{
    incomes = incomesFiles.loadIncomesOfLoggedInUserFromFile(ID_OF_LOGGED_IN_USER);
}

void IncomesManager::addNewIncome()
{
    Income income;

    system("cls");
    cout << " >>> NEW INCOME MENU <<<" << endl << endl;
    income = enterDataOfNewIncome();

    incomes.push_back(income);
    incomesFiles.addIncomeToFile(income);
    cout << "New income has been added." << endl;

    system("Pause");

}

Income IncomesManager::enterDataOfNewIncome()
{
    Income income;
    char choice;
    string amount;
    float amountFloat,amountRoundedToNearest;

    income.setUserId(ID_OF_LOGGED_IN_USER);
    income.setTransactionId(incomesFiles.getIdOfLastIncome() + 1);

    cout << endl << "Is the income from today? Press 'y' to confirm. Press any key to enter own date: ";
    choice = AncillaryMethods::getCharacter();

    if (choice == 'y')
        income.setDate(datesManager.getCurrentDate());
    else
    {
        cout << "Enter date of the income. Please use yyyy-mm-dd format: ";
        income.setDate(datesManager.enterNewDate());
    }



    cout << "What is the income: ";
    income.setItem(AncillaryMethods::getSingleLine());

    cout << "What is the amount of the income[PLN]: ";
    amount = AncillaryMethods::getSingleLine();
    amount = AncillaryMethods::replaceComaWithPeriod(amount);
    while(!AncillaryMethods::isAmountFormatCorrect(amount))
    {
        amount = AncillaryMethods::getSingleLine();
        amount = AncillaryMethods::replaceComaWithPeriod(amount);
    }

    amountFloat = atof(amount.c_str());
    amountRoundedToNearest = roundf(amountFloat * 100) / 100;
    income.setAmount(amountRoundedToNearest);

    return income;
}

void IncomesManager::listAllIncomes()
{
    for(int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getTransactionId() << endl;
        cout << incomes[i].getDate()<< endl;;
        cout << incomes[i].getAmount()<< endl;;
        cout << incomes[i].getItem()<< endl;;
    }
    system("pause");
}

vector<Income> IncomesManager::getIncomesOfLoggedInUser()
{
    return incomes;
}




