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

// ----- Funktionsdeklarationen -----

void BibliothekErstellen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekAnzeigen(Lied **bibliothek, int *anzahl_lieder);
void LiedHinzufuegen(Lied **bibliothek, int *anzahl_lieder);
void endern(Lied **bibliothek, int *anzahl_lieder);
void LiedLoeschen(Lied **bibliothek, int *anzahl_lieder);
void MetaDatenSuchen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekLoeschen(Lied **bibliothek, int *anzahl_lieder);
void Speichern(Lied **bibliothek, int *anzahl_lieder);


// --MetaDatenA--- Funkttionsdefinitionen -----

char datei[MAX_LAENGE];

// --- Programmstart ---

void ProgrammStart(void) {
    int auswahl = 0;
    FILE *fp = NULL;

    printf("Gebe einen Namen für die Bibilothek ein: \n");
    scanf("%s", datei);
    fp = fopen(datei, "w");
    fclose(fp);
}

// --- BibliothekErstellen ---
void BibliothekErstellen(Lied **bibliothek, int *anzahl_lieder) {

    //Grundstruktur und deklarationen
    int eintrag = 0;
    int ch;
    FILE *fp = fopen(datei, "r");

    //Einlesen
    while (( ch = fgetc(fp)) != EOF ) {
        if ( ch == '\n') {
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

    do{
        printf("---------------------------------\n");
        printf("Willkommen in der Musikbibliothek\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("Wähle eine Aktion aus:\n");
        // Aktionen einbauen !!

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
    } while (auswahl != 8);
    free(bibliothek);
    return 0;
}
