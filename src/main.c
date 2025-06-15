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

void BibliothekErstellen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder);
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder);
void MetaDatenAendern(Lied **bibliothek, int *anzahl_lieder);
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder);
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder);
void Speichern(Lied **bibliothek, int *anzahl_lieder);

// ----- Funktionsdefinitionen -----

// --- Programmstart ---
void ProgrammStart(Lied **bibliothek, int *anzahl_lieder) {
    int auswahl = 0;
    FILE *fp = NULL;

    printf("\n------Willkommen!------\n\nSoll eine bestehende Bibliothek geladen, oder eine neue Bibliothek erstellt werden?\n");
    printf("\nAchtung: Eine neue Bibliothek überschreibt die alte Bibliothek!\n");
    printf("\nDrücke 1 um eine Bibliothek zu laden und 2 um eine neue zu erstellen.\n");
    scanf("%d", &auswahl);
    getchar();

    printf("Gebe den Namen deiner Bibliothek ein:\n");
    scanf("%s", datei);
    getchar();

    if (auswahl == 1) {
        FILE *fp = fopen(datei, "r");
        if (fp == NULL) {
            printf("Deine Bibliothek konnte nicht gefunden werden.\n");
            exit(1);
        }
        fclose(fp);
        BibliothekErstellen(bibliothek, anzahl_lieder);
        printf("Deine Bibliothek wurde gefunden und geladen.\n");
    } else if (auswahl == 2) {
        FILE *fp = fopen(datei, "w");
        if (fp == NULL) {
            printf("Eine neue Bibliothek konnte nicht erstellt werden.\n");
            exit(1);
        }
        fclose(fp);
        BibliothekErstellen(bibliothek, anzahl_lieder);
        printf("Eine neue Bibliothek wurde erstellt\n.");
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
void BibliothekErstellen(Lied **bibliothek, int *anzahl_lieder) {

    //Grundstruktur und deklarationen
    int eintrag = 0;
    FILE *fp = fopen(datei, "r");


    *bibliothek = malloc (eintrag * sizeof(Lied));

    //Einlesen von Lied bis Trennzeichen (,)

    for (int i = 0; i < eintrag; i++) {
        fscanf(fp, "%[^,],%[^,],%[^,],%d,%d\n",
            (*bibliothek)[i].titel, (*bibliothek)[i].interpret, (*bibliothek)[i].album,
            &(*bibliothek)[i].erscheinungsjahr, &(*bibliothek)[i].lieddauer);
    }
    *anzahl_lieder = eintrag;
    fclose(fp);
    printf("\nDeine Bibliothek wurde erstellt!\n");
}

void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER");
}

void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER");
}
void MetaDatenAendern(Lied **bibliothek, int *anzahl_lieder) {
    printf("LEER");
}
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER");
}
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER");
}
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder) {
printf("LEER");
}
void Speichern(Lied **bibliothek, int *anzahl_lieder){
printf("LEER");
}

// ----- Mainfunktion -----

int main(void) {

    Lied *bibliothek = NULL;
    int auswahl;
    int anzahl_lieder = 0;

    ProgrammStart(&bibliothek, &anzahl_lieder);

    do{
        printf("---------------------------------\n");
        printf("Willkommen in der Musikbibliothek\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("Wähle eine Aktion aus:\n");
        printf("1. Bibliothek Erstellen\n");
        printf("2. Bibliothek Anzeigen\n");
        printf("3. Lied Hinzufügen\n");
        printf("4. Meta-Daten ändern\n");
        printf("5. Lied löschen\n");
        printf("6. Nach Lied oder Meta-Daten suchen\n");
        printf("7. Bibliothek löschen\n");
        printf("8. Aktion speichern\n");

        scanf("%d", &auswahl);
        getchar();

        switch (auswahl) {
            case 1:
                BibliothekErstellen(&bibliothek, &anzahl_lieder);
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
