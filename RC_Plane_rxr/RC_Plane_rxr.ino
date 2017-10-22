//Transmitter
//visit www.rootsaid.com for full tutorial

#include <SoftwareSerial.h>
#include<Servo.h>         

Servo esc; 
SoftwareSerial hc12(2, 3); //RX, TX

int thr, ail, ele, rud;

void setup()
{
esc.attach(10);
pinMode (A0, INPUT);
pinMode (A1, INPUT);
pinMode (A6, INPUT);
pinMode (A7, INPUT);
pinMode (A2, INPUT);
pinMode (13, OUTPUT);
 
Serial.begin(9600);
hc12.begin(9600);
}

void loop()
{
  ele=map(analogRead(A0), 0, 1023, 0, 180);
  rud=map(analogRead(A1), 0, 1023, 0, 180);
  thr=map(analogRead(A7), 0, 1023, 0, 180);
  ail=map(analogRead(A5), 0, 1023, 0, 180);

  hc12.print(thr);
  hc12.print(",");
  hc12.print(ail);
  hc12.print(",");
  hc12.print(ele);
  hc12.print(",");
  hc12.print(rud);
  hc12.println("");
 
  Serial.print(thr);
  Serial.print(",");
  Serial.print(ail);
  Serial.print(",");
  Serial.print(ele);
  Serial.print(",");
  Serial.print(rud);
  Serial.println("");


delay(100);  
}



