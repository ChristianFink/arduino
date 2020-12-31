// Einbinden der Bibliothek für alle DHT-Sensoren
#include "DHT.h"

// Definieren an welchem Anschluss der Sensorausgang angeschlossen ist.
const int DHTPIN = 2;

// Wir definieren unseren Sensor und geben ihm einen Namen
// wir nennen ihn dht1
// Der Sensor ist vom Datentyp DHT er wurde neu in der Bibliothek definiert
// In den Klammern wird der Data-Pin des Sensors und der Sensortyp angegeben
// Für den DHT22 oder AM2302 schreiben wir: DHT22
// Für den DHT21 oder AM2301 schreiben wir: DHT21
DHT dht1 = DHT(DHTPIN, DHT11);

void setup()
{
    // Wir initialisieren die Serielle Schnittstelle unseres Arduinos
    // Zusätzlich stellen wir eine Geschwindigkeit von 9600 ein.
    Serial.begin(9600);
    // Wir schreiben eine Zeile an die Serielle Schnittstelle. "DHTxx test!"
    Serial.println(F("DHTxx test!"));

    // Wir starten unseren Sensor
    // Den richtigen Namen angeben!
    dht1.begin();
}

void loop()
{
    // Als erstes warten wir 2 Sekunden odere 2000 Millisekunden
    delay(2000);

    // Wir lesen die Luftfeuchtigkeit aus dem Sensor aus und speicher sie in der Variable h
    float h = dht1.readHumidity();

    // Wir lesen die Temperatur aus dem Sensor aus und speichern sie in der Variablen t
    float t = dht1.readTemperature();

    // Falls der Sensor keinen Wert liefert, wird keine Nummer gespeichert.
    // Dies müssen wir mit der Funktion isnan() überprüfen.
    // Falls h keine Nummer ist oder (||) t keine Nummer ist: Befehle in {} ausführen
    if (isnan(h) || isnan(t))
    {
        // Fehlermeldung über die Serielle Schnittstelle ausgeben
        Serial.println(F("Fehler beim auslesen des Sensors!"));
        // Wir verlassen die Funktion loop und starten wieder am Anfang bei: void loop() {
        return;
    }

    // Wenn alles richtig gelesen wurde geht es hier weiter
    // Wir geben die Werte über die Serielle Schnittstelle aus:

    Serial.print(F("Luftfeuchtigkeit: "));
    Serial.print(h);
    Serial.print(F("% Temperatur: "));
    Serial.print(t);
    Serial.println(F("°C"));

    // Wir können natürlich auch Berechnungen damit anstellen
    // Zum Beispiel den Hitzeindex berechnen.
    // Da die Funktion computeHeatIndex die Temperatur in Farenheit erwartet, muss der letzte Wert false sein
    float hitzeindex = dht1.computeHeatIndex(t, h, false);

    Serial.print(F("Hitzeindex : "));
    Serial.print(hitzeindex);
    Serial.println(F("°C"));

    // Man könnte natürlich auch Maximal und Minimalwerte in eine Variable Speichern
    // Den Durchschnitt über mehrere Werte berechnen
    // Beim erreichen einer Temperatur eine LED oder Relais schalten (Thermostat)
}