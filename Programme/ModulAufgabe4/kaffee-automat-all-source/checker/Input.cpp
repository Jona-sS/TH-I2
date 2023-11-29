#include "Input.h"
#include "Transaction.h"
#include <cstdlib>
extern "C" {
#include "automat.h"
}

#include <iostream>
#include <QStringList>

Input::Input()
 : seed(0),
   reset(false),
   muenz_wert(false),
   muenze(false),
   becher(false)
{}

void Input::randomize()
{
    reset      = random(10) == 0;
    muenz_wert = random(2)  == 0;
    muenze     = random(2)  == 0;
    becher     = random(2)  == 0;
}

void Input::propagate() const
{
    if (reset) automat_reset();
    else       automat_transition(becher, muenze, muenz_wert);
}

int Input::random(int max)
{
    return rand_r(&seed) % max;    
}

void Input::print(std::ostream & os) const
{
    os << "reset("      << reset      << ") "
       << "muenz_wert(" << muenz_wert << ") "
       << "muenze("     << muenze     << ") "
       << "becher("     << becher     << ") ";
}

bool Input::operator==(const Input & o) const
{
    return (reset && reset == o.reset) ||
          (!reset &&
           muenz_wert == o.muenz_wert &&
           muenze     == o.muenze &&
           becher     == o.becher);
}

QString Input::toString() const
{
    QStringList values;
    values << Transaction::boolToString(reset);
    values << Transaction::boolToString(muenz_wert);
    values << Transaction::boolToString(muenze);
    values << Transaction::boolToString(becher);
    return "{ " + values.join(", ") + " }";
}

QString Input::toPrettyString() const
{
    if (reset) return "reset";
    else return QString("muenz_wert(%1) muenze(%2) becher(%3)")
                    .arg(muenz_wert)
                    .arg(muenze)
                    .arg(becher);
}
