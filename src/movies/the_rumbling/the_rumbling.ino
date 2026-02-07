// -------------------------------------------------
// Copyright (c) 2026 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_B3,
  NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_C4, NOTE_D4, REST, NOTE_D4, NOTE_DS4, REST,

  NOTE_G3, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_F4,
  NOTE_DS4, NOTE_D4, REST,

  NOTE_CS5, NOTE_C5, NOTE_G5, NOTE_CS5, REST,
  NOTE_C5, NOTE_G5, NOTE_CS5, REST,
  NOTE_AS4,
  REST,
};

int durations[] = {
  2,
  6, 6, 6, 6, 6, 6, 6, 3,
  6, 4, 16, 3, 3, 8,

  6, 6, 6, 6, 6, 6, 3,
  6, 2, 4,

  4, 4, 4, 2, 6,
  3, 4, 2, 6,
  1,
  2
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
