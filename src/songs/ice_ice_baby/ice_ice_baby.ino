// -------------------------------------------------
// Copyright (c) 2025 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_A2, REST,
  NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_A2, REST,
  NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, REST, NOTE_D3, NOTE_D3, NOTE_D3, NOTE_A2, REST,
  NOTE_D3,
  NOTE_D4, REST, NOTE_D4, NOTE_D4, REST,
  NOTE_E3, NOTE_D3, NOTE_F3, REST, NOTE_F3,
  NOTE_D4, REST, NOTE_D4, NOTE_D4, REST,
  NOTE_D3,
  NOTE_D4, REST, NOTE_D4, NOTE_D4, REST,
  NOTE_E3, NOTE_D3, NOTE_F3, REST, NOTE_F3,
  NOTE_D4,
  REST
};

int durations[] = {
  8, 16, 8, 16, 8, 16, 10, 10, 10, 3, 2,
  8, 16, 8, 16, 8, 16, 10, 10, 10, 3, 2,
  8, 16, 8, 16, 8, 16, 10, 10, 10, 3, 2,
  4,
  4, 3, 4, 4, 3,
  6, 6, 6, 33, 6,
  4, 3, 4, 4, 3,
  4,
  4, 3, 4, 4, 3,
  6, 6, 6, 33, 6,
  3,
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
