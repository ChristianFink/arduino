// Wird definieren D3 als LED (als Konstante, da wir den Anschluss nicht wechseln wollen)
const int led = 3;
// Wir definieren D4 als Taster
const int taste = 4;
// Wie oft soll geblinkt werden
int blink_count = 3;

void setup()
{
    // der Pin D3 wird als Ausgang definiert
    // Wir verwenden die Variable led
    pinMode(led, OUTPUT);

    // der Pin D4 wird als Eingang definiert
    // und der Pull-Up-Widerstand wird eingeschaltet
    pinMode(taste, INPUT_PULLUP);

    // die LED wird ausgeschalten
    digitalWrite(led, LOW);
}

void loop()
{
    /*
   * Den Anschluss D4 lesen digitalRead(taste)
   * testen ob der gelesene Wert LOW (0V) ist 
   * !!! Der Pull-Up-Widerstand bewirkt, dass
   * bei nicht gedrückter Taste 5V am Eingang liegen
   * beim Drücken des Tasters geht diese Spannung auf 0V
   * Wir schliessen den Eingang praktisch kurz.
   * 
   * == vergleicht zwei Werte
   * = Speichert den Wert rechts vom = der Variablen links vom = zu
   *
   * Wenn dies zutrifft, führen wir den Code in den geschweiften Klammern aus
   * if → Falls das in runden Klammer wahr ist
   */
    if (digitalRead(taste) == LOW)
    {
        // Die Taste wurde gedrückt → Lass uns blinken!
        /*
        * Dies ist eine Zähl-Schlaufe mit Bedingung.
        * Wir definieren die Variable i und speichern den Wert 0
        * Falls i kleiner ist als der Wert in der Variable blink_count 
        * führen wir die Befehle in den geschweiften Klammern aus
        * Am Ende führen wir den Befehl i++ aus.
        * i++ ist gleichbedeutend mit i = i + 1 (einfach kürzer)
        * Es bewirkt dass zum gespeicherten Wert in i 1 addiert wird
        * Dann wird wieder überprüft of i kleiner als blink_count ist
        * Falls dies nicht mehr der Fall ist, wird die Schlaufe nicht mehr ausgeführt
        * und nach den geschweiften Klammern weiter gemacht
        */
        for (int i = 0; i < blink_count; i++)
        {
            // LED einschalten
            digitalWrite(led, HIGH);
            // ein halbe Sekunde warten
            delay(500);
            // LED ausschalten
            digitalWrite(led, LOW);
            // ein halbe Sekunde warten
            delay(500);
        }
    }
}