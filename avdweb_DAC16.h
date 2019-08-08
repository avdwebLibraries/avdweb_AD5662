#ifndef DAC16_H
#define DAC16_H

class DAC16
{ 
public:
  DAC16(byte SYNCpin, byte SCLKpin, byte DINpin);
  void write(unsigned dacValue); 
  
private:
  byte SYNCpin, SCLKpin, DINpin;
};

#endif

