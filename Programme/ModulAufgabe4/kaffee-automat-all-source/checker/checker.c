#include "checker.h"
#include <stdio.h>

typedef struct {
    BOOL reset;
    BOOL muenz_wert;
    BOOL muenze;
    BOOL becher;
} fsm_input_t;

typedef struct {
    fsm_input_t input;
    fsm_action_t output;
} fsm_transaction_t;

#include "s_transaction_list.h"

static const int s_transaction_list_size =
    sizeof(s_transaction_list) / sizeof(*s_transaction_list);

#define ERROR_STRING_SIZE 1000
static char s_error_string[ERROR_STRING_SIZE] = { 0 };

static void checker_propagate_input(fsm_input_t input);
static BOOL checker_compare(fsm_action_t o1, fsm_action_t o2);
static void checker_write_error_string(
    fsm_action_t current, fsm_input_t input,
    fsm_action_t actual, fsm_action_t expected);
static void checker_clear_error_string(void);

/*****************************************************************************/
/* implementation of extern functions ****************************************/
/*****************************************************************************/

BOOL checker_check()
{
    fsm_action_t last_out;
    fsm_action_t new_out;
    int i;

    automat_reset();

    for (i = 0; i < s_transaction_list_size; i++) {
        
        last_out = automat_output();
        
        checker_propagate_input(s_transaction_list[i].input);

        new_out = automat_output();
        
        if (!checker_compare(new_out, s_transaction_list[i].output)) {
            checker_write_error_string(last_out, s_transaction_list[i].input,
                                       new_out,  s_transaction_list[i].output);
            return false;
        }
    }

    checker_clear_error_string();

    return true;
}

const char * checker_error_string() { return s_error_string; }


/*****************************************************************************/
/* implementation of static functions ****************************************/
/*****************************************************************************/

void checker_propagate_input(fsm_input_t input)
{
    if (input.reset) automat_reset();
    else automat_transition(input.becher, input.muenze, input.muenz_wert);
}

BOOL checker_compare(fsm_action_t o1, fsm_action_t o2)
{
    return o1.display     == o2.display &&
           o1.muenz_rueck == o2.muenz_rueck &&
           o1.kaffee_los  == o2.kaffee_los &&
           o1.guthaben    == o2.guthaben;
}

void checker_write_error_string(
    fsm_action_t current, fsm_input_t input,
    fsm_action_t actual, fsm_action_t expected)
{
    if (input.reset) {
        /* actually wanna use snprintf, but it's defined in c99 */
        sprintf(s_error_string,
            "Ausgangsvektor enthält nicht die erwarteten Werte:\n"
            "Letzter Zustand: disp:%d rueck:%d los:%d guthaben:%d \"%s\"\n"
            "Eingang:  Reset\n"
            "Ausgang:  disp:%d rueck:%d los:%d guthaben:%d \"%s\"\n"
            "Erwartet: disp:%d rueck:%d los:%d guthaben:%d",
                current.display, current.muenz_rueck, current.kaffee_los,
                current.guthaben, current.display_string,
                actual.display, actual.muenz_rueck, actual.kaffee_los,
                actual.guthaben, actual.display_string,
                expected.display, expected.muenz_rueck, expected.kaffee_los,
                expected.guthaben);
    } else {
        /* actually wanna use snprintf, but it's defined in c99 */
        sprintf(s_error_string,
            "Ausgangsvektor enthält nicht die erwarteten Werte:\n"
            "Letzter Zustand: disp:%d rueck:%d los:%d guthaben:%d \"%s\"\n"
            "Eingang:  becher:%d muenze:%d muenz_wert:%d\n"
            "Ausgang:  disp:%d rueck:%d los:%d guthaben:%d \"%s\"\n"
            "Erwartet: disp:%d rueck:%d los:%d guthaben:%d",
                current.display, current.muenz_rueck, current.kaffee_los,
                current.guthaben, current.display_string,
                input.becher, input.muenze, input.muenz_wert,
                actual.display, actual.muenz_rueck, actual.kaffee_los,
                actual.guthaben, actual.display_string,
                expected.display, expected.muenz_rueck, expected.kaffee_los,
                expected.guthaben);
    }
}

void checker_clear_error_string()
{
    s_error_string[0] = '\0';
}
