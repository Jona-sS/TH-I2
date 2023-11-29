#include "TransactionList.h"
#include <QFile>

void TransactionList::add(const Transaction & transaction)
{
    list.push_back(transaction);
}

void TransactionList::save(const QString & filename) const
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        qFatal("Cannot open %s for writing", qPrintable(filename));
    }

    file.write("static const fsm_transaction_t s_transaction_list[] = {\n");

    for (int i = 0; i < list.size(); i++) {
        const Transaction & transaction = list.at(i);
        file.write(transaction.toString().toUtf8());

        if ( (i+1) != list.size() ) file.write(",");
        file.write("\n");
    }
    file.write("};\n");

    file.close();
}
