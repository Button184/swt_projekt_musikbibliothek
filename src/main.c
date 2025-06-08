#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LAENGE 50

typedef struct {
    char titel [MAX_LAENGE];
    char interpret [MAX_LAENGE];
    char album [MAX_LAENGE];
    int lieddauer;
    int erscheinungsjahr;
} Lied;

void BibliothekErstellen(Lied **bibliothek, int *anzahl_lieder);
void BibliothekAnzeigen();
void LiedHinzufuegen();
void MetaDatenAendern();
void LiedLoeschen();
void MetaDatenSuchen();
void BibliothekLoeschen();
void Speichern();

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
                BibliothekenAnzeigen(&bibliothek, &anzahl_lieder);
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

char datei[MAX_LAENGE];

void BibltiothekErstellen(Lied **bibliothek, int *anzahl_lieder) {
    //Grundstruktur und deklarationen
    int eintrag = 0;
    char a = 0;
    FILE *fp = NULL;
    fp = fopen(datei, "r");
    //Einlesen
    while (( a = (char) fgetc (fp)) != EOF) {
        if ( a == '\n') {
            eintrag++;
        }
    }
    rewind(fp);
    bibliothek = (Lied*) malloc((unsigned long) eintrag * sizeof(Lied));
}
