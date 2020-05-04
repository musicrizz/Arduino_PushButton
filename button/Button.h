/*
 * Button.h
 *
 *  Created on: Mar 3, 2020
 *      Author: musicrizz
 *     Copyright (C) 2020 Giovanni Grandinetti <grandinetti.giovanni13@gmail.com>
 *
 */
struct Button {
  private:
    short pin = -1;
    short mode = 0;
    byte  state;
    byte  lastState;
    byte  flag;
    void  (*pfunction)() = 0;
    unsigned long debounceDelay = 10;
    unsigned long lastDebounceTime = 0;

  public:
    Button(short p, short m, void (*function)())  {
      pin = p;
      mode = m;
      pfunction = function;
      if(mode == INPUT) {
        state     = LOW;
        lastState = LOW;
        flag      = LOW;
      }else{
        state     = HIGH;
        lastState = HIGH;
        flag      = HIGH;
      }
      debounceDelay = 10;
      lastDebounceTime = 0;
      pinMode(pin, m);
    }

    Button(const Button& b)  {
      pin       = b.pin;
      mode      = b.mode;
      state     = b.state;
      lastState = b.lastState;
      flag      = b.flag;
      pfunction = b.pfunction;
      debounceDelay    = b.debounceDelay;
      lastDebounceTime = b.lastDebounceTime;
    }

    bool check()  {
      if (pin < 0 || pfunction == 0)  {
        return false;
      }

      flag = digitalRead(pin);

      if (flag != lastState) {
        lastDebounceTime = millis();
      }

      if ((millis() - lastDebounceTime) > debounceDelay) {
        if (flag != state) {
          state = flag;

          if (mode == INPUT && state == HIGH) (*pfunction)();
          
          if (mode == INPUT_PULLUP && state == LOW) (*pfunction)();        
          
        }
      }

      lastState = flag;
      return true;
    }


    void getFunction()  {
      (*pfunction)();
    }

    void setDebounceDelay(unsigned long d)   {
      debounceDelay = d;
    }

};

