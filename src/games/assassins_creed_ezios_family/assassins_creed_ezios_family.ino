// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_F4,
  NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5,
  
  NOTE_A5, NOTE_A5, NOTE_D6,
  NOTE_A5, NOTE_A5, NOTE_AS5,
  NOTE_A5, NOTE_G5, NOTE_A5,
  NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5, NOTE_E5,
  
  NOTE_A5, NOTE_AS5, NOTE_A5,
  NOTE_A5, NOTE_D6, NOTE_A5,
  NOTE_AS5, NOTE_F6, NOTE_D6,
  NOTE_D6, NOTE_A5, NOTE_F5, NOTE_E5,
  
  NOTE_D4,
};

int durations[] = {
  3, 3, 3, 3,
  3, 3, 3, 3,
  3, 3, 3, 3,
  3, 3, 3, 3,

  2, 4, 2,
  2, 3, 2,
  2, 3, 2,
  2, 2, 6, 6, 2,

  3, 2, 2,
  3, 2, 2,
  3, 2, 2,
  3, 3, 6, 6,
  
  1
};

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}
