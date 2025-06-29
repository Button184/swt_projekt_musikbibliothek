#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LAENGE 200

// --- Struct Lied ---
typedef struct {
    char titel [MAX_LAENGE];
    char interpret [MAX_LAENGE];
    char album [MAX_LAENGE];
    int lieddauer;
    int erscheinungsjahr;
} Lied;

// ----- Globale Variablen -----
char datei[MAX_LAENGE + 10]; // erweitert um einen Puffer für .csv-Endung und \0

// ----- Funktionsdeklarationen -----

void BibliothekErstellen();
void BibliothekAnzeigen(void);
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder);
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder);

// ----- Funktionsdefinitionen -----

// --- Programmstart ---
void ProgrammStart(void) {
    int auswahl = 0;
    FILE *fp = NULL;
    char name[MAX_LAENGE]; // KI-Hilfe

    printf("\n========================= Willkommen!=========================\n");
    printf("\nSoll eine bestehende Bibliothek geladen, oder eine neue Bibliothek erstellt werden?\n");
    printf("\nEine vorhandene Bibliothek laden: Drücke (1)\nEine neue Bibliothek erstellen: Drücke (2)\n");
    scanf("%d", &auswahl);
    getchar();

    if (auswahl == 1) {
        printf("Gebe den Namen deiner Bibliothek ein (ohne .csv-Endung!):\n");
        scanf("%s", name); // KI-Hilfe
        snprintf(datei, sizeof(datei), "%s.csv", name); // KI-Hilfe

        fp = fopen(datei, "r");
        if (fp == NULL) {
            printf("Diese Bibliothek konnte nicht gefunden werden.\n");
            exit(1);
        } else {
            printf("Deine Bibliothek wurde gefunden und geladen.\n");
            fclose(fp);
        }

    } else if (auswahl == 2) {
        printf("Gebe deiner Bibliothek einen Namen (ohne .csv-Endung!): ");
        scanf("%s", name);
        snprintf(datei, sizeof(datei), "%s.csv",name); // KI-Hilfe
        BibliothekErstellen();
    } else {
        printf("Eingabe ungültig\n");
        printf("Programm wird beendet...");
        exit(1);
    }
}


// --- Bibliothek Erstellen ---
void BibliothekErstellen(void) {
    FILE *fp = fopen(datei, "w");
        if (fp == NULL) {
            printf("Error: Bibliothek konnte nicht erstellt werden!\n");
            exit(1);
        }
        fclose(fp);
        printf("Erfolg: Deine Bibliothek '%s' ist erstellt!\n", datei);
}

// --- Bibliothek Anzeigen ---
// Daten werden in eine temporäre Variable geladen und wieder an den dynamischen Array zurückgegeben
void BibliothekAnzeigen(void) {
    int i = 0;
    Lied temp;
    FILE *fp = fopen(datei, "r");

    if (fp == NULL) {
        printf("Feher beim Öffnen deiner Bibliothek!\n");
        return;
    }

    printf("\n-------- Deine Bibliothek --------\n");

        //Einlesen von Lied bis Trennzeichen (,) und das für alle 5 Columns
    while (fscanf (fp, "%[^,],%[^,],%[^,],%d,%d\n",
        temp.titel,
        temp.interpret,
        temp.album,
        &temp.lieddauer,
        &temp.erscheinungsjahr) == 5) {
            printf("\nLied %d \n", ++i);
            printf("Titel: %s\n",temp.titel);
            printf("Interpret: %s\n", temp.interpret);
            printf("Album: %s\n", temp.album);
            printf("Lieddauer in (sek): %d\n", temp.lieddauer);
            printf("Erschienen: %d\n", temp.erscheinungsjahr);
    }
    if (i == 0) {
        printf("Deine Bibliothek ist leer.\n");
    }
    fclose(fp);

    // Warten auf Eingabe, ansosten das Menü die Ausgabe verdeckt
    printf("\nTaste drücken, um zum Menü zu gelangen..\n");
    getchar();
}


