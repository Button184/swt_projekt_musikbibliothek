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

            default:
                printf("FEHLER: Eingabe ist ungültig!\n");
        }
    while (auswahl != 2); // SPÄTER ANPASSEN !!
    free(bibliothek)

    return 0;
}
