#include <stdio.h>
#include "view.h"
#include "automat.h"
#include "checker.h"

void insert_1_euro(void)
{
    view_set_coin(1);
    automat_transition(view_has_cup(), true, false);
}

void insert_2_euro(void)
{
    view_set_coin(2);
    automat_transition(view_has_cup(), true, true);
}

void toggle_cup(void)
{
    view_set_coin(0);
    view_toggle_cup();
    automat_transition(view_has_cup(), false, false);
}

void check(void)
{
    printf("\n");

    if (checker_check()) {
        
        printf("Der Zustandsautomat ist correct\n");

    } else {

        printf("%s\n", checker_error_string());

    }

    printf("\nWeiter mit Return ...");
    while (getchar() != '\n');

    automat_reset();
}

int main(void)
{
    int finished = 0;

    automat_reset();
    view_reset();

    while (!finished) {
        view_menu_t selection;

        view_show(automat_output());
        selection = view_menu();

        switch (selection) {
            case VIEW_1_EURO:  insert_1_euro(); break;
            case VIEW_2_EURO:  insert_2_euro(); break;
            case VIEW_CUP:     toggle_cup(); break;
            case VIEW_RESET:   automat_reset(); view_reset(); break;
            case VIEW_CHECK:   check(); break;
            case VIEW_EXIT:    finished = 1; break;
            case VIEW_INVALID: break;
        }
    }

    return 0;
}
