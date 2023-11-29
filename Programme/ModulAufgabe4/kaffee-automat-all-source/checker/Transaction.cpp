#include "Transaction.h"
#include <QStringList>

Transaction::Transaction() {}

Transaction::Transaction(const Input & in, const Output & out)
 : in(in),
   out(out)
{}

QString Transaction::toString() const
{
    return "    { " + in.toString() + ", " + out.toString() + " }";
}

QString Transaction::boolToString(bool value)
{
    return value ? " true" : "false";
}
