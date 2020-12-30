// Wird definieren D3 als LED
const int led = 3;
// Wir definieren D4 als Taster
const int taste = 4;
// Wie oft soll geblinkt werden
int blink_count = 3;

void setup()
{
    // der Pin D3 wird als Ausgang definiert
    pinMode(led, OUTPUT);

    // der Pin D4 wird als Eingang definiert
    // und der Pull-Up-Widerstand wird eingeschaltet
    pinMode(taste, INPUT_PULLUP);

    // die LED wird ausgeschalten
    digitalWrite(led, LOW);
}

/*
 * Wir definieren eine eigen Funktion zum blinken einer LED
 * Da wir beim Verlassen der Funktion keinen Wert zurück geben wollen, deklarieren wir sie als void
 * Falls wir einen Wert mit return zurükgebeben wollen, geben wir statt void den passenden Datentyp an
 * In der Deklaration der Funktion werden in den runden Klammern zwei Variablen deklariert (pin und anzahl).
 * Beim Aufrufen der Funktion müssen passende Werte in runden Klammern mitgegeben werden, welche während
 * der Laufzeit der Funktion in den deklarierten Variablen gespeichert werden.
 */
void blinken(int pin, int anzahl)
{
    // Wir prüfen ob die Zählervariable i kleiner als die Variable anzahl ist
    for (int i = 0; i < anzahl; i++)
    {
        // pin einschalten
        digitalWrite(pin, HIGH);
        // ein halbe Sekunde warten
        delay(500);
        // pin ausschalten
        digitalWrite(pin, LOW);
        // ein halbe Sekunde warten
        delay(500);
    }
    // Zurück von dort wo wir gekommen sind
    return;
}

void loop()
{
    if (digitalRead(taste) == LOW)
    {
        /* Taste gedrückt → Funktion blinken aufrufen
         * Wir üergeben die Werte der Variablen led und blink_count
         */
        blinken(led, blink_count);
    }
}