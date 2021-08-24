const int outputPin = 13;

void setup()
{
    pinMode(outputPin, OUTPUT);
}

void S()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(outputPin, HIGH);
        delay(500);
        digitalWrite(outputPin, LOW);
        delay(300);
    }
}

void O()
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(outputPin, HIGH);
        delay(1500);
        digitalWrite(outputPin, LOW);
        delay(300);
    }
}

void loop()
{
    S();
    O();
    S();
    delay(300);
}