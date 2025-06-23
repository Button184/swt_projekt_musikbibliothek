# Musik-Bibliothek Softwaretechnik-Projekt SS2025

Das Hauptprogramm wurde in C geschrieben und dient als eine Verwaltung von Songs. Hierbei können Bibliotheken erstellt, gelöscht und mit Liedern befüllt werden, sowie auch gelöscht werden.
Es handelt sich hierbei um ein Programm ohne Interface (CLI). Das Projekt wurde stetig mit Github verwaltet und von mir durchgeführt.

_Der Aufbau sieht wie folgt aus:_

Eine main.c Datei beinhaltet den gesamten Code. Eine Einbindung externe Funktionen durch z.B. #include "library.h" war aufgrund schwerwiegender Konfigurationsprobleme seitens des PC's leider nicht möglich. Daher wurde auf "Clean-Code" geachtet, um die Lesbarkeit beizubehalten.

_Der Ablauf nach Programmstart sieht wie folgt aus:_

Zuerst erfolgt eine Abfrage, ob man eine bereits vorhandene Bibliothek einlesen möchte, die dann geladen wird und mit welcher anschließend alle Aktionen vorgenommen werden, oder man eine neue Bibliothek erstellen möchte, die dann für alle folgenden Aktionen herangezogen wird.
Anschließend kann man im Menü aus den gegebenen Aktionen auswählen, was man tun möchte. Hierbei gibt es folgende Möglichkeiten:

1. Bibliothek Anzeigen
2. Lied Hinzufügen
3. Lied löschen
4. Bibliothek löschen
5. Programm beenden

Die Auswahl der Aktion erfolgt mittels einer switch-Anweisung, womit im Anschluss die entsprechende Funktion aufgerufen wird. Danach springt das Programm zurück ins Menü, um weitere Aktionen durchzuführen.

Für Unit-Tests wurden mittels Catch2 die Funktionenen LiedLöschen, LiedHinzufügen, Bibliothek löschen geprüft. (Aufgrund des Zeitumfangs wurde Bibliothek Anzeigen ausgelassen)
