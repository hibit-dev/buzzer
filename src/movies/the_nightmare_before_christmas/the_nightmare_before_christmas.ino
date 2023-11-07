// -------------------------------------------------
// Copyright (c) 2023 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9

int melody[] = {
  NOTE_C4, NOTE_C4,
  NOTE_G4, NOTE_G4,
  NOTE_D4, NOTE_C4,
  NOTE_B4,
  NOTE_C4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_GS4, NOTE_F4, NOTE_F4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_DS4, NOTE_D4, NOTE_G4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_G4,
  NOTE_AS4, NOTE_F4, NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_AS4, NOTE_GS4,
  NOTE_B4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_CS4, NOTE_CS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_GS4,
  NOTE_FS4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_G4, NOTE_FS4,
  NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3, NOTE_GS3, NOTE_A3, NOTE_B3, NOTE_CS4,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_GS4,
  NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4,
  NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_D4, NOTE_C4,
  NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_B4, NOTE_AS4, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_GS4, NOTE_G4, NOTE_F4,
  NOTE_F4, REST, REST
};

int durations[] = {
  2, 2,
  2, 2,
  2, 2,
  1,
  2, 2,
  8, 8, 8, 8, 16, 16, 8, 4,
  16, 16, 8, 16, 16, 8, 16, 16, 8, 4,
  8, 8, 8, 16, 16, 8, 16, 16, 4,
  8, 8, 16, 16, 8, 8, 8, 8, 8,
  8, 8, 16, 16, 8, 8, 8, 16, 16, 8,
  8, 8, 8, 16, 16, 8, 8, 4,
  8, 8, 16, 16, 8, 16, 16, 16, 16, 16, 16, 8,
  8, 8, 8, 16, 16, 16, 16, 16, 16, 16, 16, 8,
  8, 8, 4, 16, 16, 16, 16, 8, 8,
  8, 8, 8, 8, 8, 16, 16, 4,
  8, 16, 16, 8, 16, 16, 16, 16, 8, 4,
  8, 8, 8, 8, 8, 16, 16, 4,
  8, 16, 16, 8, 16, 16, 16, 16, 8, 4,
  16, 16, 8, 8, 8, 16, 16, 16, 16, 4,
  8, 8, 16, 16, 8, 8, 8, 16, 16, 8,
  16, 16, 8, 16, 16, 8, 16, 16, 8, 16, 16, 8,
  4, 4, 2
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
