#if ARDUINO >= 100 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "avdweb_DAC16.h"

const byte SYNCpin = 2;
const byte SCLKpin = 3; 
const byte DINpin = 4;

DAC16 dac16(SYNCpin, SCLKpin, DINpin);

void setup(void) 
{ Serial.begin(9600);
  dac16.write(32767); // test first write 2.5V
  delay(3000);
  dac16.write(0);
}

void loop(void) 
{ for(unsigned i=0; i<65536; i+=1024) dac16.write(i); // create a sawtooth 
}

 
