//#############################################################################################################
//This code only works on an Arduino with the ATmega32U4 chip, so only Arduino Leonardo and Arduino Pro Micro!!
//#############################################################################################################
 
 
#include <Keyboard.h>    // This is a "built-in" library no need to install
 
#include "Keyboard.h"
 
#define PEDAL1_KEY   '5'   //Change this to define which key to send for each pedal
#define PEDAL2_KEY   '6'
#define PEDAL3_KEY   '7'
#define PEDAL4_KEY   '8'
#define PEDAL5_KEY   '9'
 
 
 
 
 
#define PEDAL1_PIN   3    //define input pins for the switches
#define PEDAL2_PIN   4
#define PEDAL3_PIN   5
#define PEDAL4_PIN   6
#define PEDAL5_PIN   7
 
// Works on the Leonardo board only to simulate 
// a HID keyboard over USB
 
 
void setup(void)
{
 
 pinMode(2,INPUT_PULLUP);   //Pin 2 is used as a failsafe, connect it to GND!
delay(100);
 
  
    // Set pin to input
    pinMode(PEDAL1_PIN, INPUT);
    // Enable pullup resistor
    digitalWrite(PEDAL1_PIN, HIGH);
 
    // Set pin to input
    pinMode(PEDAL2_PIN, INPUT);
    // Enable pullup resistor
    digitalWrite(PEDAL2_PIN, HIGH);
    
        // Set pin to input
    pinMode(PEDAL3_PIN, INPUT);
    // Enable pullup resistor
    digitalWrite(PEDAL3_PIN, HIGH);
 
    // Set pin to input
    pinMode(PEDAL4_PIN, INPUT);
    // Enable pullup resistor
    digitalWrite(PEDAL4_PIN, HIGH);
    
        // Set pin to input
    pinMode(PEDAL5_PIN, INPUT);
    // Enable pullup resistor
    digitalWrite(PEDAL5_PIN, HIGH);
 
 
delay(100);
 
 
    if (digitalRead(2) == 0)   //Failsafe 
  {
  Keyboard.begin();
  }
  else {
    delay(20000);
  }
 
 
 
  }
 
 
 
 
void loop(void)
{
    static uint8_t pedal1StateLast = 0;
    static uint8_t pedal2StateLast = 0;
    static uint8_t pedal3StateLast = 0;
    static uint8_t pedal4StateLast = 0;
    static uint8_t pedal5StateLast = 0;
 
    uint8_t pedalState1;
    uint8_t pedalState2;
    uint8_t pedalState3;
    uint8_t pedalState4;
    uint8_t pedalState5;
 
    
    pedalState1 = digitalRead(PEDAL1_PIN);
    if (pedalState1 != pedal1StateLast) {
        pedal1StateLast = pedalState1;
 
        if (pedalState1 == 0) {
             Keyboard.press(PEDAL1_KEY);
            delay(10);
            }
            else
            {
            Keyboard.release(PEDAL1_KEY);
            }
        
    }
 
    pedalState2 = digitalRead(PEDAL2_PIN);
    if (pedalState2 != pedal2StateLast) {
        pedal2StateLast = pedalState2;
 
        if (pedalState2 == 0) {
            Keyboard.press(PEDAL2_KEY);
            delay(10);
        }
 
        else
            {
            Keyboard.release(PEDAL2_KEY);
            }
    }
 
 
 pedalState3 = digitalRead(PEDAL3_PIN);
    if (pedalState3 != pedal3StateLast) {
        pedal3StateLast = pedalState3;
 
        if (pedalState3 == 0) {
            Keyboard.press(PEDAL3_KEY);
            delay(10);
        }
 
        else
            {
            Keyboard.release(PEDAL3_KEY);
            }
    }
 
 
     pedalState4 = digitalRead(PEDAL4_PIN);
    if (pedalState4 != pedal4StateLast) {
        pedal4StateLast = pedalState4;
 
        if (pedalState4 == 0) {
            Keyboard.press(PEDAL4_KEY);
            delay(10);
        }
 
        else
            {
            Keyboard.release(PEDAL4_KEY);
            }
    }
 
 
     pedalState5 = digitalRead(PEDAL5_PIN);
    if (pedalState5 != pedal5StateLast) {
        pedal5StateLast = pedalState5;
 
        if (pedalState5 == 0) {
            Keyboard.press(PEDAL5_KEY);
            delay(10);
        }
 
        else
            {
            Keyboard.release(PEDAL5_KEY);
            }
    }
 
 
    delay(50);
}
