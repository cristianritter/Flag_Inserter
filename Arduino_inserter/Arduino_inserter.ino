/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  Adicionalmente, a cada período de tempo, a informação da flag Flops é enviada pela porta serial.
 
  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

 
*/
#include <arduino-timer.h>

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

auto timer = timer_create_default(); // create a timer with default settings

bool send_flag(void *) {
  Serial.print("Flops\n"); 
  return true; // repeat? true
}

void setup() {
  // initialize serial:
  Serial.begin(4800);
  // reserve 500 bytes for the inputString:
  inputString.reserve(500);
  timer.every(30000, send_flag);
}

void loop() {
  timer.tick(); // tick the timer
  
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
