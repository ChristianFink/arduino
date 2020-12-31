const int led = 3; // Wird definieren D3 als LED
const int taste_hoch = 4; // Wir definieren D4 und D5 als Tasten (die Variabelnamen beschreiben zugleich die Funktion)
const int taste_runter = 5;

// Variable der Blinkgeschwindigkeit (Pause zwischen ein- und ausschalten in ms)
int pause = 2000;

/* Eine weiter Hilfsvariable vom Type unsigned long wird definiert
 * darin speichern wir die Anzahl an Millisekunden die seit dem einschalten vergangen sind
 * unsigned long speichert max. 4294967295ms = nicht ganz 50 Tage.
 * Nach dieser Zeit läuft die Variable über und beginnt wieder bei 0 (gut zu wissen)
 */
unsigned long lastTime = 0;
// Das gleiche für den Knopfdruck
unsigned long buttonPressed = 0;

// Zeit nach der ein weiterer Knopfdruck erkannt wird
// Verhindert dass beim Drücken direkt ans Maximum bzw. Minimum gesprungen wird
int buttonDelay = 500;

void setup()
{
    pinMode(led, OUTPUT);
    pinMode(taste_hoch, INPUT_PULLUP);
    pinMode(taste_runter, INPUT_PULLUP);
}

void loop()
{
    // die Millisikunden die seit dem Einschalten vergangen sind, werden in zeit gespeichert
    // Da wir diesen Wert nur während dieser Schlaufe benötigen, wird sie erst hier deklariert
    unsigned long zeit = millis();

    // Prüfen ob die Taste EIN gedrückt und seit dem letzten Drücken die Zeit buttonDelay vergangen ist
    if ((digitalRead(taste_hoch) == LOW) && (zeit - buttonPressed >= buttonDelay))
    {
        if (pause > 200) {
            pause -= 100;
        }
        buttonPressed = zeit;
    }
    if ((digitalRead(taste_runter) == LOW) && (zeit - buttonPressed >= buttonDelay))
    {
        if (pause < 2000) {
            pause += 100;
        }
        buttonPressed = zeit;
    }

    // Soll geblinkt werden? Sonst weiter
    if (zeit - lastTime >= pause) 
    {
        // LED Toggeln
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        // Die aktuelle Zeit in lastTime speichern
        lastTime = zeit;
    }
}