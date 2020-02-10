#include "Transaction.h"

void Transaction::setTransactionId(int transactionId)
{
    this->transactionId = transactionId;
}

void Transaction::setUserId(int userId)
{
    this->userId = userId;
}

void Transaction::setDate(int date)
{
    this->date = date;
}

void Transaction::setAmount(float amount)
{
    this->amount = amount;
}

void Transaction::setItem(string item)
{
    this->item = item;
}

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getUserId()
{
    return userId;
}
int Transaction::getDate()
{
    return date;
}
float Transaction::getAmount()
{
    return amount;
}
string Transaction::getItem()
{
    return item;
}
