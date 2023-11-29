#pragma once

#include "Input.h"
#include "Output.h"

class Transaction
{
    public:
        Transaction();
        Transaction(const Input & in, const Output & out);

        QString toString() const;

        static QString boolToString(bool value);

        Input in;
        Output out;
};
