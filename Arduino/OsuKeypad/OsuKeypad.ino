#include <Keyboard.h>

int xPin = 2;
int zPin= 3;

// Debouncing
unsigned long xHitMicros = 0;
unsigned long zHitMicros = 0;
unsigned long debounceMicros = 50000;


void setup() {
  pinMode(xPin, INPUT_PULLUP);
  pinMode(zPin, INPUT_PULLUP);
  
  Keyboard.begin();
}

void loop() {
  if (!digitalRead(xPin)){
    Keyboard.press('up_arrow');
    xHitMicros = micros();
  } else if (micros()-xHitMicros >= debounceMicros) {
    Keyboard.release('up_arrow');
  }
    
  if (!digitalRead(zPin)){
    Keyboard.press('down_arrow');
    zHitMicros = micros();
  } else if (micros()-zHitMicros >= debounceMicros) {
    Keyboard.release('down_arrow');
  }
}
