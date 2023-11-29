#include "Input.h"
#include "Output.h"
#include <QHash>
#include <iostream>

#include "TransactionList.h"

extern "C" {
#include "automat.h"
}

typedef QHash< Input, int> InputCounter;
typedef QHash< Output, QHash< Input, int > > TransactionCounter;

void addTransactionCount(TransactionCounter & counter, const Output & out, const Input & in)
{
    TransactionCounter::iterator trans_it = counter.find(out);
    if (trans_it == counter.end()) {
        // add new InputCounter for out
        InputCounter new_in_cnt;
        new_in_cnt.insert(in, 1);
        counter.insert(out, new_in_cnt);
    } else {
        InputCounter & in_cnt = *trans_it;
        in_cnt[in] = in_cnt.value(in, 0) + 1;
    }
}

void printTransactions(const TransactionCounter & counter)
{
    for (TransactionCounter::const_iterator trans_it = counter.begin();
         trans_it != counter.end(); ++trans_it) {

        std::cout <<     " - " << trans_it.value().size() << " ";
        trans_it.key().print(std::cout);
        std::cout << ((trans_it.value().size() == Input::POSSIBILITIES) ? " (full)" : " (not full)" )
                  << std::endl;

        for (InputCounter::const_iterator in_it = trans_it.value().begin();
             in_it != trans_it.value().end(); ++in_it) {
            std::cout << " +-> "; in_it.key().print(std::cout);
            std::cout << in_it.value() << std::endl;
        }
    }
}

int main()
{
    Input in;
    Output out;

    TransactionCounter counter;

    automat_reset();
    out.read();

    TransactionList tList;

    for (int i = 0; i < 100000; i++) {
        in.randomize();

        addTransactionCount(counter, out, in);

        in.propagate();

        out.read();
        tList.add(Transaction(in, out));
    }
    tList.save("s_transaction_list.h");
    printTransactions(counter);
}