// --- Lied Hinzufügen ---
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder) {

    *bibliothek = (Lied*) realloc(*bibliothek, (*anzahl_lieder + 1) * sizeof(Lied));

    printf("\nFüge ein neues Lied hinzu:\n");

    printf("Titel: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_lieder].titel);
    printf("Interpet: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_lieder].interpret);
    printf("Album: ");
    scanf(" %[^\n]", (*bibliothek)[*anzahl_lieder].album);
    printf("Lieddauer (in sekunden): ");
    scanf(" %d", &(*bibliothek)[*anzahl_lieder].lieddauer);
    printf("Erscheinungsjahr: ");
    scanf(" %d", &(*bibliothek)[*anzahl_lieder].erscheinungsjahr);

    FILE *fp = fopen(datei, "a");
    if (fp == NULL) {
        printf("Error: Datei konnte nicht beschrieben werden.\n");
        return;
    }

    fprintf(fp, "%s,%s,%s,%d,%d\n",
        (*bibliothek)[*anzahl_lieder].titel,
        (*bibliothek)[*anzahl_lieder].interpret,
        (*bibliothek)[*anzahl_lieder].album,
        (*bibliothek)[*anzahl_lieder].lieddauer,
        (*bibliothek)[*anzahl_lieder].erscheinungsjahr);

    fclose(fp);
    printf("\nDein Lied wurde zur Playlist hinzugefügt!\n");

    (*anzahl_lieder)++;

    printf("\nDrücke eine Taste, um zum Menü zu gelangen.\n");
    getchar();
}

// --- Lied löschen ---
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder) {

    FILE *fp = fopen(datei, "r");
    if (fp == NULL) {
        printf("Error: Fehler beim Aufruf deiner Bibliothek.\n");
        return;
    }

    Lied temp;
    *anzahl_lieder = 0;
    *bibliothek = NULL;

    while (fscanf (fp, "%[^,],%[^,],%[^,],%d,%d\n",
        temp.titel,
        temp.interpret,
        temp.album,
        &temp.lieddauer,
        &temp.erscheinungsjahr) == 5) {
            *bibliothek = (Lied*) realloc(*bibliothek, (*anzahl_lieder + 1) * sizeof(Lied));
            if (*bibliothek == NULL) {
                printf("Fehler beim Laden deiner Bibliotek\n");
                fclose(fp);
                return;
            }

            (*bibliothek)[*anzahl_lieder] = temp;
            (*anzahl_lieder)++;
        }
        fclose(fp);

    if (*anzahl_lieder == 0) {
        printf("Deine Bibliothek ist leer :/\n");
        return;
    }

    printf("\n-------- Deine aktuelle Bibliothek --------\n");
    for (int i = 0; i < *anzahl_lieder; i++) {
        printf("%d. %s - %s - %s - %d - %d\n", i + 1,
            (*bibliothek)[i].titel,
            (*bibliothek)[i].interpret,
            (*bibliothek)[i].album,
            (*bibliothek)[i].lieddauer,
            (*bibliothek)[i].erscheinungsjahr);
    }

    int num;
    printf("Wähle ein Lied aus der Liste aus, dass du löschen möchtest und gebe die Liednummer ein: ");
    scanf("%d", &num);
    getchar();

    if (num < 1 || num > *anzahl_lieder) {
        printf("\nFehler: Deine Eingabe ist falsch oder die Zahl ist zu hoch!\n");
        printf("Drücke eine Taste, um zum Menü zu gelangen.\n");
        getchar();
        return;
    }

    //Erneute abfrage
    printf("Bist du dir sicher, dass du das lied löschen willst? (j/n): ");
    char abfrage;
    scanf("%c", &abfrage);
    getchar();
    if (abfrage != 'j' && abfrage != 'J') {
        printf("Alles klar, das Lied wird nicht gelöscht.\n");
        printf("Drücke eine Taste, um zum Menü zu gelangen.\n");
        getchar();
        return;
    }

    //Löschen, indem Pointer überschrieben werden
    for (int i = num -1; i < *anzahl_lieder - 1; i++) {
        (*bibliothek)[i] = (*bibliothek)[i + 1];
    }
    (*anzahl_lieder)--;

    //Datei neu schreiben
    fp = fopen(datei, "w");
    for (int i = 0; i < *anzahl_lieder; i++) {
        fprintf(fp, "%s,%s,%s,%d,%d\n",
        (*bibliothek)[i].titel,
        (*bibliothek)[i].interpret,
        (*bibliothek)[i].album,
        (*bibliothek)[i].lieddauer,
        (*bibliothek)[i].erscheinungsjahr);
    }
    fclose(fp);

    printf("\nDas Lied wurde gelöscht.\n");
    printf("Drücke eine Taste, um zum Menü zu gelangen.\n");
    getchar();
}

// --- Bibliothek löschen ---
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder) {
    char abfrage;

    printf("\n\nAchtung! Möchtest du wirklich die Bibliothek %s und seine dazugehörigen Daten löschen? (j/n)\n\n", datei);
    scanf("%c", &abfrage);
    getchar();
    if (abfrage != 'j' && abfrage != 'J') {
        printf("Die Aktion wurde abgebrochen.\n");
        printf("Drücke eine Taste, um zum Menü zu gelangen.\n");
        getchar();
        return;
    }

    // Bibliothek löschen mit remove-Funktion aus stdio-Library
    if (remove(datei) == 0) {
        printf("Deine Bibliothek wurde soeben gelöscht.\n");
        //Speicherplatz freigeben
        free (*bibliothek);
        *bibliothek = NULL;
        *anzahl_lieder = 0;
    }

    printf("Drücke eine Taste, um zum Menü zu gelangen.\n");
    getchar();

}
