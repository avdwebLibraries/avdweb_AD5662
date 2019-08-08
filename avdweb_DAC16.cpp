/* 
AD5662 16 bit DAC for the Arduino

Copyright (C) 2012  Albert van Dalen http://www.avdweb.nl
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License at http://www.gnu.org/licenses .
Version 21-6-2013
*/

#if ARDUINO >= 100 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include "avdweb_DAC16.h"

DAC16::DAC16(byte SYNCpin, byte SCLKpin, byte DINpin):
SYNCpin(SYNCpin), SCLKpin(SCLKpin), DINpin(DINpin)
{ pinMode(SYNCpin, OUTPUT);
  pinMode(SCLKpin, OUTPUT);
  pinMode(DINpin, OUTPUT);
  digitalWrite(SCLKpin, HIGH);
}

void DAC16::write(unsigned dacValue)
{ digitalWrite(SYNCpin, HIGH);
  digitalWrite(SYNCpin, LOW);
  
  for(int i=23; i>=0; i--)
  { digitalWrite(DINpin, (dacValue >> i) & 1);
    digitalWrite(SCLKpin, LOW);
    digitalWrite(SCLKpin, HIGH);
  } 
}

