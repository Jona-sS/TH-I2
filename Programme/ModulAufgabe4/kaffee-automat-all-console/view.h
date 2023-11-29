#pragma once

#include "automat.h"

typedef enum { VIEW_1_EURO, VIEW_2_EURO, VIEW_CUP, VIEW_RESET, VIEW_CHECK, VIEW_EXIT, VIEW_INVALID } view_menu_t;

extern void view_show(fsm_action_t out_vector);

extern view_menu_t view_menu(void);

extern void view_toggle_cup(void);
extern int  view_has_cup(void);

extern void view_set_coin(int value);

extern void view_reset(void);
