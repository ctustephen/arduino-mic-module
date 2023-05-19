#include <Arduino.h>

#define mic_analog_read_trigger 65

#define mic_pin A0
#define out 8

float mic_analog = 0;
bool is_trigger = 1;

void setup()
{
    Serial.begin(9600);

    Serial.println("READY");

    pinMode(mic_pin, INPUT);
    pinMode(out, OUTPUT);

    digitalWrite(out, HIGH);
}
void loop()
{
    mic_analog = analogRead(mic_pin);

    if (mic_analog >= mic_analog_read_trigger)
    {
        Serial.println("Mic trigger");
        digitalWrite(out, is_trigger);

        delay(500);

        is_trigger = !is_trigger;
    }
}