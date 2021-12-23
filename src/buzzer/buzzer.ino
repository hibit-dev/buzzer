// -------------------------------------------------
// Copyright (c) 2021 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#define BUZZER_PIN 9

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  tone(BUZZER_PIN, 1000); //Send 1KHz sound signal
  delay(1000);

  noTone(BUZZER_PIN); //Stop sound
  delay(1000);
}
