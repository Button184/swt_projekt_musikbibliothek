#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LAENGE 50

// --- Struct Lied ---
typedef struct {
    char titel [MAX_LAENGE];
    char interpret [MAX_LAENGE];
    char album [MAX_LAENGE];
    int lieddauer;
    int erscheinungsjahr;
} Lied;

// ----- Globale Variablen -----
char datei[MAX_LAENGE];

// ----- Funktionsdeklarationen -----

void BibliothekErstellen();
void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder);
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder);
void MetaDatenAendern(Lied **bibliothek, int *anzahl_lieder);
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder);
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder);
void Speichern(Lied **bibliothek, int *anzahl_lieder);

// ----- Funktionsdefinitionen -----

// --- Programmstart ---
void ProgrammStart(void) {
    int auswahl = 0;
    FILE *fp = NULL;
    char name[MAX_LAENGE]; // KI-Hilfe

    printf("\n------Willkommen!------\n");
    printf("\nSoll eine bestehende Bibliothek geladen, oder eine neue Bibliothek erstellt werden?\n");
    printf("\nAchtung: Eine neue Bibliothek überschreibt die alte Bibliothek!\n");
    printf("\n Bibliothek laden: (1)\nNeue Bibliothek erstellen: (2)\n");
    scanf("%d", &auswahl);
    getchar();

    if (auswahl == 1) {
        printf("Gebe den Namen deiner Bibliothek ein (ohne .csv-Endung!):\n");
        scanf("%s", name); // KI-Hilfe
        snprintf(datei, MAX_LAENGE, "%s.csv", name); // KI-Hilfe

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
        snprintf(datei, MAX_LAENGE, "%s.csv",name); // KI-Hilfe
        BibliothekErstellen();
    } else {
        printf("Eingabe ungültig\n");
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
void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER\n");

    /*

    //Einlesen von Lied bis Trennzeichen (,)

        for (int i = 0; i < eintrag; i++) {
            fscanf(fp, "%[^,],%[^,],%[^,],%d,%d\n",
                (*bibliothek)[i].titel, (*bibliothek)[i].interpret, (*bibliothek)[i].album,
                &(*bibliothek)[i].erscheinungsjahr, &(*bibliothek)[i].lieddauer);
    */
}

// --- Lied Hinzufügen ---
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder) {

    *bibliothek = realloc(*bibliothek, (*anzahl_lieder + 1) * sizeof(Lied));
    Lied *lied = &(*bibliothek) [*anzahl_lieder];

    printf("\n Füge ein neues Lied hinzu:\n");

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
        (*bibliothek)[*anzahl_lieder].titel, (*bibliothek)[*anzahl_lieder].interpret,
        (*bibliothek)[*anzahl_lieder].album, (*bibliothek)[*anzahl_lieder].lieddauer,
        (*bibliothek)[*anzahl_lieder].erscheinungsjahr );

    fclose(fp);
    printf("\nDein Lied wurde hinzugefügt!\n");

    (*anzahl_lieder)++;
}

// --- Meta-Daten ändern ---
void MetaDatenAendern(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER\n");
}

// --- Lied löschen ---
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}

// --- Meta-Daten suchen ---
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}

// --- Bibliothek löschen ---
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}

// --- Aktion speichern ---
void Speichern(Lied **bibliothek, int *anzahl_lieder){
printf("LEER\n");
}

// ----- Mainfunktion -----

int main(void) {

    Lied *bibliothek = NULL;
    int auswahl;
    int anzahl_lieder = 0;

    ProgrammStart();

    do{
        printf("\n---------------------------------\n");
        printf("Willkommen in der Musikbibliothek\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("Wähle eine Aktion aus:\n");
        printf("1. Bibliothek Anzeigen\n");
        printf("2. Lied Hinzufügen\n");
        printf("3. Meta-Daten ändern\n");
        printf("4. Lied löschen\n");
        printf("5. Nach Lied oder Meta-Daten suchen\n");
        printf("6. Bibliothek löschen\n");
        printf("7. Aktion speichern\n");
        printf("8. Programm beenden\n");
        printf("\nAktion: ");

        scanf("%d", &auswahl);
        getchar();

        switch (auswahl) {
            case 1:
                BibliothekAnzeigen(&bibliothek, &anzahl_lieder);
                break;
            case 2:
                LiedHinzufuegen(&bibliothek, &anzahl_lieder);
                break;
            case 3:
                MetaDatenAendern(&bibliothek, &anzahl_lieder);
                break;
            case 4:
                LiedLoeschen(&bibliothek, &anzahl_lieder);
                break;
            case 5:
                MetaDatenSuchen(&bibliothek, &anzahl_lieder);
                break;
            case 6:
                BibliothekLoeschen(&bibliothek, &anzahl_lieder);
                break;
            case 7:
                Speichern(&bibliothek, &anzahl_lieder);
                break;
            case 8:
                printf("\nAuf Wiedersehen!");
                exit(1);
            default:
                printf("FEHLER: Eingabe ist ungültig!\n");
        }
    } while (auswahl != 0);
    free(bibliothek);
    return 0;
}
