// -------------------------------------------------
// Copyright (c) 2026 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_B4, NOTE_E4, NOTE_G4, REST, NOTE_E4, REST,
  NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, REST,

  NOTE_G4, REST,
  NOTE_G4, NOTE_G4, REST,
  NOTE_G4, REST,
  NOTE_G4, NOTE_D4, NOTE_G4, REST, NOTE_G4, REST, 

  NOTE_C4, REST, NOTE_D4, REST, NOTE_E4, REST, NOTE_G4, REST,
  NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_E4, REST, NOTE_E4, REST, NOTE_E4, REST,
  REST
};

int durations[] = {
  4, 6, 6, 8, 6, 6,
  4, 6, 4, 3, 4,

  6, 8,
  6, 6, 8,
  6, 8,
  4, 6, 4, 16, 2, 8,
  
  4, 6, 4, 6, 4, 6, 4, 8,
  6, 6, 6,
  6, 3, 6, 3, 6, 3,
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
