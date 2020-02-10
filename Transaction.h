#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
    int transactionId,userId,date;
    float amount;
    string item;

public:

    void setTransactionId(int transactionId);
    void setUserId(int userId);
    void setDate(int date);
    void setAmount(float amount);
    void setItem(string item);

    int getTransactionId();
    int getUserId();
    int getDate();
    float getAmount();
    string getItem();

    bool operator<( const Transaction& val ) const
    {
        return date < val.date;
    }
};

#endif // TRANSACTION_H
