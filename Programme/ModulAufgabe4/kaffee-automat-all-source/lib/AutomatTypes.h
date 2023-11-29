#pragma once

#include <stdint.h>

extern "C" {
#include "automat.h"
}

namespace AutomatTypes
{

struct In
{
    bool becher;
    bool muenze;
    bool muenz_wert;

    In(bool becher, bool muenze, bool muenz_wert)
     : becher(becher),
       muenze(muenze),
       muenz_wert(muenz_wert) {}
   
};

struct Out
{
    fsm_action_t vector;
    Out(const fsm_action_t vector) : vector(vector) {}
};

} /* end of namespace AutomatTypes */
