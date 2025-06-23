#define CATCH_CONFIG_MAIN
#include "catch.hpp"
extern "C" {
    #include "C:/Users/Admin/Desktop/Code/swt_projekt/SWT_PROJEKT_MUSIKBIBLIOTHEK/src/test_main.c"
}

TEST_CASE("Ein Lied wird korrekt hinzugefügt", "[LiedHinzufuegen]") {

    strcpy(datei, "test_liederstellung.csv");
    remove(datei);

    Lied *bibliothek = NULL;
    int anzahl_lieder = 0;

    // Testinhalte
    Lied testlied;
    strcpy(testlied.titel, "Test123");
    strcpy(testlied.interpret, "MC Test");
    strcpy(testlied.album, "Biggest Tests");
    testlied.lieddauer = 1807;
    testlied.erscheinungsjahr = 2021;

    // Cast zu Lied* für C++ kompiler
    bibliothek = (Lied*) realloc(bibliothek, sizeof(Lied));
    bibliothek[0] = testlied;
    anzahl_lieder++;

    FILE* fp = fopen(datei, "a");
    REQUIRE(fp != NULL);
    fprintf(fp, "%s,%s,%s,%d,%d\n",
        testlied.titel,
        testlied.interpret,
        testlied.album,
        testlied.lieddauer,
        testlied.erscheinungsjahr);
    fclose(fp);

    //Prüfen, ob Lied da ist
    fp = fopen(datei, "r");
    REQUIRE(fp != NULL);

    Lied vorhanden;
    REQUIRE(fscanf(fp, "%[^,],%[^,],%[^,],%d,%d\n",
        vorhanden.titel,
        vorhanden.interpret,
        vorhanden.album,
        &vorhanden.lieddauer,
        &vorhanden.erscheinungsjahr) == 5);

    CHECK(strcmp(vorhanden.titel, testlied.titel) == 0);
    CHECK(strcmp(vorhanden.interpret, testlied.interpret) == 0);
    CHECK(strcmp(vorhanden.album, testlied.album) == 0);
    CHECK(vorhanden.lieddauer == testlied.lieddauer);
    CHECK(vorhanden.erscheinungsjahr == testlied.erscheinungsjahr);

    fclose(fp);
    remove(datei);
}


TEST_CASE("Ein Lied wird korrekt entfernt", "[LiedLoeschen]") {

    Lied *bibliothek = NULL;
    int anzahl_lieder = 0;

    anzahl_lieder = 2;
    bibliothek = (Lied*) malloc(sizeof(Lied) *anzahl_lieder); // KI-Hilfe

    strcpy(bibliothek[0].titel, "tesetTitel1");
    strcpy(bibliothek[1].titel, "testTitel2");
    LiedLoeschen(&bibliothek, &anzahl_lieder);

    //Eingabe simulieren
    FILE *temp = tmpfile();
    fputs("1", temp);
    rewind(temp);
    stdin = temp;

    CHECK(strcmp(bibliothek[0].titel, "testTitel2") == 0);

    free(bibliothek);
}


TEST_CASE("Eine Bibliothek wird korrekt entfernt", "[BibliothekLoeschen]") {
    int anzahl_bib = 2;
    Lied *bibliothek = (Lied*) malloc(sizeof(Lied) *anzahl_bib);

    strcpy(bibliothek[0].titel, "Bib1");
    strcpy(bibliothek[1].titel, "Bib2");

    //Eingabe simulieren
    FILE *temp = tmpfile();
    fputs("j", temp);
    rewind(temp);
    stdin = temp;

    BibliothekLoeschen(&bibliothek, &anzahl_bib);

    CHECK(anzahl_bib == 0);
}
