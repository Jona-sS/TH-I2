#include "view.h"
#include "io.h"
#include <stdio.h>

#define S_MACHINE_HEAD \
        " /-----------------------------------\\\n" \
        " | %33s |\n" \
        " \\-----------------------------------/\n" \
        " \n" \
        "                      /~~~~~~~~~~~/|  \n" \
        "                     / /#########/ / |\n" \
        "                    / /_________/ /  |\n" \
        "                   =============== /||\n" \
        "                   |    %03d EUR  |/ ||\n" \
        "                   |_____________|/ ||\n" \
        "                    | \\___..___/    ||\n" \
        "                    |     ||        ||\n"


#define S_MACHINE_NO_COFFEE \
        "                    |               ||\n" \
        "                    |               ||\n" \
        "                    |               ||\n"

#define S_MACHINE_COFFEE \
        "                    |    )  (       ||\n" \
        "                    |   (   ) )     ||\n" \
        "                    |    ) ( (      ||\n" \

#define S_MACHINE_NO_CUP \
        "     _________      |               ||\n" \
        "  .-'---------|     |_______________||\n" \
        " ( C|/\\/\\/\\/\\/|     |              / |\n" \
        "  '-./\\/\\/\\/\\/|    _|_ _ _ _ _ _ _/  |\n" \
        "    '_________'   |               | / \n" \
        "     '-------'    |_______________|/  \n" \
        " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n"

#define S_MACHINE_CUP \
        "                    |  _________    ||\n" \
        "                    .-'---------|___||\n" \
        "                   ( C|/\\/\\/\\/\\/|  / |\n" \
        "                   _'-./\\/\\/\\/\\/|_/  |\n" \
        "                  |   '_________' | / \n" \
        "                  |____'-------'__|/  \n" \
        " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n"

#define S_MACHINE_NO_COIN_RETURN "\n"

#define S_MACHINE_INVALID_COIN_RETURN \
        " -> keine Muenze verfuegbar !!!\n"

#define S_MACHINE_COIN_RETURN \
        " -> %0d Euro zurueck\n"


/* machine status variables */
static int s_has_cup = 0;
static int s_coin_value = 0;

/* function implementations */
void view_show(fsm_action_t out_vector)
{
    int i;
    for (i = 0; i < 100; i++) printf("\n");

    printf(S_MACHINE_HEAD, out_vector.display_string, out_vector.guthaben);

    if (out_vector.kaffee_los) printf(S_MACHINE_COFFEE);
    else                       printf(S_MACHINE_NO_COFFEE);

    if (s_has_cup) printf(S_MACHINE_CUP);
    else           printf(S_MACHINE_NO_CUP);

    if (out_vector.muenz_rueck) {
        if (s_coin_value) printf(S_MACHINE_COIN_RETURN, s_coin_value);
        else              printf(S_MACHINE_INVALID_COIN_RETURN);
    } else {
        printf(S_MACHINE_NO_COIN_RETURN);
    }
}

view_menu_t view_menu()
{
    int read = io_read_signed_number(
           "\n"
           "  0) Einwurf 1 Euro\n"
           "  1) Einwurf 2 Euro\n"
           "  2) Becher verstellen\n"
           "  3) Reset\n"
           "  4) Automatischer Testlauf\n"
           "  5) Programm beenden\n"
           "\n"
           " Auswahl: ");

    switch (read) {
        case 0:  return VIEW_1_EURO;
        case 1:  return VIEW_2_EURO;
        case 2:  return VIEW_CUP;
        case 3:  return VIEW_RESET;
        case 4:  return VIEW_CHECK;
        case 5:  return VIEW_EXIT;
        default: return VIEW_INVALID;
    }
}

void view_toggle_cup()        { s_has_cup = s_has_cup ? 0 : 1; }
int  view_has_cup()           { return s_has_cup; }
void view_set_coin(int value) { s_coin_value = value; }

void view_reset()
{
    s_has_cup = 0;
    s_coin_value = 0;
}
