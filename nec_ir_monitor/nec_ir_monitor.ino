// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $
//#include <VirtualWire.h>
#define DEBUG true
#include <IRremote.h>
#include <LiquidCrystal.h>
#define DEBUG true

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(10, 9, 5, 4, 3, 2);


void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn(); // Start the receiver
      // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    lcd.print("hello, world!");
    // Initialise the IO andd ISR
//    vw_set_tx_pin(transmit_pin);
//    vw_set_rx_pin(receive_pin);
//    vw_set_ptt_pin(transmit_en_pin);
//    vw_set_ptt_inverted(true); // Required for DR3100
//    vw_setup(500);       // Bits per sec
}

long code;
long prevCode = 0;

void loop()
{
  if (irrecv.decode(&results)) {
    prevCode = code;
    code = results.value;
    Serial.println(code, HEX);
//    code = 0x7F806;
     lcd.clear();
     lcd.print(code, 16);
     lcd.setCursor(0, 1);
     lcd.print(prevCode, 16);
//    vw_send((uint8_t *) &code, 4);
//    vw_wait_tx(); // Wait until the whole message is gone
//    delay(1000);
     irrecv.resume();
  }
  delay(100);
}
