int led_1 = 3; // Wird definieren D3 und D7 als LEDs
int led_2 = 7;
int taste_1 = 4; // Wir definieren D4, D5 und D6 als Taster
int taste_2 = 5;
int taste_3 = 6;

void setup()
{
    pinMode(led_1, OUTPUT); // die Pins D3 und D7 werden als Ausgang definiert
    pinMode(led_2, OUTPUT);

    // die Pins D4, D5 und D6 werden als Eingänge mit Pull-Up definiert
    pinMode(taste_1, INPUT_PULLUP);
    pinMode(taste_2, INPUT_PULLUP);
    pinMode(taste_3, INPUT_PULLUP);

    digitalWrite(led_1, LOW); // die LEDs werden ausgeschalten
    digitalWrite(led_2, LOW);
}

// Die Blinken Funktion (Beschreibung im Beispiel 2)
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
    if (digitalRead(taste_1) == LOW)
    {
        // Taste 1 gedrückt → LED 1: 3x blinken
        blinken(led_1, 3);
    }
    else if (digitalRead(taste_2) == LOW)
    {
        // Taste 2 gedrückt → LED 1: 5x blinken
        blinken(led_1, 5);
    }
    else if (digitalRead(taste_3) == LOW)
    {
        // Taste 3 gedrückt → LED 2: 3x blinken
        blinken(led_2, 3);
    }
}