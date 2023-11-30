/**********************************************************************\
 * Kurzbeschreibung: automat.c
 * Stellt Funktionen zur Realisierung eines Automaten zur Verf�gung,
 * die �ber die in der automat.h vorgegebene C-Schnittstelle
 * mit einer grafischen Schnittstelle kommunizieren.
 *
 * Datum:       Autor:        Grund der Aenderung:
 *
 *
\**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "automat.h"

/*--- #defines -------------------------------------------------------*/
/* Macro zur Ermittlung der Array Groesse */
#define SIZE_OF(a) (sizeof((a)) / sizeof(*(a)))

#define NR_OF_STATES (I - A + 1)

/*--- Datentypen (typedef) -------------------------------------------*/
/* Definition der Zustaende */
typedef enum
{
  A = 0,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I
} state_t;

/* Definition der fsm-spezifischen Variablen */
/* Struktur zur Beschreibung eines Uebergangs mit "Don't Care"-Moeglichkeit */
typedef struct
{
  int input;
  int mask;
  state_t nxtstate;
} fsm_state_t;

/* Struktur zur Beschreibung aller Uebergaenge eines Zustands */
typedef struct
{
  const fsm_state_t *transitions;
  int nrOfTransitions;
  state_t defaultNxtState;
} fsm_full_state_t;

/*--- Modulglobale static Variablen ----------------------------------*/
/* Definition der Zustandsvariablen */
static state_t s_curstate = A; /* Initialisierung */

/* Definition aller Zustandsuebergaenge fuer jeden Zustand */
static const fsm_state_t s_transitions_A[] =
    {
        /*    input   mask      nxtstate */
        {0x002, ~0x004, B},
        {0x003, ~0x004, C} // Transitionsbedingungen um von A nach C zu kommen -11 wobei ~0x004 den 3. bit raus nimmt
};

static const fsm_state_t s_transitions_B[] =
    {/*    input   mask      nxtstate */
     {0x002, ~0x004, C},
     {0x003, ~0x004, D}};

static const fsm_state_t s_transitions_C[] =
    {/*    input   mask      nxtstate */
     {0x002, ~0x004, D},
     {0x003, ~0x000, F},
     {0x007, ~0x000, H}};

static const fsm_state_t s_transitions_D[] =
    {/*    input   mask      nxtstate */
     {0x002, ~0x000, F},
     {0x003, ~0x004, E},
     {0x006, ~0x000, H}};

static const fsm_state_t s_transitions_E[] =
    {/*    input   mask      nxtstate */
     /* TODO   */
     {0x002, ~0x000, F},
     {0x006, ~0x000, H},
     {0x000, ~0x005, D}};

static const fsm_state_t s_transitions_F[] =
    {
        /*    input   mask      nxtstate */
        /* TODO   */
        {0x004, ~0x001, H},
        {0x002, ~0x001, G},
        {0x006, ~0x001, I}
        };


static const fsm_state_t s_transitions_G[] =
    {/*    input   mask      nxtstate */
     /* TODO   */
     {0x004, ~0x001, H},
     {0x006, ~0x001, I},
     {0,~0x005,F}};


static const fsm_state_t s_transitions_H[] =
    {/*    input   mask      nxtstate */
     /* TODO   */
     {0, ~0x001, A},
     {0x006, ~0x001, I},
     {0x002, ~0x000, B},
     {0x003, ~0x000, C}
     };

static const fsm_state_t s_transitions_I[] =
    {/*    input   mask      nxtstate */
     /* TODO   */
     {0, ~0x001, A},
     {0x002, ~0x000, B},
     {0x003, ~0x000 , C},
     {0x004, ~0x001 , H}
     };

/* Definition der Uebergangstabelle */
/* Die Reihenfolge der Zustaende in der enum Definition muss der
 * Reihenfolge der Zustaende in der Uebergangstabelle entsprechen
 *                 [Zeile] [Spalte] */
static const fsm_full_state_t s_state_table[NR_OF_STATES] =
    {
        /* transitions     nrOfTransitions           defaultNxtState */
        {s_transitions_A, SIZE_OF(s_transitions_A), A},
        {s_transitions_B, SIZE_OF(s_transitions_B), B},
        {s_transitions_C, SIZE_OF(s_transitions_C), C},
        {s_transitions_D, SIZE_OF(s_transitions_D), D},
        /* TODO   */
        {s_transitions_E, SIZE_OF(s_transitions_E), E},
        {s_transitions_F, SIZE_OF(s_transitions_F), F},
        {s_transitions_G, SIZE_OF(s_transitions_G), G},
        {s_transitions_H, SIZE_OF(s_transitions_H), H},
        {s_transitions_I, SIZE_OF(s_transitions_I), I}
        /* {    } */
};

/* Definition der Ausgaenge */
static const fsm_action_t s_out_table[NR_OF_STATES] =
    {
        /* display    muenz_rueck   kaffee_los     guthaben,   display_string */
        {false, false, false, 0, "Warten"},                /* state A */
        {false, false, false, 1, "1 Euro"},                /* state B */
        {false, false, false, 2, "2 Euro"},                /* state C */
        {false, false, false, 3, "3 Euro"},                /* state D */
                                                           /* TODO   */
        {false, true, false, 3, "3 Euro"},                 /* state E */
        {true, false, false, 4, "4 Euro"},                 /* state F */
        {true, true, false, 4, "4 Euro"},                  /* state G */
        {true, false, true, 0, "Kaffee wird zubereitet"}, /* state H */
        {true, true, true, 0, "Kaffee wird zubereitet"}   /* state I */

        /* {    } */
};

/*--- Funktionsdefinition --------------------------------------------*/
void automat_reset(void)
{
  printf("---- automat_reset ----\n");
  /* TODO go into IDLE state */
  s_curstate = A;
  automat_output();
}

/*--- Funktionsdefinition --------------------------------------------*/
void automat_transition(BOOL becher, BOOL muenze, BOOL muenz_wert)
{
    printf("---- automat_transition becher(%0d) muenze(%0d) muenz_wert(%0d) ----\n",
           becher, muenze, muenz_wert);
    /* TODO do automat transitions */
}

/*--- Funktionsdefinition --------------------------------------------*/
fsm_action_t automat_output(void)
{
  return s_out_table[s_curstate];
}
