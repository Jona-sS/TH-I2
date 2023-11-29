#pragma once

#include "Transaction.h"
#include <QList>

class TransactionList
{
    public:
        void add(const Transaction & transaction);

        int size() const              { return list.size(); }
        const Transaction & at(int i) { return list.at(i); }

        void save(const QString & filename) const;

    private:
        QList<Transaction> list;
};
