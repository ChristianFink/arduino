const int led = 3; // Wird definieren D3 als LED
const int taste_ein = 4; // Wir definieren D4 und D5 als Tasten (die Variabelnamen beschreiben zugleich die Funktion)
const int taste_aus = 5;

// Es wird eine Hilfsvariable deklariert die speichert, ob geblinkt werden soll oder nicht
// Eine bool-Variable mit den Werten Wahr oder Falsch ist da genau richtig
bool status_blinken = false;

/* Eine weiter Hilfsvariable vom Type unsigned long wird definiert
 * darin speichern wir die Anzahl an Millisekunden die seit dem einschalten vergangen sind
 * unsigned long speichert max. 4294967295ms = nicht ganz 50 Tage.
 * Nach dieser Zeit läuft die Variable über und beginnt wieder bei 0 (gut zu wissen)
 */
unsigned long lastTime = 0;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(taste_ein, INPUT_PULLUP);
    pinMode(taste_ein, INPUT_PULLUP);
}

void loop()
{
    // die Millisikunden die seit dem Einschalten vergangen sind, werden in zeit gespeichert
    // Da wir diesen Wert nur während dieser Schlaufe benötigen, wird sie erst hier deklariert
    unsigned long zeit = millis();

    /* Prüfen ob die Taste EIN gedrückt wird UND der Bilnkstatus Falsch ist
     * Das ! vor einer bool-Variablen invertiert diese.
     * Es würde ausreichen nur den Tastendruck zu prüfen. Wenn die Taste
     * aber festgehalten wird, wird die Funktion wieder und wieder ausgeführt
     */
    if ((digitalRead(taste_ein) == LOW) && !status_blinken)
    {
        // die Variable status_blinken wird auf wahr gesetzt
        status_blinken = true;
    }
    // Wie oben aber anders herum
    if ((digitalRead(taste_aus) == LOW) && status_blinken)
    {
        status_blinken = false;
        // Die LED soll auf jeden Fall noch ausgeschaltet werden
        digitalWrite(led, LOW);
    }

    // Soll geblinkt werden? Sonst weiter
    if (status_blinken)
    {
        if (zeit - lastTime >= 500) 
        {
            /* 
             * Wir prüfen ob der Wert der Variable lastTime >= 500 ist 
             * WICHTIG! Niemals dem Wert der Zeit (millis) mit == vergleichen
             * Dass die Zeit auf die millisekunde genau ist tritt nie ein.
             * Darum immer >= oder <= verwenden
             * zeit >= lastTime + 500
             * würde in den meisten Fällen auch funktionieren.
             * Vor einem Zeitüberlauf wäre aber z.B. lastTime = 4294967290
             * Nach dem Überlauf ist Zeit z.B 600
             * Dann ergibt 600 >= 4294967290 + 500 → FALSCH
             * 
             * 600 - 4294967290 >= 500 → WAHR
             * 
             */
            // LED Toggeln
            digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
            // Die aktuelle Zeit in lastTime speichern
            lastTime = zeit;
        }
    }
}