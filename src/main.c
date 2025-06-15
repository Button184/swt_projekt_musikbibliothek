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
        printf("Gebe den Namen deiner Bibliothek ein (mit .csv-Endung!):\n");
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
        printf("Gebe deiner Bibliothek einen Namen (mit .csv-Endung!): ");
        scanf("%s", name);
        snprintf(datei, MAX_LAENGE, "%s.csv",name); // KI-Hilfe
        BibliothekErstellen();
    } else {
        printf("Eingabe ungültig\n");
        exit(1);
    }


    printf("Gebe einen Namen für die Bibilothek ein: \n");
    scanf("%s", datei);
    fp = fopen(datei, "w");
    fclose(fp);
}

// --- BibliothekErstellen ---
void BibliothekErstellen(void) {
    FILE *fp = fopen(datei, "r");

    // Falls eine Bibliothek bereits existiert
    if (fp != NULL) {
        int eintrag = 0;
        int ch;

        // Einlesen der Bibliothek zeichen für zeichen bis zu Zeilensprung "\n"
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '\n') {
                eintrag++;
            }
        }
        rewind(fp);

        *bibliothek = malloc (eintrag * sizeof(Lied));

    //Einlesen von Lied bis Trennzeichen (,)

        for (int i = 0; i < eintrag; i++) {
            fscanf(fp, "%[^,],%[^,],%[^,],%d,%d\n",
                (*bibliothek)[i].titel, (*bibliothek)[i].interpret, (*bibliothek)[i].album,
                &(*bibliothek)[i].erscheinungsjahr, &(*bibliothek)[i].lieddauer);
        }
        *anzahl_lieder = eintrag;
        fclose(fp);
        printf("\nDeine Bibliothek geladen!\n");
    } else { // Falls noch keine Bibliothek besteht
        fp = fopen(datei, "w");
        if (fp == NULL) {
            printf("Error bei Dateierstellung.\n");
            exit(1);
        }
        int x;
        printf("");
    }
}

void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER\n");
}

void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER\n");
}
void MetaDatenAendern(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER\n");
}
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER\n");
}
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
        printf("\n1. Bibliothek Erstellen\n");
        printf("2. Bibliothek Anzeigen\n");
        printf("3. Lied Hinzufügen\n");
        printf("4. Meta-Daten ändern\n");
        printf("5. Lied löschen\n");
        printf("6. Nach Lied oder Meta-Daten suchen\n");
        printf("7. Bibliothek löschen\n");
        printf("8. Aktion speichern\n");
        printf("\nAktion: ");

        scanf("%d", &auswahl);
        getchar();

        switch (auswahl) {
            case 1:
                printf("LEER 'WIP'");
                break;
            case 2:
                BibliothekAnzeigen(&bibliothek, &anzahl_lieder);
                break;
            case 3:
                LiedHinzufuegen(&bibliothek, &anzahl_lieder);
                break;
            case 4:
                MetaDatenAendern(&bibliothek, &anzahl_lieder);
                break;
            case 5:
                LiedLoeschen(&bibliothek, &anzahl_lieder);
                break;
            case 6:
                MetaDatenSuchen(&bibliothek, &anzahl_lieder);
                break;
            case 7:
                BibliothekLoeschen(&bibliothek, &anzahl_lieder);
                break;
            case 8:
                Speichern(&bibliothek, &anzahl_lieder);
                break;
            default:
                printf("FEHLER: Eingabe ist ungültig!\n");
        }
    } while (auswahl != 0);
    free(bibliothek);
    return 0;
}
