<<<<<<< HEAD
/**********************************************************************\
* Kurzbeschreibung:
* queue.c - realisiert eine Queue (Warteschlange)
*
* Datum: 27.11.2023     Autor: Seuber / Duchow
*
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

typedef struct Warteschlange	//Struct anlegen mit Verkettungszeiger der dann immer auf die nächste Struct Ebene zeigt
{
	int Datenpunkt;
	struct Warteschlange *weiter;
} Warteschlange;

static Warteschlange *start = 0; // Startzeiger auf Anfang von Warteschlange
static Warteschlange *ende = 0;	 // Endzeiger aufs Ende von Warteschlange

// Zeiger auf das Ende der Schlange
/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
 * Einfuegen in Liste
 * Parameter:
 *    zahl  fügt die übergebene Zahl 'zahl' am Ende der Liste ein
 * Return Wert:
 *    TRUE  wenn noch genug Speicherplatz vorhanden
 *    FALSE wenn kein Speicherplatz mehr allokiert werden konnte
 *--------------------------------------------------------------------*/
Bool put(int zahl)
{
	Warteschlange *neuerDatenpunkt = malloc(sizeof(struct Warteschlange)); // Neuen Zeiger erstellen um neue Zahl in die Warteschlange zu packen
	if (neuerDatenpunkt == 0)
		return -1;

	neuerDatenpunkt->Datenpunkt = zahl;
	neuerDatenpunkt->weiter = 0;

	if (start == 0) // Am Anfang den Startzeiger auf den ersten Wert legen , sonst den Endzeiger bei neuen Zahlen weiterschieben
	{
		start = neuerDatenpunkt;
	}
	else
	{
		ende->weiter = neuerDatenpunkt; // Wenn es nicht der Anfang ist dann wird bei jedem neuen Struct Aufruf der Endzeiger auf den neuen hinzugefügten Zeiger gelegt
	}
	ende = neuerDatenpunkt; // Den Endzeiger auf letzten hinzugefügten Wert legen

	return TRUE;
}

/*--------------------------------------------------------------------*\
 * Auslesen aus Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    Zahl am Anfang der Liste oder aber QLEER, wenn Liste leer ist.
 *--------------------------------------------------------------------*/

int get(void)
{
	if (isEmpty()) // Wenn Warteschlange leer , also start = end dann return und aus.
	{
		return QLEER;
	}

	Warteschlange *werteReihe;		   // Neuen Zeiger erstellen
	werteReihe = start;				   // auf den start wert initallisieren
	int wert = werteReihe->Datenpunkt; // den Datenpunkt als int in var speichern

	if (start == 0)
	{
		ende = 0; // Damit es ausgeschalten wird
	}

	start = start->weiter; // Den Startzeiger weiterschieben in die nächste Struct Ebene
	free(werteReihe);	   // Speicher von dem dann ausgebener Struct löschen

	return wert;
}

/*--------------------------------------------------------------------*\
 * Pruefen der Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    liefert TRUE, wenn Queue leer ist, sonst FALSE
 *--------------------------------------------------------------------*/
Bool isEmpty(void)
{
	return ((start == 0) && (ende == 0)); // überprüfung
}
=======
/**********************************************************************\
* Kurzbeschreibung:
* queue.c - realisiert eine Queue (Warteschlange)
*
* Datum: 27.11.2023     Autor: Seuber / Duchow
*
*
\**********************************************************************/

/*--- #includes ------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*--- #defines -------------------------------------------------------*/

/*--- Lokale Datentypen (typedef) ------------------------------------*/

/*--- Modulglobale static Variablen ----------------------------------*/

/*--- Prototypen lokaler Funktionen ----------------------------------*/

typedef struct Warteschlange	//Struct anlegen mit Verkettungszeiger der dann immer auf die nächste Struct Ebene zeigt
{
	int Datenpunkt;
	struct Warteschlange *weiter;
} Warteschlange;

static Warteschlange *start = 0; // Startzeiger auf Anfang von Warteschlange
static Warteschlange *ende = 0;	 // Endzeiger aufs Ende von Warteschlange

// Zeiger auf das Ende der Schlange
/*--- Funktionsdefinitionen ------------------------------------------*/

/*--------------------------------------------------------------------*\
 * Einfuegen in Liste
 * Parameter:
 *    zahl  fügt die übergebene Zahl 'zahl' am Ende der Liste ein
 * Return Wert:
 *    TRUE  wenn noch genug Speicherplatz vorhanden
 *    FALSE wenn kein Speicherplatz mehr allokiert werden konnte
 *--------------------------------------------------------------------*/
Bool put(int zahl)
{
	Warteschlange *neuerDatenpunkt = malloc(sizeof(struct Warteschlange)); // Neuen Zeiger erstellen um neue Zahl in die Warteschlange zu packen
	if (neuerDatenpunkt == 0)
		return -1;

	neuerDatenpunkt->Datenpunkt = zahl;
	neuerDatenpunkt->weiter = 0;

	if (start == 0) // Am Anfang den Startzeiger auf den ersten Wert legen , sonst den Endzeiger bei neuen Zahlen weiterschieben
	{
		start = neuerDatenpunkt;
	}
	else
	{
		ende->weiter = neuerDatenpunkt; // Wenn es nicht der Anfang ist dann wird bei jedem neuen Struct Aufruf der Endzeiger auf den neuen hinzugefügten Zeiger gelegt
	}
	ende = neuerDatenpunkt; // Den Endzeiger auf letzten hinzugefügten Wert legen

	return TRUE;
}

/*--------------------------------------------------------------------*\
 * Auslesen aus Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    Zahl am Anfang der Liste oder aber QLEER, wenn Liste leer ist.
 *--------------------------------------------------------------------*/

int get(void)
{
	if (isEmpty()) // Wenn Warteschlange leer , also start = end dann return und aus.
	{
		return QLEER;
	}

	Warteschlange *werteReihe;		   // Neuen Zeiger erstellen
	werteReihe = start;				   // auf den start wert initallisieren
	int wert = werteReihe->Datenpunkt; // den Datenpunkt als int in var speichern

	if (start == 0)
	{
		ende = 0; // Damit es ausgeschalten wird
	}

	start = start->weiter; // Den Startzeiger weiterschieben in die nächste Struct Ebene
	free(werteReihe);	   // Speicher von dem dann ausgebener Struct löschen

	return wert;
}

/*--------------------------------------------------------------------*\
 * Pruefen der Liste
 * Parameter:
 *    keine
 * Return Wert:
 *    liefert TRUE, wenn Queue leer ist, sonst FALSE
 *--------------------------------------------------------------------*/
Bool isEmpty(void)
{
	return ((start == 0) && (ende == 0)); // überprüfung
}
>>>>>>> 389ad4c680344541f2ef886850d4ed8106416293
