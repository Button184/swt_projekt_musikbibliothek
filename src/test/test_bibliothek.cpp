#define CATCH_CONFIG_MAIN
#include "catch.hpp"
extern "C" {
    #include "C:/Users/Admin/Desktop/Code/swt_projekt/SWT_PROJEKT_MUSIKBIBLIOTHEK/src/test_main.c"
}

TEST_CASE("Ein Lied wird korrekt hinzugefügt", "[LiedHinzufuegen]") {
    strcpy(datei, "test_liederstellung.csv");
    remove(datei);

}
