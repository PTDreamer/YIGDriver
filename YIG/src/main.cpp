#include <SPI.h>
#include "DAC8552.h"

// HW SPI
DAC8552 DAC;

void setup()
{
  //DAC = DAC8552(11, 7, 10);
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.println(DAC8552_LIB_VERSION);
  DAC.begin();
  Serial.println(F(" "));
  Serial.println(F("Press 's' to set DAC value"));
  Serial.println(F(" "));
}

uint8_t channel = 0;
int menuselect;
long currentVal = 0;
void loop()
{
  if (Serial.available()) 
  {
    menuselect = Serial.read(); //Reads a single letter
    if (menuselect == '+')
    {
      currentVal += 10;
      Serial.print("set to ");
      Serial.print(currentVal);
      Serial.print(" => ");
      Serial.println(0.01514 * currentVal - 2.063);
      Serial.print(" => ");
      Serial.println((0.01514 * currentVal - 2.063) / 0.057);
      DAC.setValue(channel, currentVal);
    }
    if (menuselect == '-')
    {
      currentVal -= 10;
      Serial.print("set to ");
      Serial.print(currentVal);
      Serial.print(" => ");
      Serial.println(0.01514 * currentVal - 2.063);
      Serial.print(" => ");
      Serial.println((0.01514 * currentVal - 2.063) / 0.057);
      DAC.setValue(channel, currentVal);
    }
  }
}
