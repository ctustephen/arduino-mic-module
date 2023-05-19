#include <Arduino.h>

#define mic_pin A0
#define out 8

bool mic_state = 0, mic_oldstate = 0;
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
    mic_state = digitalRead(mic_pin);

    if (mic_state == LOW && mic_state != mic_oldstate)
    {
        Serial.println("Mic trigger");
        digitalWrite(out, is_trigger);

        delay(500);

        is_trigger = !is_trigger;
    }
    mic_oldstate = mic_state;
}