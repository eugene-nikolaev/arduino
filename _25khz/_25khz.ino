/*
 40 KHz
 */
 
int pulseCount = 8;
int perm = 0;
float freq = 25000;
float pulseTimeMicros = (1000000.0f * pulseCount) / freq;
 
void setup() {
  startTransducer();
} 

void startTransducer()  { 
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A0) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS21);
  OCR2A = 39;
  OCR2B = 100;
}

void stopTransducer()
{
  TCCR2A = 0;
  TCCR2B = 0;
}

void loop()  { 
  startTransducer();
  if (perm != 1) {
    delayMicroseconds((int) pulseTimeMicros - 2); // wait for 400 microseconds
    stopTransducer();
    delay(1000);
  }
}
