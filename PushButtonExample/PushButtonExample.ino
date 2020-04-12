#include "Button.h"

#define PIN_BUTTON_1  2
#define PIN_BUTTON_2  3

Button* button1 = 0;
Button* button2 = 0;

void Method_1();
void Method_2();

void setup() {

  button1 = new Button(PIN_BUTTON_1, INPUT, Method_1);
  button2 = new Button(PIN_BUTTON_2, INPUT_PULLUP, Method_2);


  Serial.begin(115200, SERIAL_8N1);
  while(!Serial);

}

void loop() {

  button1->check();
  button2->check();
  //delay(10);

}

void Method_1()   {
  Serial.println(F(" Push Button 1"));
}

void Method_2()   {
  Serial.println(F(" Push Button 2 "));
}
