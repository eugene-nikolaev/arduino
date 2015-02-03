// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>
#include <IRremote.h>

IRsend irsend;

const int transmit_pin = 12;
const int receive_pin = 11;
const int transmit_en_pin = 3;

void setup()
{
  //Serial.begin(9600);
  // Initialise the IO and ISR
  //vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
//  vw_set_ptt_pin(transmit_en_pin);
  //vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(500);	 // Bits per sec
  vw_rx_start();       // Start the receiver PLL running
  //Serial.begin(9600);
}

  unsigned long code = 0;
//  long code2 = 0x8F807;
//  long code3 = 0xFFFFFFFF;
//  long codes[] = {code, code3, code2, code3, code, code3};
  
void loop()
{
  uint8_t buflen = 4;
  //vw_wait_rx();
  if (vw_get_message((uint8_t*) &code, &buflen)) // Non-blocking
  {
    noInterrupts();
    irsend.sendNEC(code, 32);
    interrupts();    
  }
  delay(1000);
  //{
    //for (int i = 0; i < 1; i++) {
      //long c = codes[i];
//          for (int i = 0; i < 3; i++) {
  //    delay(40);
   // }
      //delay(1000);
    //}
    //Serial.println(code, HEX);
    //delay(1000);
    //Serial.print(code, HEX);
    //Serial.println();
  //}
}

