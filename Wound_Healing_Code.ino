/******************************************************************************
ISL29125_basics.ino
Simple example for using the ISL29125 RGB sensor library.
Jordan McConnell @ SparkFun Electronics
11 Apr 2014
https://github.com/sparkfun/ISL29125_Breakout

This example declares an SFE_ISL29125 object called RGB_sensor. The 
object/sensor is initialized with a basic configuration so that it continuously
samples the light intensity of red, green and blue spectrums. These values are
read from the sensor every 10 milliseconds and printed to the Serial monitor.

In addition, this program provides toggle functionality to the UV LEDs

Together, this program should allow us to measure the fluoresence (that's
probably spelled wrong) from a surface such as an infected wound.

Developed/Tested with:
Arduino Uno
Arduino IDE 1.0.5

Requires:
SFE_ISL29125_Library

This code is beerware.
Distributed as-is; no warranty is given. 
******************************************************************************/

#include <Wire.h>
#include "SFE_ISL29125.h"

// Declare sensor object
SFE_ISL29125 RGB_sensor;

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int ledLite = 0; 

void setup()
{
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize the ISL29125 with simple configuration so it starts sampling
  if (RGB_sensor.init())
  {
    Serial.println("Sensor Initialization Successful\n\r");
  }
   // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

// Read sensor values for each color and print them to serial monitor
void loop()
{
  // Read sensor values (16 bit integers) when the LED state is on
  if (ledLite == 1){
    unsigned int red = RGB_sensor.readRed();
    unsigned int green = RGB_sensor.readGreen();
    unsigned int blue = RGB_sensor.readBlue();
  
    // Print out readings, change HEX to DEC if you prefer decimal output
    //Serial.print("Red: "); Serial.println(red,DEC);  //We don't want the red values as the fluoresence (also spelled wrong) we're measuring are green and blue
    Serial.print("Green: "); Serial.println(green,DEC);
    Serial.print("Blue: "); Serial.println(blue,DEC);
    Serial.println();
    delay(10); //We want a lot a values, but at a managable speed
  }

// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
//To crete a toggle switch, we only care when the button is pressed

  if (buttonState == HIGH){
    if (ledLite == 0){ //a simple variable to check if the light is on or off
      digitalWrite(ledPin, HIGH); //turns the LED on
      ledLite = 1; //now the LED is on and the variable reflects such
      delay(200);} //delay because otherwise the light would flip several times each button press
    else{
      digitalWrite(ledPin, LOW);//turns LED off
      ledLite = 0;}
      delay(200);
      //same as first if statement, but turns the light off if it is on. Completes the toggle functionality
    }
  }
  
