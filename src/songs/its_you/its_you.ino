// -------------------------------------------------
// Copyright (c) 2024 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_D5, NOTE_B5, NOTE_A5, NOTE_A5, NOTE_FS5, NOTE_D4, NOTE_FS5, NOTE_D4, NOTE_D4,
  NOTE_A5, NOTE_FS5, REST,
  NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_FS5, REST,
  NOTE_B4, NOTE_D5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, REST,
  NOTE_A5, NOTE_FS5, NOTE_FS5, REST,
  NOTE_FS5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_FS5, NOTE_FS5, REST,
  NOTE_B4, NOTE_D5, NOTE_FS5, NOTE_D5, REST,

  NOTE_D5,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_A5, REST,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_B5, NOTE_A5, REST,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_E5, NOTE_D5, REST,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_A5, NOTE_A5, REST,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_B5, NOTE_A5, REST,
  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_E5, REST,

  REST
};

int durations[] = {
  2, 4, 2, 4, 2, 4, 2, 1, 1,
  4, 1, 2,
  4, 4, 4, 2, 4, 4, 1, 2,
  8, 4, 4, 8, 4, 4, 2,
  4, 4, 1, 4,
  4, 4, 4, 2, 4, 4, 1, 2,
  8, 4, 2, 2, 2,

  8,
  8, 8, 8, 4, 4, 8, 2, 4,
  8, 8, 8, 8, 4, 4, 2, 4,
  8, 8, 8, 4, 4, 8, 2, 2, 4,
  8, 8, 8, 8, 4, 4, 2, 4,
  8, 8, 8, 8, 4, 4, 2, 4,
  8, 8, 8, 8, 4, 8, 2, 2,

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
