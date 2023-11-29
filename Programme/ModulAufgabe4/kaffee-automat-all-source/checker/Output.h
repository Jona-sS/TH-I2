#pragma once

#include <ostream>
#include <QtGlobal>

extern "C" {
#include "automat.h"
}

class Output
{
    public:
        Output() {}

        QString toString() const;
        QString toPrettyString() const;

        void read();

        void print(std::ostream & os) const;

        bool operator==(const Output & o) const;

        friend uint qHash(const Output & output);

    private:
        fsm_action_t out;
};
