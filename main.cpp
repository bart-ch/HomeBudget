#include "HomeBudget.h"

using namespace std;

int main()
{
     HomeBudget homeBudget;

     char choice;

     while (true)
     {
         if (homeBudget.isUserLoggedIn() == false)
         {
             choice = homeBudget.selectChoiceFromMainMenu();

             switch (choice)
             {
             case '1':
                 homeBudget.registerUser();
                 break;
             case '2':
                 homeBudget.logIn();
                 break;
             case '9':
                 exit(0);
                 break;
             default:
                 cout << endl << "There is no such option in the menu. Try again." << endl << endl;
                 system("pause");
                 break;
             }
         }
         else
         {
             choice = homeBudget.selectChoiceFromUserMenu();

             switch (choice)
             {
             case '1':
                 homeBudget.addNewIncome();
                 break;
             case '2':
                 homeBudget.addNewExpense();
                 break;
             case '3':
                 homeBudget.showBalanceSheetFromCurrentMonth();
                 break;
             case '4':
                 homeBudget.showBalanceSheetFromPreviousMonth();
                 break;
             case '5':
                 homeBudget.showBalanceSheetFromSelectedPeriod();
                 break;
             case '6':
                 homeBudget.changePasswordOfLoggedInUser();
                 break;
             case '7':
                 homeBudget.logOut();
                 break;
             }
         }
     }

    return 0;
}
